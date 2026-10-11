#include <math.h>
#include <stdio.h>

double f(double x) { return exp(x) + log(1 + x) / log(3) - 2.2; }

int main() {
  double a, b, x, y1, y2, d;
  int n;

  printf("Enter interval [a, b]: ");
  scanf("%lf %lf", &a, &b);
  printf("Enter number of refinements: ");
  scanf("%d", &n);

  d = b - a;
  y1 = f(a);

  printf("\n Ref\t a\t\t b\t\t f(a)\t\t f(b)\n");
  for (int i = 1; i <= n; i++) {
    d = d / 10.0;
    for (int j = 1; j <= 10; j++) {
      x = a + d;
      y2 = f(x);
      if (y1 * y2 < 0) {
        b = x;
        break;
      } else {
        a = x;
        y1 = y2;
      }
    }
    printf("%2d\t%.6f\t%.6f\t%.6f\t%.6f\n", i, a, b, f(a), f(b));
  }

  if (fabs(y1) < fabs(f(b))) {
    printf("\nRoot = %.6f (correct to %d decimal places)\n", a, n);
  } else {
    printf("\nRoot = %.6f (correct to %d decimal places)\n", a + d, n);
  }

  return 0;
}
