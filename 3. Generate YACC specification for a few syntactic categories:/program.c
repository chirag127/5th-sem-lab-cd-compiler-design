// Aim: Generate YACC specification for a few syntactic categories:
// a) Program to recognize a valid arithmetic expression that uses operator +, – , * and /.
// b) Program to recognize a valid variable which starts with a letter followed by any number of letters or digits.
// c) Implementation of Calculator using LEX and YACC
// d) Convert the BNF rules into YACC form and write code to generate abstract syntax tree

%{
#include <stdio.h>