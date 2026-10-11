#include <math.h>
#include <stdio.h>

#define MAX 10

int main() {
  int n;
  double a[MAX][MAX + 1], x[MAX];

  printf("Enter number of equations: ");
  scanf("%d", &n);

  printf("Enter augmented matrix [A|b] row by row:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    int max_row = i;
    for (int k = i + 1; k < n; k++) {
      if (fabs(a[k][i]) > fabs(a[max_row][i])) {
        max_row = k;
      }
    }
    for (int j = 0; j <= n; j++) {
      double temp = a[i][j];
      a[i][j] = a[max_row][j];
      a[max_row][j] = temp;
    }

    if (fabs(a[i][i]) < 1e-12) {
      printf("No unique solution exists.\n");
      return 1;
    }

    for (int k = i + 1; k < n; k++) {
      double factor = a[k][i] / a[i][i];
      for (int j = i; j <= n; j++) {
        a[k][j] -= factor * a[i][j];
      }
    }
  }

  printf("\nUpper Triangular Matrix [A|b]:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      printf("%10.4f", a[i][j]);
    }
    printf("\n");
  }

  for (int i = n - 1; i >= 0; i--) {
    double sum = a[i][n];
    for (int j = i + 1; j < n; j++) {
      sum -= a[i][j] * x[j];
    }
    x[i] = sum / a[i][i];
  }

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++) {
    printf("x[%d] = %.6f\n", i, x[i]);
  }

  return 0;
}
