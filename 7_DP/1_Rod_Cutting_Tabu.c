#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF INT_MAX
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

int rodCutting(int len, int prices[])
{
    int val[len + 1];
    val[0] = 0;

    for (int i = 1; i <= len; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, prices[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }

    return val[len];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length = sizeof(prices)/sizeof(int);
    printf("%d\n",rodCutting(length,prices));
    return 0;
}