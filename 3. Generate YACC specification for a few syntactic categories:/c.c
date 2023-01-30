%
{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

    int yylex();
    void yyerror(char *s);

    %
}

% token NUMBER % token PLUS MINUS TIMES DIVIDE

        % %

        expression : expression PLUS term |
    expression MINUS term | term;

term : term TIMES factor | term DIVIDE factor | factor;

factor : NUMBER | '(' expression ')';

% %

    int yylex()
{
    int c;
    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return NUMBER;
    }
    if (c == '+')
        return PLUS;
    if (c == '-')
        return MINUS;
    if (c == '*')
        return TIMES;
    if (c == '/')
        return DIVIDE;
    if (c == '\n')
        return 0;
    return c;
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
