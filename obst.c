#include <stdio.h>
#include <stdlib.h>
#include <float.h>  //maxxxx

#define MAX 100

double e[MAX][MAX], w[MAX][MAX];
int root[MAX][MAX];

double optimal_bst(double p[], double q[], int n) {
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    return e[1][n];
}

int main() {
    int n = 4;
    double p[] = {0.0,0.1, 0.2, 0.4, 0.3};
    double q[] = {.05, 0.1, 0.05, 0.05, 0.1};

    double result = optimal_bst(p, q, n);
    printf("Minimum expected cost of OBST: %.4f\n", result);

    return 0;
}






