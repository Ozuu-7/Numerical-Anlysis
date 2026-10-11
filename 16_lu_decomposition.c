#include <stdio.h>

#define MAX 10

int main() {
  int n;
  double a[MAX][MAX], b[MAX], x[MAX], y[MAX];
  double L[MAX][MAX] = {0}, U[MAX][MAX] = {0};

  printf("Enter number of equations: ");
  scanf("%d", &n);

  printf("Enter augmented matrix [A|b] row by row:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
    scanf("%lf", &b[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      double sum = 0;
      for (int k = 0; k < i; k++) {
        sum += L[i][k] * U[k][j];
      }
      U[i][j] = a[i][j] - sum;
    }
    for (int j = i; j < n; j++) {
      if (i == j) {
        L[i][i] = 1;
      } else {
        double sum = 0;
        for (int k = 0; k < i; k++) {
          sum += L[j][k] * U[k][i];
        }
        L[j][i] = (a[j][i] - sum) / U[i][i];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < i; j++) {
      sum += L[i][j] * y[j];
    }
    y[i] = b[i] - sum;
  }

  for (int i = n - 1; i >= 0; i--) {
    double sum = 0;
    for (int j = i + 1; j < n; j++) {
      sum += U[i][j] * x[j];
    }
    x[i] = (y[i] - sum) / U[i][i];
  }

  printf("\nLower Triangular Matrix L:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%10.4f", L[i][j]);
    }
    printf("\n");
  }

  printf("\nUpper Triangular Matrix U:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%10.4f", U[i][j]);
    }
    printf("\n");
  }

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++) {
    printf("x[%d] = %.6f\n", i, x[i]);
  }

  return 0;
}
