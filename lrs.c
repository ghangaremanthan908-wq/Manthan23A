#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lrs(char* str) {
    int n = strlen(str);
    int dp[MAX][MAX];

   
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

   
    int index = dp[n][n];
    char lrs_str[MAX];
    lrs_str[index] = '\0';

    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (str[i - 1] == str[j - 1] && i != j) {
            lrs_str[--index] = str[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LRS Length: %d\n", dp[n][n]);
    printf("LRS: %s\n", lrs_str);
}

int main() {
    char str[] = "GGFTFGUFGEUDGJHU";
    lrs(str);
    return 0;
}