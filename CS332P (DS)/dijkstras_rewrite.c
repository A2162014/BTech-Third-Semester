#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int weights[V][V];

void dijkstra(int w[V][V], int src);
int minDistance(int d[V], bool sptS[V]);

int main(){
	int source;
	
	printf("Enter weights in adjacency matrix format: \n");
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			scanf("%d", &weights[i][j]);
		}
	}

	printf("\nYour adjacency matrix: \n");
	for (int i = 0; i < V; i++){
		printf("\n");
		for (int j = 0; j < V; j++){
			printf("%d ", weights[i][j]);
		}
	}
		
	printf("\n\nEnter Source: ");
	scanf("%d", &source);
	
	dijkstra(weights, source);
	
	return 0;
}

void dijkstra(int w[V][V], int src){
	int dist[V]; //shortest distance from src to i
	bool sptSet[V]; //shortest path tree set - true if vertex i is include in spt
		
	for(int i = 0;i < V; i++){
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	
	dist[src] = 0;

	for(int count = 0; count < V - 1; count++){
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for(int v = 0;v < V; v++)
			if (!sptSet[v] && w[u][v] 
				&& (dist[u] != INT_MAX) 
				&& (dist[u] + w[u][v] < dist[v]))
				dist[v] = dist[u] + w[u][v];
	}
	
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int minDistance(int d[], bool sptS[]){
	int min = INT_MAX;
	int min_index;
	
	for (int v = 0; v < V; v++)
		if (sptS[v] == false && d[v] <= min)
			min = d[v], min_index = v;
	
	return min_index;
}

