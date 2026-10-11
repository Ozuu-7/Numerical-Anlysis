#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d]: ", i);
    scanf("%lf", &x[i]);
    printf("y[%d]: ", i);
    scanf("%lf", &y[i]);
  }

  double xp;
  printf("\nEnter x to interpolate: ");
  scanf("%lf", &xp);

  double result = 0.0;

  printf("\n i\t x[i]\t\t y[i]\t\t L_i(x)\t\t Term (L_i * y_i)\n");
  for (int i = 0; i < n; i++) {
    double Li = 1.0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        Li *= (xp - x[j]) / (x[i] - x[j]);
      }
    }
    double term = Li * y[i];
    result += term;
    printf("%2d\t%.6f\t%.6f\t%.6f\t%.6f\n", i, x[i], y[i], Li, term);
  }

  printf("\nInterpolated value at x = %.4f is y = %.6f\n", xp, result);

  return 0;
}
