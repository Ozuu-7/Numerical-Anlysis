#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX], dd[MAX][MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d], y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  for (int i = 0; i < n; i++) {
    dd[i][0] = y[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
    }
  }

  printf("\nDivided Difference Table:\n\n");
  printf("%-10s", "x");
  for (int j = 0; j < n; j++) {
    printf("Order %-6d", j);
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("%-10.4f", x[i]);
    for (int j = 0; j < n - i; j++) {
      printf("%-12.6f", dd[i][j]);
    }
    printf("\n");
  }

  double xp;
  printf("\nEnter x to interpolate: ");
  scanf("%lf", &xp);

  double result = dd[0][0];
  double product = 1.0;

  for (int i = 1; i < n; i++) {
    product *= (xp - x[i - 1]);
    result += dd[0][i] * product;
  }

  printf("\nInterpolated value at x = %.4f is y = %.6f\n", xp, result);

  return 0;
}
