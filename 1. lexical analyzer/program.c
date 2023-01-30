// 1.Design and implement a lexical analyzer for given language using C and the lexical analyzer should ignore redundant spaces, tabs and new lines.
#include <string.h>
#include <ctype.h>
#include <stdio.h>
        void
        main()
{
    FILE *f1;
    char c, str[10];
    int lineno = 1, num = 0, i = 0, j = 0;
    // clrscr();
    printf("\nEnter the c program\n");

    f1 = fopen("input.txt", "w");
    while ((c = getchar()) != 36)
    {
        putc(c, f1);
    }
    fclose(f1);

    f1 = fopen("input.txt", "r");
    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            num = c - 48;
            c = getc(f1);
            while (isdigit(c))
            {
                num = num * 10 + (c - 48);
                c = getc(f1);
            }
            printf("%d is a number \n", num);
            ungetc(c, f1);
        }
        else if (isalpha(c) || c == 95)
        {
            str[i++] = c;
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == 95 || c == 36)
            {
                str[i++] = c;
                c = getc(f1);
            }
            str[i++] = '\0';
            if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0) // TYPE 32 KEYWORDS
                printf("%s is a keyword\n", str);
            else
                printf("%s is a identifier\n", str);
            ungetc(c, f1);
            i = 0;
        }
        else if (c == ' ' || c == '\t')
        {
            printf("\n");
            j = j - 1;
        }
        else if (c == '\n')
        {
            lineno++;
            j = j - 1;
        }
        else
        { // TO FIND SPECIAL SYMBOL
            printf("%c is a special symbol\n", c);
        }

        j = j + 1;
    }

    printf("Total no. of lines are: %d\n", lineno);
    printf("The total number of token is %d\n", j);
    fclose(f1);
    // getch();
}

/* Here is the explanation for the code above:
1. The program starts by defining the header files and the main function.
2. Then the program asks for the input from the user.
3. The program then takes the input and stores it in a file name input.txt.
4. The program then opens the file input.txt and reads the input from the file.
5. The program then checks for the character from the file and then checks whether it is a digit or an alphabet or a special symbol.
6. The program then prints the appropriate output according to the character.
7. The program then prints the total number of lines and the total number of tokens. */
