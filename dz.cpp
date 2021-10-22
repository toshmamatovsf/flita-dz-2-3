#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int graph[100000];
bool used[100000];

void dfs(int v, int p = -1) {    //p - ïðÿìîé ïðåäîê
    used[v] = true;
	int u=0;
    for (u=0;u<=graph[v];u++) {
        if (!used[u]) {
            dfs(u, v);
        } else if (u != p) {
            cout << "Graph has cycles.";
            exit(0);    //Ïîëíîñòüþ âûéòè èç ïðîãðàììû.
        }
    }
}

int main()
{
	int matrix[30][30];
	int i=0, j=0;
	int n=0;
	FILE *file;
	int a = 0, b = 0, c, k = 0, d = 0;
    char is = 'T';
	printf("Input the number of edges: ");
	scanf("%d", &n);
	
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
			matrix[i][j]=0;
	}
	
	file = fopen("Toshmamatov.gv", "w");
    fputs("graph{\n", file);
    
    for(i=1;i<=n;i++)
    {
    	for(j=i+1;j<=n;j++)
    	{
    		printf("matrix[%d][%d]: ", i, j);
    		scanf("%d", &matrix[i][j]);
    		if(matrix[i][j]==1)
    		{
    			matrix[j][i]=1;
    			fprintf(file, "\t%d--%d\n", i, j);
			}
			else
			{
				fprintf(file, "\t%d\n", i);
			}
		}
	}
	
        printf(" ");
        for(j=1;j<=n;j++)
        {
        	printf(" %d",j);
		}
		printf("\n");
   for(i=1;i<=n;i++)
   {
   		printf("%d ",i);
   		for(j=1;j<=n;j++)
   		{
   			printf("%d ", matrix[i][j]);
	   	}
	   	printf("\n");
   }
   
        fputc('}', file);
        fclose(file);
        system("dot -Tpng Toshmamatov.gv -o Toshmamatov.png");
        
        for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << "Graph has no cycles.";
        return 0;
   
	
}
