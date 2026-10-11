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

  printf("Enter number of subintervals n (even for Simpson's): ");
  scanf("%d", &n);

  double h = (b - a) / n;

  printf("\n i\t x\t\t f(x)\n");
  for (int i = 0; i <= n; i++) {
    printf("%2d\t%.6f\t%.6f\n", i, a + i * h, f(a + i * h));
  }

  double It = f(a) + f(b);
  for (int i = 1; i < n; i++) {
    It += 2 * f(a + i * h);
  }
  It *= h / 2.0;
  printf("\nTrapezoidal rule (I_t) = %.6f\n", It);

  if (n % 2 != 0) {
    printf("Simpson's rule requires even n, skipped.\n");
  } else {
    double Is = f(a) + f(b);
    for (int i = 1; i < n; i++) {
      if (i % 2 == 1) {
        Is += 4 * f(a + i * h);
      } else {
        Is += 2 * f(a + i * h);
      }
    }
    Is *= h / 3.0;
    printf("Simpson's 1/3 rule (I_s) = %.6f\n", Is);
  }

  return 0;
}
