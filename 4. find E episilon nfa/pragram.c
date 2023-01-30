// Write program to find ε – closure of all states of any given NFA with ε transition
#include <stdio.h>

#include <string.h>

char result[20][20], copy[3], states[20][20];

void add_state(char a[3], int i)
{
    strcpy(result[i], a);
}

void display(int n)
{
    int k = 0;
    printf("\n\n\n Epsilon closure of %s = { ", copy);
    while (k < n)
    {
        printf(" %s", result[k]);
        k++;
    }
    printf(" } \n\n\n");
}

int main()
{
    FILE *INPUT;
    INPUT = fopen("input.dat", "r");
    char state[3];
    int end, i = 0, n, k = 0;
    char state1[3], input[3], state2[3];
    printf("\n Enter the no of states: ");
    scanf("%d", &n);
    printf("\n Enter the states \n");
    for (k = 0; k < 3; k++)
    {
        scanf("%s", states[k]);
    }

    for (k = 0; k < n; k++)
    {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++);
        while (1)
        {
            end = fscanf(INPUT, "%s%s%s", state1, input, state2);
            if (end == EOF)
            {
                break;
            }

            if (strcmp(state, state1) == 0)
            {
                if (strcmp(input, "e") == 0)
                {
                    add_state(state2, i++);
                    strcpy(state, state2);
                }
            }
        }
        display(i);
        rewind(INPUT);
    }
    /* Here is the explanation for the code above:
    1. The function add_state() adds the states to the array.
    2. The function display() displays the states in the array.
    3. The variable end is used to know when the file ends.
    4. The variable i is used to store the number of states that are added in the array.
    5. The variable k is used to store the number of lines in the file.
    6. The variable n is used to store the number of states that are read from the file.
    7. The variable state is used to store the current state.
    8. The variable state1 and state2 are used to store the states read from the file.
    9. The variable copy is used to store a copy of the state.
    10. The variable input is used to store the input read from the file.
    11. The file pointer INPUT is used to read from the file.
    12. The function strcmp() is used to compare the states.
    13. The function strcpy() is used to copy the states.
    14. The function rewind() is used to go back to the beginning of the file. */

    return 0;
}

/* Here is the explanation for the code above:
1. First we have to take input from the file.
2. Then we need to read the input from the file.
3. We need to store the states in a 2D array.
4. Then we need to check the states.
5. If the state is present in the 2D array, then we need to add it to the new 2D array.
6. Then we need to print the new 2D array.
7. Finally we need to close the file. */

/* Here is the explanation for the code above:
1. Declare a function add_state() to add the states in the array result[].
2. Declare a function display() to display the states in the array result[].
3. Declare a function main().
4. Declare an array result[] to store the result.
5. Declare a variable end to store the return value of fscanf().
6. Declare a variable i to store the index of the array result[].
7. Declare a variable n to store the number of states.
8. Declare a variable k to store the index of the array states[].
9. Declare an array states[] to store all the states.
10. Declare a variable state[] to store the current state.
11. Declare a variable state1[] to store the first state of the transition.
12. Declare a variable input[] to store the input symbol.
13. Declare a variable state2[] to store the second state of the transition.
14. Declare a variable copy[] to store the copy of the current state.
15. Declare a variable INPUT to store the pointer to the file input.dat.
16. Open the file input.dat in read mode.
17. Read the number of states from the user.
18. Read the states from the user.
19. Declare a loop to iterate over each state.
20. Declare a loop to iterate over the transitions of the current state.
21. Add the current state to the array result[].
22. Check if the input symbol is e.
23. Add the second state of the transition to the array result[].
24. Copy the second state of the transition to the current state.
25. Display the states in the array result[].
26. Close the file input.dat. */