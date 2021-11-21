#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define INF INT_MAX
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b

int knapsack(int v[],int w[],int n,int W,int i){
    if(i==n||w==0)
    {
        return 0;
    }

    if(w[i]<W)
    {
        return max(v[i]+knapsack(v,w,n,W-w[i],i+1),knapsack(v,w,n,W,i+1));
    }
    else
    {
        return knapsack(v,w,n,W,i+1);
    }

    // time complexity : O(2^n) 
}

int main(){
    int v[]={10,40,30,50};
    int w[]={5,4,6,3};
    int size=sizeof(v)/sizeof(int);
    int W=10;
    printf("ANSWER FOR THE PROBLEM : %d\n",knapsack(v,w,size,W,0));
    return 0;
}