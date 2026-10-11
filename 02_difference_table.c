#include <stdio.h>

#define MAX 20

int main() {
  int n;
  double x[MAX], y[MAX], diff[MAX][MAX];

  printf("Enter number of data points: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("x[%d]: ", i);
    scanf("%lf", &x[i]);
    printf("y[%d]: ", i);
    scanf("%lf", &y[i]);
  }

  for (int i = 0; i < n; i++) {
    diff[i][0] = y[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
    }
  }

  printf("\nForward Difference Table:\n\n");

  for (int i = 0; i < n; i++) {
    printf("%-10.4f", x[i]);
    for (int j = 0; j < n - i; j++) {
      printf("%-12.4f", diff[i][j]);
    }
    printf("\n");
  }

  double bdiff[MAX][MAX];
  for (int i = 0; i < n; i++) {
    bdiff[i][0] = y[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = j; i < n; i++) {
      bdiff[i][j] = bdiff[i][j - 1] - bdiff[i - 1][j - 1];
    }
  }

  printf("\nBackward Difference Table:\n\n");

  for (int i = 0; i < n; i++) {
    printf("%-10.4f", x[i]);
    for (int j = 0; j <= i; j++) {
      printf("%-12.4f", bdiff[i][j]);
    }
    printf("\n");
  }

  return 0;
}
