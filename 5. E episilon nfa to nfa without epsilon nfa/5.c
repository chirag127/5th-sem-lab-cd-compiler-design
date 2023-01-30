#include <stdio.h>
#include <stdlib.h>
struct node
{
    int st;
    struct node *link;
};

void fc(int, int);
void it(int, char, int);
int fa(char);
void ffs(void);
void uc(int);
void pec(int);
static int set[20], ns, na, s, nt, nf, start, fs[20], c, r, b[20];
char alphabet[20];
static int e_closure[20][20] = {0};
struct node *transition[20][20] = {NULL};
void main()
{
    int i, j, k, m, t, n;

    struct node *temp;
    printf("enter the number of alphabets?\n");
    scanf("%d", &na);
    getchar();
    printf("\nEnter alphabets?\n");
    for (i = 0; i < na; i++)
    {

        alphabet[i] = getchar();
        getchar();
    }
    printf("Enter the number of states?\n");
    scanf("%d", &ns);
    printf("Enter the start state?\n");
    scanf("%d", &start);
    printf("Enter the number of final states?\n");
    scanf("%d", &nf);
    printf("Enter the final states?\n");
    for (i = 0; i < nf; i++)
        scanf("%d", &fs[i]);
    printf("Enter no of transition?\n");
    scanf("%d", &nt);
    printf("\nEnter transition?\n");
    for (i = 0; i < nt; i++)
    {

        scanf("%d %c%d", &r, &c, &s);
        it(r, c, s);
    }

    printf("\n");

    for (i = 1; i <= ns; i++)
    {
        c = 0;
        for (j = 0; j < 20; j++)

        {
            b[j] = 0;
            e_closure[i][j] = 0;
        }
        fc(i, i);
    }
    printf("Equivalent NFA without epsilon\n");
    printf("start state:");
    pec(start);
    printf("\nAlphabets:");
    for (i = 0; i < na; i++)
        printf("%c ", alphabet[i]);
    printf("\n States :");
    for (i = 1; i <= ns; i++)
        pec(i);

    printf("\nTnransitions are...:\n");

    for (i = 1; i <= ns; i++)
    {

        for (j = 0; j < na - 1; j++)
        {
            for (m = 1; m <= ns; m++)
                set[m] = 0;
            for (k = 0; e_closure[i][k] != 0; k++)
            {

                t = e_closure[i][k];
                temp = transition[t][j];
                while (temp != NULL)
                {

                    uc(temp->st);
                    temp = temp->link;
                }
            }
            printf("\n");
            pec(i);
            printf("%c\t", alphabet[j]);
            printf("{");
            for (n = 1; n <= ns; n++)
            {
                if (set[n] != 0)
                    printf("q%d,", n);
            }
            printf("}");
        }
    }
    printf("\n Final states:");
    ffs();
}

void fc(int x, int sta)
{
    struct node *temp;
    int i;
    if (b[x])
        return;
    e_closure[sta][c++] = x;
    b[x] = 1;
    if (alphabet[na - 1] == 'e' && transition[x][na - 1] != NULL)
    {
        temp = transition[x][na - 1];
        while (temp != NULL)
        {
            fc(temp->st, sta);
            temp = temp->link;
        }
    }
}

void it(int r, char c, int s)
{
    int j;
    struct node *temp;
    j = fa(c);
    if (j == 999)
    {
        printf("error\n");
        exit(0);
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->st = s;
    temp->link = transition[r][j];
    transition[r][j] = temp;
}

int fa(char c)
{
    int i;
    for (i = 0; i < na; i++)
        if (alphabet[i] == c)
            return i;

    return (999);
}

void uc(int i)
{
    int j = 0, k;
    while (e_closure[i][j] != 0)
    {
        k = e_closure[i][j];
        set[k] = 1;
        j++;
    }
}
void ffs()
{
    int i, j, k, t;
    for (i = 0; i < nf; i++)
    {
        for (j = 1; j <= ns; j++)
        {
            for (k = 0; e_closure[j][k] != 0; k++)
            {
                if (e_closure[j][k] == fs[i])
                {

                    pec(j);
                }
            }
        }
    }
}

void pec(int i)
{
    int j;
    printf("{");
    for (j = 0; e_closure[i][j] != 0; j++)
        printf("q%d,", e_closure[i][j]);
    printf("}\t");
}

// https://3.bp.blogspot.com/-t3w2DH0PjE4/W6n_PZUzr3I/AAAAAAAAF24/GY2aLuE53Rc30MfqD2hYUEL5brWACv8sgCLcBGAs/s640/nfa852914951.jpg