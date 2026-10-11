#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

double f(double x) { return sqrt(sin(x) + cos(x)); }

int main() {
  int n, mode;
  double a, b;

  printf("Enter limits as (1) real numbers or (2) degrees: ");
  scanf("%d", &mode);
  printf("Enter lower limit a: ");
  scanf("%lf", &a);
  printf("Enter upper limit b: ");
  scanf("%lf", &b);

  if (mode == 2) {
    a = a * M_PI / 180.0;
    b = b * M_PI / 180.0;
  }

  printf("Enter number of subintervals n (must be multiple of 6): ");
  scanf("%d", &n);

  if (n % 6 != 0) {
    printf("n must be a multiple of 6.\n");
    return 1;
  }

  double h = (b - a) / n;

  printf("\n i\t x\t\t f(x)\n");
  for (int i = 0; i <= n; i++) {
    printf("%2d\t%.6f\t%.6f\n", i, a + i * h, f(a + i * h));
  }

  double result = 0;
  int groups = n / 6;
  for (int g = 0; g < groups; g++) {
    double x0 = a + g * 6 * h;
    result += f(x0) + 5 * f(x0 + h) + f(x0 + 2 * h) + 6 * f(x0 + 3 * h) +
              f(x0 + 4 * h) + 5 * f(x0 + 5 * h) + f(x0 + 6 * h);
  }
  result *= 3.0 * h / 10.0;

  printf("\nWeddle's rule result = %.6f\n", result);

  return 0;
}
