#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define INF INT_MAX
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b

// For better understanding watch the gfg video.

int knapsack(int v[],int w[],int n,int W){
    int dp[n+1][W+1];             
    /*
    dp[i][j] denotes the max value which can be obtained using i elements with j weight capacity
    */
    for(int i=0;i<W+1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(w[i-1]>j)   // if the current element has weight greater than the current weight j then its not included
            {
                dp[i][j]=dp[i-1][j];  // we simply take the max value which can be obtained using i-1 objects and j weight
            }
            else
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-v[i-1]],dp[i-1][j]);
                /*
                if the current weight can be included then we find the maximum value of knapsack with current weight included
                and knapsack with current not included both having the same weight capacity j
                */
            }
        }
    }


    // Time complexity : O(W*N) not polynomial since the value of W can be way larger than N (its pseudo-polynomial).
    
    // Auxilliary space : O(W*N)
}

int main(){
    int v[]={10,40,30,50};
    int w[]={5,4,6,3};
    int size=sizeof(v)/sizeof(int);
    int W=10;
    printf("ANSWER FOR THE PROBLEM : %d\n",knapsack(v,w,size,W));
    return 0;
}