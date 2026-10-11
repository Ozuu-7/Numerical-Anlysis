#include <math.h>
#include <stdio.h>

double f(double x) { return exp(x) + log(1 + x) / log(3) - 2.2; }

double g(double x) { return log(2.2 - log(1 + x) / log(3)); }

int main() {
  double x, x1, eps, tol;
  int n = 0;

  printf("Enter initial guess: ");
  scanf("%lf", &x);
  printf("Enter decimal places of accuracy (or tolerance): ");
  scanf("%lf", &tol);

  int k = (tol >= 1.0) ? (int)tol : (int)ceil(-log10(tol));
  eps = (tol >= 1.0) ? pow(10, -k) : tol;

  printf("\n n\t x_n\t\t g(x_n)\t\t |x_(n+1) - x_n|\n");

  do {
    x1 = g(x);
    double diff = fabs(x1 - x);
    printf("%2d\t%.6f\t%.6f\t%.6f\n", n, x, x1, diff);

    if (diff < eps) {
      break;
    }
    x = x1;
    n++;
  } while (n < 100);

  printf("\nRoot = %.6f (correct to %d decimal places)\n", x1, k);

  return 0;
}
