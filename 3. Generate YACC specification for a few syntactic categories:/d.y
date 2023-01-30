%
{
#include <stdio.h>
#include <stdlib.h>

    int yylex();
    void yyerror(char *s);

    %
}

% token NUMBER % token PLUS MINUS TIMES DIVIDE

    % start expression

    % union
{
    int value;
    struct ast *node;
}

    % type<node> expression term factor

    % nonassoc UMINUS

    % %

    expression : expression PLUS term
{
    $$ = new_ast('+', $1, $3);
}
| expression MINUS term
{
    $$ = new_ast('-', $1, $3);
}
| term
{
    $$ = $1;
};

term : term TIMES factor
{
    $$ = new_ast('*', $1, $3);
}
| term DIVIDE factor
{
    $$ = new_ast('/', $1, $3);
}
| factor
{
    $$ = $1;
};

factor :

    NUMBER
{
    $$ = new_num_ast($1);
}
| MINUS factor % prec UMINUS
{
    $$ = new_ast('-', new_num_ast(0), $2);
}
| '(' expression ')'
{
    $$ = $2;
};

% %

    struct ast
{
    char op;
    struct ast *left;
    struct ast *right;
};

struct ast *new_ast(char op, struct ast *left, struct ast *right)
{
    struct ast *node = (struct ast *)malloc(sizeof(struct ast));
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

struct ast *new_num_ast(int value)
{
    struct ast *node = (struct ast *)malloc(sizeof(struct ast));
    node->op = 0;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main()
{
    yyparse();
    return 0;
}
