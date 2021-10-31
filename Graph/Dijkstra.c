#include <stdio.h>
#include <conio.h>
#define INFINITY 999
#define V 5

typedef enum{TRUE,FALSE}Boolean;

void dijkstra(int graph[V][V], int src);

int main()
{
	int graph[V][V]={{INFINITY,10,INFINITY,30,INFINITY},
					{INFINITY,INFINITY,50,INFINITY,INFINITY},
					{20,INFINITY,INFINITY,INFINITY,10},
					{INFINITY,INFINITY,20,INFINITY,60},
					{INFINITY,INFINITY,INFINITY,INFINITY,INFINITY}					
					};
	dijkstra(graph, 0);
	return 0;
}

int minDistance(int output[], Boolean SET[])
{
	int min, min_index, v;
	min = INFINITY;
	
	for(v=0;v<V;v++){
		if(SET[v]==FALSE && output[v]<=min){
			min = output[v];
			min_index =v;
		}
	}
	return min_index;
}

void printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   int i;
   for (i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int output[V];
	Boolean SET[V];
	int i, count, v;
	  
	for(i=0;i<V;i++){
		output[i]=INFINITY;
		SET[i] = FALSE; //FALSE IF UNVISITED, ELSE TRUE
	}
	
	output[src] = 0;
	
	for(count=0;count<V-1;count++){
		int u = minDistance(output, SET);
		SET[u] = TRUE;
		
		for(v=0;v<V;v++){
			if(graph[u][v] && output[u]!= INFINITY
								 && output[u] + graph[u][v] < output[v]){
				output[v] = output[u]+graph[u][v];		 	
			 }
		}
	}
	printSolution(output, V);
}
