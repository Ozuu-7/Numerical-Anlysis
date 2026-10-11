#include <math.h>
#include <stdio.h>

#define MAX 10

int main() {
  int n;
  double a[MAX][MAX], b[MAX], x[MAX] = {0}, x_new[MAX], eps, tol;

  printf("Enter number of equations: ");
  scanf("%d", &n);

  printf("Enter augmented matrix [A|b] row by row:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
    scanf("%lf", &b[i]);
  }

  printf("Enter decimal places of accuracy (or tolerance): ");
  scanf("%lf", &tol);

  int k = (tol >= 1.0) ? (int)tol : (int)ceil(-log10(tol));
  eps = (tol >= 1.0) ? pow(10, -k) : tol;

  printf("\nIter\t");
  for (int i = 0; i < n; i++) {
    printf("x[%d]\t\t", i);
  }
  printf("\n");

  int iter = 0;
  while (iter < 100) {
    double max_diff = 0.0;

    for (int i = 0; i < n; i++) {
      double sum = b[i];
      for (int j = 0; j < n; j++) {
        if (j != i) {
          sum -= a[i][j] * x[j];
        }
      }
      x_new[i] = sum / a[i][i];
      double diff = fabs(x_new[i] - x[i]);
      if (diff > max_diff) {
        max_diff = diff;
      }
    }

    for (int i = 0; i < n; i++) {
      x[i] = x_new[i];
    }

    iter++;
    printf("%2d\t", iter);
    for (int i = 0; i < n; i++) {
      printf("%.6f\t", x[i]);
    }
    printf("\n");

    if (max_diff < eps) {
      break;
    }
  }

  printf("\nSolution after %d iterations:\n", iter);
  for (int i = 0; i < n; i++) {
    printf("x[%d] = %.6f\n", i, x[i]);
  }

  return 0;
}
