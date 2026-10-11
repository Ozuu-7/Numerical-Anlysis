#include <math.h>
#include <stdio.h>

double f(double x) { return sqrt(sin(x) + cos(x)); }

int main() {
  double a, b;
  int n;

  printf("Enter lower limit a: ");
  scanf("%lf", &a);
  printf("Enter upper limit b: ");
  scanf("%lf", &b);
  printf("Enter number of subintervals n: ");
  scanf("%d", &n);

  double h = (b - a) / n;
  double sum = 0.0;

  printf("\n i\t Midpoint x\t f(x)\n");
  for (int i = 0; i < n; i++) {
    double x = a + h * (i + 0.5);
    double fx = f(x);
    sum += fx;
    printf("%2d\t%.6f\t%.6f\n", i + 1, x, fx);
  }

  double result = sum * h;
  printf("\nIntegral value = %.6f\n", result);

  return 0;
}
