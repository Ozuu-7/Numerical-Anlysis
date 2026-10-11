#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double a, b;

double f(double x) { return sqrt(sin(x) + cos(x)); }

double trap(int n) {
  double h = (b - a) / n, sum = f(a) + f(b);
  for (int i = 1; i < n; i++) {
    sum += 2 * f(a + i * h);
  }
  return (h / 2.0) * sum;
}

int main() {
  int d, n = 1;
  double eps, I1, I2, diff;

  printf("Enter lower limit: ");
  scanf("%lf", &a);
  printf("Enter upper limit: ");
  scanf("%lf", &b);
  a = a * PI / 180.0;
  b = b * PI / 180.0;

  printf("Enter accuracy (decimal places): ");
  scanf("%d", &d);
  eps = pow(10, -(d + 1));

  I1 = trap(n);
  printf("\n n\t Integral\t Difference\n");
  printf("%2d\t%.6f\t-\n", n, I1);

  do {
    n++;
    I2 = trap(n);
    diff = fabs(I1 - I2);
    printf("%2d\t%.6f\t%.6e\n", n, I2, diff);
    I1 = I2;
  } while (diff > eps && n < 50);

  printf("\nIntegral value = %.6f\n", I2);
  printf("Correct up to %d decimal places after %d subintervals\n", d, n);

  return 0;
}
