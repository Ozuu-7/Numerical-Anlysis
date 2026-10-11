#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX], diff[MAX][MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d]: ", i);
    scanf("%lf", &x[i]);
    printf("y[%d]: ", i);
    scanf("%lf", &y[i]);
  }

  double h = x[1] - x[0];

  for (int i = 0; i < n; i++) {
    diff[i][0] = y[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = j; i < n; i++) {
      diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
    }
  }

  printf("\nBackward Difference Table:\n\n");

  for (int i = 0; i < n; i++) {
    printf("%-10.4f", x[i]);
    for (int j = 0; j <= i; j++) {
      printf("%-12.4f", diff[i][j]);
    }
    printf("\n");
  }

  double xp;
  printf("\nEnter x to interpolate: ");
  scanf("%lf", &xp);

  double u = (xp - x[n - 1]) / h;
  double result = diff[n - 1][0];
  double u_term = 1.0;

  for (int i = 1; i < n; i++) {
    u_term *= (u + (i - 1)) / i;
    result += u_term * diff[n - 1][i];
  }

  printf("\nInterpolated value at x = %.4f is y = %.6f\n", xp, result);

  return 0;
}
