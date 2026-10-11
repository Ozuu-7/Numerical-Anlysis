#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d], y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  double yp;
  printf("\nEnter y value to find corresponding x: ");
  scanf("%lf", &yp);

  double result = 0.0;

  printf("\n i\t y[i]\t\t x[i]\t\t L_i(y)\t\t Term (L_i * x_i)\n");
  for (int i = 0; i < n; i++) {
    double Li = 1.0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        Li *= (yp - y[j]) / (y[i] - y[j]);
      }
    }
    double term = Li * x[i];
    result += term;
    printf("%2d\t%.6f\t%.6f\t%.6f\t%.6f\n", i, y[i], x[i], Li, term);
  }

  printf("\nFor y = %.6f, the interpolated x = %.6f\n", yp, result);

  return 0;
}
