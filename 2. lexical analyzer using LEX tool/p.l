// aim - Implementation of Lexical Analyzer using Lex Tool in C
% {
#include <stdio.h>
      % }

        % % [0 - 9] +
{
    printf("NUMBER\n");
}
[a - zA - Z] + { printf("IDENTIFIER\n"); }
[ \t\n] { /* ignore whitespaces */ }
    . { printf("UNKNOWN\n"); }

% %

    int main(int argc, char *argv[])
{
    yylex();
    return 0;
}
/* Here is the explanation for the code above:
1. % { ... % } is used to define the C code that will be used by the flex program. This is used to include the header files, define the global variables and define the functions that will be used by the program.
2. % % [0 - 9] + is used to define the regular expression that will be matched by the flex program. If the input string matches with the regular expression, then the code inside the braces will be executed. In the above code, [0 - 9] + is the regular expression that matches any number. If the input string matches with the regular expression, then the code inside the braces will be executed. If the input string matches with the regular expression, then the code inside the braces will be executed. If the input string matches with the regular expression, then the code inside the braces will be executed.
3. % % [a - zA - Z] + is used to define the regular expression that will be matched by the flex program. If the input string matches with the regular expression, then the code inside the braces will be executed. In the above code, [a - zA - Z] + is the regular expression that matches any identifier. If the input string matches with the regular expression, then the code inside the braces will be executed.
4. % % [ \t\n] is used to define the regular expression that will be matched by the flex program. If the input string matches with the regular expression, then the code inside the braces will be executed. In the above code, [ \t

] is the regular expression that matches any whitespaces. If the input string matches with the regular expression, then the code inside the braces will be executed.
5. % % . is used to define the regular expression that will be matched by the flex program. If the input string matches with the regular expression, then the code inside the braces will be executed. In the above code, . is the regular expression that matches any other character. If the input string matches with the regular expression, then the code inside the braces will be executed.
6. % % is used to define the C code that will be used by the flex program. This is used to define the main function. The main function will be called when the program is executed. The main function will call the yylex() function. The yylex() function will be used to match the input string with the defined regular expressions.
7. int main(int argc, char *argv[]) is the main function. This function will be called when the program is executed. The main function will call the yylex() function. The yylex() function will be used to match the input string with the defined regular expressions.
8. yylex() is the function that will be used to match the input string with the defined regular expressions. The yylex() function will be called from the main function.
9. return 0; is used to return the value 0 from the main function. */