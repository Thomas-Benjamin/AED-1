#include <stdio.h>

#include <stdlib.h>

char percorre(char conteudo, char ** mat, int i, int j, int p, int t1, int t2);

int main() {
  int x, y, i, j;
  char ** mat, resultado;

  scanf("%d", & x);
  scanf("%d", & y);

  mat = malloc(y * sizeof(char * ));

  for (i = 0; i < y; i++) {
    mat[i] = malloc(x * sizeof(char));
  }

  for (i = 0; i < y; i++) {
    scanf("%s", mat[i]);
  }

  resultado = percorre(mat[0][0], mat, 0, 0, 0, x, y);

  if (resultado == '*') {
    printf("*\n");
  } else if (resultado == '!') {
    printf("!\n");
  }
  return 0;
}

char percorre(char conteudo, char ** mat, int i, int j, int p, int t1, int t2) {

  if (j >= 0 && j < t1) {
    if (i >= 0 && i < t2) {
      if (conteudo == '*') {
        return '*';
      } else if (conteudo == '>') {
        mat[i][j] = '!';
        j++;
        conteudo = mat[i][j];
        p = 1;
        return percorre(conteudo, mat, i, j, p, t1, t2);
      } else if (conteudo == '<') {
        mat[i][j] = '!';
        j--;
        conteudo = mat[i][j];
        p = 2;
        return percorre(conteudo, mat, i, j, p, t1, t2);
      } else if (conteudo == '^') {
        mat[i][j] = '!';
        i--;
        conteudo = mat[i][j];
        p = 3;
        return percorre(conteudo, mat, i, j, p, t1, t2);
      } else if (conteudo == 'v') {
        mat[i][j] = '!';
        i++;
        conteudo = mat[i][j];
        p = 4;
        return percorre(conteudo, mat, i, j, p, t1, t2);
      } else if (conteudo == '.') {
        if (p == 1) {
          mat[i][j] = '!';
          j++;
          conteudo = mat[i][j];
          return percorre(conteudo, mat, i, j, p, t1, t2);
        }
        if (p == 2) {
          mat[i][j] = '!';
          j--;
          conteudo = mat[i][j];
          return percorre(conteudo, mat, i, j, p, t1, t2);
        }
        if (p == 3) {
          mat[i][j] = '!';
          i--;
          conteudo = mat[i][j];
          return percorre(conteudo, mat, i, j, p, t1, t2);
        }
        if (p == 4) {
          mat[i][j] = '!';
          i++;
          conteudo = mat[i][j];
          return percorre(conteudo, mat, i, j, p, t1, t2);
        }
      } else if (conteudo == '!') {
        return '!';
      }
    } else {
      return '!';
    }
  } else {
    return '!';
  }
}