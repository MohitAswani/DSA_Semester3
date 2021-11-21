#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF INT_MAX
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

int fibo(int n)
{
    int dp[n + 1];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <=n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n=1;
    printf("FIBO NUM %d : %d\n",n,fibo(n));
    return 0;
}