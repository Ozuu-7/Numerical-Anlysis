# Numerical Analysis in C

C implementations of numerical methods covered in Numerical Analysis.

## Disclaimer

This repository is created for my personal use and coursework. The implementations are meant for me to keep a tab of the things being done in class and for future reference. If you choose to use any of this code, you do so entirely at your own risk, dont trust my code. Thank you

## Contents

### Unit I: Finite Differences

| File | Description |
|------|-------------|
| `01_finite_differences.c` | Forward, backward, central, and shift operators |
| `02_difference_table.c` | Forward and backward difference tables |

### Unit II: Interpolation

| File | Description |
|------|-------------|
| `03_newton_forward.c` | Newton's forward interpolation |
| `04_newton_backward.c` | Newton's backward interpolation |
| `05_lagrange.c` | Lagrange interpolation |
| `06_newton_divided_diff.c` | Newton's divided difference interpolation |
| `07_inverse_interpolation.c` | Inverse interpolation using Lagrange |

### Unit III: Numerical Integration

| File | Description |
|------|-------------|
| `08_numerical_integration.c` | Midpoint numerical integration |
| `09_simpson.c` | Trapezoidal and Simpson's 1/3 rule |
| `10_weddle.c` | Weddle's rule |
| `11_trapezoidalrule.c` | Trapezoidal rule with accuracy control |

### Unit IV: Root Finding & Linear Systems

| File | Description |
|------|-------------|
| `12_tabulation.c` | Tabulation method for root finding |
| `13_bisection.c` | Bisection method |
| `14_regula_falsi.c` | Regula Falsi (False Position) method |
| `15_newton_raphson.c` | Newton-Raphson method |
| `16_lu_decomposition.c` | LU Decomposition (Doolittle's method) |
| `17_gauss_jordan.c` | Gauss-Jordan elimination |
| `18_gauss_jacobi.c` | Gauss-Jacobi method |
| `19_gauss_seidel.c` | Gauss-Seidel method |
| `20_fixed_point.c` | Fixed point iteration method |
| `21_gauss_elimination.c` | Gauss elimination with back substitution |

## How to compile and run

You need a C compiler (GCC, Clang, or MSVC). Each file is a standalone program.

To compile a single file:

```
gcc -o 03_newton_forward 03_newton_forward.c -lm
```

To run it:

```
./03_newton_forward
```

On Windows without a Unix-like shell:

```
03_newton_forward.exe
```

To compile everything at once (PowerShell):

```powershell
Get-ChildItem *.c | ForEach-Object { gcc -o ($_.BaseName + ".exe") $_.FullName -lm }
```

To compile everything at once (Bash):

```bash
for f in *.c; do gcc -o "${f%.c}" "$f" -lm; done
```

All programs are interactive and will prompt you for input.
