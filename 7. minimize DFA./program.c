
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **transitionMap;
int **ptm;
int ss;
long int r;
long int as;
long int fs;
long int nonfs;
long int *P;
void dfs(int v) {
  r |= (1 << v);

  for (int i = 0; i < 26; i++)
    if ((transitionMap[v][i] != -1) &&
        ((r & (1 << transitionMap[v][i])) == 0)) {
      dfs(transitionMap[v][i]);
    }
}
int main() {
  fs = 0;
  as = 0;

  transitionMap = (int **)malloc(64 * sizeof(int *));
  for (int i = 0; i < 64; i++) {
    transitionMap[i] = (int *)malloc(26 * sizeof(int));
    for (int j = 0; j < 26; j++) {
      transitionMap[i][j] = -1;
    }
  }
  ptm = (int **)malloc(64 * sizeof(int *));
  for (int i = 0; i < 64; i++) {
    ptm[i] = (int *)malloc(26 * sizeof(int));
    for (int j = 0; j < 26; j++) {
      ptm[i][j] = -1;
    }
  }

  char buff[125];
  fgets(buff, sizeof(buff), stdin);
  char *p = strtok(buff, " ");
  ss = atoi(p);

  fgets(buff, sizeof(buff), stdin);
  p = strtok(buff, " ");
  while (p != NULL) {
    int state = atoi(p);
    fs |= 1 << (state);
    p = strtok(NULL, " ");
  }

  int from;
  char symbol;
  int to;
  while (fscanf(stdin, "%d %c %d", &from, &symbol, &to) != EOF) {
    transitionMap[from][symbol - 'a'] = to;

    llStates |= (1 << from);
    as |= (1 << to);
  }

  r = 0;
  dfs(ss);

  as &= r;
  fs &= r;

  P = (long int *)malloc(64 * sizeof(long int));
  for (int i = 0; i < 64; i++) {
    P[i] = 0;
  }

  nonfs = as & ~fs;
  P[0] = fs;
  P[1] = nonfs;
  int npi = 2;

   for (int i = 0; i < 64; i++) {

     long int np = 0;

    if (P[i] == 0) {
      break;
    }
    /* Try to find leftmost bit in the bitset. This loop will only run to its
entirety once when that bit is found*/
    for (int j = 63; j >= 0; j--) {

      long int sts = (long int)1 << j;

      if ((P[i] & (sts)) != 0) {

	
	ptm[i] = transitionMap[j];

 for (int k = j - 1; k >= 0; k--) {

  long int os = (long int)1 << k;

  if ((P[i] & (os)) != 0) {
    /* Iterate across the entire alphabet and check if sts and os can transition
to Different*/
    for (int l = 0; l < 26; l++) {

      int sn = -1;
      int on = -1;
      for (int m = 0; m < npi; m++) {
        if ((P[m] & (1 << transitionMap[j][l])) != 0) {
          sn = m;
        }
        if ((P[m] & (1 << transitionMap[k][l])) != 0) {
          on = m;
        }
      }

     if (transitionMap[j][l] != transitionMap[k][l] &&
                                   (sn != on)) {
        P[i] &= ~(1 << k);
        np |= (1 << k);
        break;
      }
    }
  }
}
break;
      }
    }

    if (np != 0) {
      P[npi] = np;
      npi++;
    }
  }

  int sp = 0;
  for (int i = 0; i < npi; i++) {
    if ((P[i] & (1 << ss)) != 0) {
      sp = i;
      break;
    }
  }
  printf("%d \n", sp);

  for (int i = 0; i < npi; i++) {
    if ((P[i] & fs) != 0) {
      printf("%d ", i);
    }
  }
  printf("\n");

  for (int i = 0; i < npi; i++) {
    for (int j = 0; j < 26; j++) {
      if (ptm[i][j] != -1) {
        for (int k = 0; k < npi; k++) {
          if ((P[k] & (1 << ptm[i][j])) != 0) {
            printf("%d %c %d\n", i, j + 'a', k);
          }
        }
      }
    }
  }
  return 0;
}
