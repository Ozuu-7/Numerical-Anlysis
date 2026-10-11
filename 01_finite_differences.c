#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  printf("Enter x and y values:\n");
  for (int i = 0; i < n; i++) {
    printf("  x[%d], y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }

  double fwd[MAX][MAX], bwd[MAX][MAX];
  for (int i = 0; i < n; i++) {
    fwd[i][0] = y[i];
    bwd[i][0] = y[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      fwd[i][j] = fwd[i + 1][j - 1] - fwd[i][j - 1];
    }
  }

  printf("\nForward Differences (Delta):\n");
  for (int j = 1; j < n; j++) {
    printf("  Delta^%d: ", j);
    for (int i = 0; i < n - j; i++) {
      printf("%.4f  ", fwd[i][j]);
    }
    printf("\n");
  }

  for (int j = 1; j < n; j++) {
    for (int i = j; i < n; i++) {
      bwd[i][j] = bwd[i][j - 1] - bwd[i - 1][j - 1];
    }
  }

  printf("\nBackward Differences (Nabla):\n");
  for (int j = 1; j < n; j++) {
    printf("  Nabla^%d: ", j);
    for (int i = j; i < n; i++) {
      printf("%.4f  ", bwd[i][j]);
    }
    printf("\n");
  }

  printf("\nCentral Differences (delta):\n");
  for (int j = 1; j < n; j++) {
    printf("  delta^%d: ", j);
    for (int i = 0; i < n - j; i++) {
      printf("%.4f  ", fwd[i][j]);
    }
    printf("\n");
  }

  printf("\nShift Operator (E): E^k y_i = y_(i+k)\n");
  for (int k = 1; k < n; k++) {
    printf("  E^%d: ", k);
    for (int i = 0; i + k < n; i++) {
      printf("%.4f  ", y[i + k]);
    }
    printf("\n");
  }

  printf("\nVerification of relations:\n");
  printf("  Delta = E - 1:  Delta y_0 = %.4f, (E-1) y_0 = %.4f\n", y[1] - y[0],
         y[1] - y[0]);
  printf("  Nabla = 1 - E^(-1):  Nabla y_%d = %.4f, (1-E^-1) y_%d = %.4f\n",
         n - 1, y[n - 1] - y[n - 2], n - 1, y[n - 1] - y[n - 2]);
  printf("  E = 1 + Delta:  E y_0 = %.4f, (1+Delta) y_0 = %.4f\n", y[1],
         y[0] + (y[1] - y[0]));

  return 0;
}
