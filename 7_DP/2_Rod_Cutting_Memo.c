#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF INT_MAX
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b
#define len 8

int memo[len+1];

void init_memo()
{
    for(int i=0;i<=len;i++)
    memo[i]=-1;
}
int rodCutting(int prices[],int l)
{
    if(l<=0)
    {
        return 0;
    }
    else
    {
        if(memo[l]==-1)
        {
            int max_val=INT_MIN;
            for(int i=0;i<l;i++)
            {
                max_val=max(max_val,prices[i]+rodCutting(prices,l-i-1));
            }
            memo[l]=max_val;
        }
    }
    return memo[l];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    init_memo();
    printf("%d\n",rodCutting(prices,len));
    return 0;
}