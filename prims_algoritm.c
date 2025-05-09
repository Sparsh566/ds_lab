#include<stdio.h>
#include<conio.h>
#define MAX 10
#define INF 999
// complete the missing code..
int cost[10][10];
int n;

void prims() {
	int visited[10]={0};
	int edge_count=0,min,a=-1,b=-1;
	int total_cost=0;

	visited[1]=1;
	while(edge_count<n-1){
		int min=INF;
		for(int i=1;i<=n;i++){
			if(visited[i]){
				for(int j=1;j<=n;j++){
					if(!visited[j]&&cost[i][j]<min){
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		if(a!=-1&&b!=-1){
			printf("Edge cost from %d to %d : %d\n",a,b,min);
			total_cost+=min;
			visited[b]=1;
			edge_count++;
		}else{
			break;
		}
	}
	printf("Minimum cost of spanning tree = %d\n",total_cost);
}

void main(){
	int e;
	int s,d,w;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&e);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cost[i][j]=0;

	for(int i=1;i<=e;i++){
		printf("Enter source : ");
		scanf("%d",&s);
		printf("Enter destination : ");
		scanf("%d",&d);
		printf("Enter weight : ");
		scanf("%d",&w);
		if(s<=0||d<=0||s>n||d>n||w<0){
			printf("Invalid data.Try again.\n");
			i--;
			continue;
		}

		cost[s][d]=w;
		cost[d][s]=w;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&cost[i][j]==0){
				cost[i][j]=INF;
			}
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are : \n");
	prims();
}
