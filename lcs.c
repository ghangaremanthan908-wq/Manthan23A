#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[MAX][MAX];

    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

 
    int index = dp[m][n];
    char lcs_str[MAX];
    lcs_str[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[--index] = X[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS Length: %d\n", dp[m][n]);
    printf("LCS: %s\n", lcs_str);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    lcs(X, Y);
    return 0;
}
    