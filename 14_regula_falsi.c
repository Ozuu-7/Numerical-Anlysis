#include <math.h>
#include <stdio.h>

double f(double x) { return exp(x) + log(1 + x) / log(3) - 2.2; }

int main() {
  double a, b, x, y, y1, y2, eps, tol;
  int n = 0;

  printf("Enter interval [a, b]: ");
  scanf("%lf %lf", &a, &b);
  printf("Enter decimal places of accuracy (or tolerance): ");
  scanf("%lf", &tol);

  int k = (tol >= 1.0) ? (int)tol : (int)ceil(-log10(tol));
  eps = (tol >= 1.0) ? pow(10, -k) : tol;

  y1 = f(a);
  y2 = f(b);

  if (y1 * y2 > 0) {
    printf("f(a) and f(b) must have opposite signs.\n");
    return 1;
  }

  printf("\n n\t a\t\t b\t\t x\t\t f(x)\n");

  do {
    x = a - y1 * (b - a) / (y2 - y1);
    y = f(x);
    printf("%2d\t%.6f\t%.6f\t%.6f\t%.6f\n", n, a, b, x, y);

    if (y * y1 < 0) {
      b = x;
      y2 = y;
    } else {
      a = x;
      y1 = y;
    }
    n++;
  } while (fabs(y) > eps);

  printf("\nRoot = %.6f (correct to %d decimal places)\n", x, k);

  return 0;
}
