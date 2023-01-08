#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

/* DFS algorithm using adjacent matrix in C */

int V, visited[SIZE], G[SIZE][SIZE];

void DFS(int i) {
    visited[i] = 1;
    
	printf(" %d-> ", i+1);
    
	for(int j = 0;j < V; j++)
    {
        if(G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}

int main() {
    int i, j, v1, v2, E, source;
    
	printf("\t\t\tGraphs\n");
    
	printf("\nEnter the no of edges:");
    scanf("%d",&E);
    
	printf("\nEnter the no of vertices:");
    scanf("%d",&V);
    
	for(i = 0;i < V; i++)
    {
        for(j = 0;j < V; j++)
            G[i][j] = 0;        	
    }
    
    /*    creating edges :P    */
    for(i = 0;i < E; i++)
    {
        printf("\nEnter the edges (format: V1 V2) : ");
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = 1;
    }

    for(i = 0;i < V; i++)
    {
        for(j = 0;j < V; j++)
            printf(" %d ", G[i][j]);
        printf("\n");
    }
    
    printf("\nEnter the source: ");
    scanf("%d", &source);
        
	DFS(source-1);
    
	return 0;
}
