//  8. Develop an operator precedence parser for a given language.

#include <stdio.h>
#include <stdlib.h>

int Operator_Position_Finder(char);

#define node struct Basic_tree

int T4Tutorials[5][5] = {
    {1, 0, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 2, 3},
    {1, 1, 3, 1, 1},
    {0, 0, 0, 3, 2}};
int tos = -1;
void T4Tutorials_value(void);
// node create_node(char,*node);void DisplayTree( node *);
int isOperator(char);

struct Basic_tree
{
    char data;
    node *lptr;
    node *rptr;
} * first;

struct opr
{
    char op_name;
    node *t;
} oprate[50];

char current_operators[5] = {'+', '*', '(', ')', '['};
char OperatorsInStack[5] = {'+', '*', '(', ')', ']'};

void main()
{
    char exp[10];

    int myVariable = 0, row = 0, col = 0;
    node *temp;
    //    clrscr();

    printf("Enter Exp : ");
    scanf("%s", exp);

    T4Tutorials_value();
    while (exp[myVariable] != '\0')
    {
        if (myVariable == 0)
        {
            tos++;
            oprate[tos].op_name = exp[tos];
        }
        else
        {
            if (isOperator(exp[myVariable]) == -1)
            {
                oprate[tos].t = (node *)malloc(sizeof(node));
                oprate[tos].t->data = exp[myVariable];
                oprate[tos].t->lptr = '\0';
                oprate[tos].t->rptr = '\0';
            }
            else
            {
                row = Operator_Position_Finder(oprate[tos].op_name);
                col = Operator_Position_Finder(exp[myVariable]);
                if (T4Tutorials[row][col] == 0)
                {
                    tos++;
                    oprate[tos].op_name = exp[myVariable];
                }
                else if(T4Tutorials[row][col] == 1){

                    temp = (node *)malloc(sizeof(node));
                    temp->data = oprate[tos].op_name;

                    temp->lptr = (oprate[tos - 1].t);
                    temp->rptr = (oprate[tos].t);
                    tos--;

                    oprate[tos].t = temp;

                    myVariable--;
                }
                else if(T4Tutorials[row][col] == 2)
                {
                    // temp = (node*) malloc (sizeof(node));
                    temp = oprate[tos].t;
                    tos--;
                    oprate[tos].t = temp;
                }
                else if(T4Tutorials[row][col] == 3)
                {
                    printf("\nExpression is Invalid...\n");
                    printf("%c  %c can not occur simultaneously\n", oprate[tos].op_name, exp[myVariable]);
                    break;
                }
            }
        }

        myVariable++;
    }
    printf("show tree \n\n\n");
    DisplayTree(oprate[tos].t);
    printf("Over");
    // getch();
    // getch();
}

int isOperator(char c)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (c == current_operators[i] || c == OperatorsInStack[i])
            break;
    }

    if (i == 5)
        return (-1);
    else return i;
}

int Operator_Position_Finder(char c)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (c == current_operators[i] || c == OperatorsInStack[i])
            break;
    }
    return i;
}

void DisplayTree(node *start)
{
    if (start->lptr != NULL)
        DisplayTree(start->lptr);

    if (start->rptr != NULL)
        DisplayTree(start->rptr);

    printf("%c \n", start->data);
}

void T4Tutorials_value(void)
{
    int i, j;
    printf("OPERATOR PRECEDENCE Matrix\n");
    printf("===========================\n   ");

    for (i = 0; i < 5; i++)
    {
        printf("%c ", OperatorsInStack[i]);
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("%c  ", current_operators[i]);
        for (j = 0; j < 5; j++)
        {
            if (T4Tutorials[i][j] == 0)
                printf("< ");
            else if(T4Tutorials[i][j] == 1)
                printf("> ");
            else if(T4Tutorials[i][j] == 2)
                printf("= ");
            else if(T4Tutorials[i][j] == 3)
                printf("  ");
        }
        printf("\n");
    }
}

// https://t4tutorials.com/c-program-to-parse-a-string-using-operator-precedence-parsing/