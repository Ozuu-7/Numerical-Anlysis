#include <stdio.h>

#define N 10

int main() {
  printf("Name: Abhronkosh Mondal, Roll No: 35\n\n");
  double x[N] = {2.00, 2.01, 2.02, 2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09};
  double y[N] = {5.54308063, 5.554909997, 5.56689485, 5.57903640, 5.59133585,
                 5.60379443, 5.61641340, 5.62919401, 5.64213754, 5.65524528};
  double h = x[1] - x[0];

  printf("Given Data Table (k = 5):\n\n");
  printf("%-10s%-15s\n", "x", "f(x)");
  for (int i = 0; i < N; i++) {
    printf("%-10.2f%-15.8f\n", x[i], y[i]);
  }

  /*double is necessary here because the table values have 8 significant digits
   but float only holds ~6-7, so higher-order differences become
   noise and the interpolated result is wrong. */
  {
    printf("\n Why float fails:- \n");
    float fy[N] = {5.54308063, 5.554909997, 5.56689485, 5.57903640, 5.59133585,
                   5.60379443, 5.61641340, 5.62919401, 5.64213754, 5.65524528};
    float ff[N][N];
    for (int i = 0; i < N; i++) {
      ff[i][0] = fy[i];
    }
    for (int j = 1; j < N; j++) {
      for (int i = 0; i < N - j; i++) {
        ff[i][j] = ff[i + 1][j - 1] - ff[i][j - 1];
      }
    }
    float u_f = (2.005 - 2.00) / 0.01;
    float res_f = ff[0][0];
    float ut_f = 1.0;
    for (int i = 1; i < N; i++) {
      ut_f *= (u_f - (i - 1)) / i;
      res_f += ut_f * ff[0][i];
    }
    printf("f(2.005) with float  = %.8f  (WRONG)\n", res_f);
  }

  double fwd[N][N];
  for (int i = 0; i < N; i++) {
    fwd[i][0] = y[i];
  }
  for (int j = 1; j < N; j++) {
    for (int i = 0; i < N - j; i++) {
      fwd[i][j] = fwd[i + 1][j - 1] - fwd[i][j - 1];
    }
  }

  printf("\nForward Difference Table:\n\n");
  for (int i = 0; i < N; i++) {
    printf("%-10.2f", x[i]);
    for (int j = 0; j < N - i; j++) {
      printf("%-10.4f", fwd[i][j]);
    }
    printf("\n");
  }

  double xp1 = 2.005;
  double u1 = (xp1 - x[0]) / h;
  double result1 = fwd[0][0];
  double u_term1 = 1.0;
  for (int i = 1; i < N; i++) {
    u_term1 *= (u1 - (i - 1)) / i;
    result1 += u_term1 * fwd[0][i];
  }
  printf("\nf(2.005) = %.8f  (Newton's Forward)\n", result1);

  double bwd[N][N];
  for (int i = 0; i < N; i++) {
    bwd[i][0] = y[i];
  }
  for (int j = 1; j < N; j++) {
    for (int i = j; i < N; i++) {
      bwd[i][j] = bwd[i][j - 1] - bwd[i - 1][j - 1];
    }
  }

  printf("\nBackward Difference Table:\n\n");
  for (int i = 0; i < N; i++) {
    printf("%-10.2f", x[i]);
    for (int j = 0; j <= i; j++) {
      printf("%-12.4f", bwd[i][j]);
    }
    printf("\n");
  }

  double xp2 = 2.086;
  double u2 = (xp2 - x[N - 1]) / h;
  double result2 = bwd[N - 1][0];
  double u_term2 = 1.0;
  for (int i = 1; i < N; i++) {
    u_term2 *= (u2 + (i - 1)) / i;
    result2 += u_term2 * bwd[N - 1][i];
  }
  printf("\nf(2.086) = %.8f  (Newton's Backward)\n", result2);

  printf("\nf(2.005) = %.8f\n", result1);
  printf("f(2.086) = %.8f\n", result2);

  return 0;
}
