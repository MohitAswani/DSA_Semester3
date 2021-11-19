#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define INF INT_MAX
#define V 5
void function(){

}

int main(){
    int adj[V][V]={
        {0,1,0,0,0},
        {1,0,1,0,0},
        {0,1,0,1,0},
        {0,0,1,0,1},
        {0,0,0,1,0}
    };

    for(int i=0;i<V;i++){
        printf("%d : ",i);
        for(int j=0;j<V;j++){
            if(adj[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}