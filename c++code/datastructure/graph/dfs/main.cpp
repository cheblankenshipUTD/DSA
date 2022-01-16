#include <stdio.h>      // printf


#define ROW 8
#define COL 8

int A[ROW][COL] = {
    {0,0,0,0,0,0,0,0}, // ---
    {0,0,1,1,1,0,0,0}, // vertex 1
    {0,1,0,1,0,0,0,0}, // vertex 2
    {0,1,1,0,1,1,0,0}, // vertex 3
    {0,1,0,1,0,1,0,0}, // vertex 4
    {0,0,0,1,1,0,1,1}, // vertex 5
    {0,0,0,0,0,1,0,0}, // vertex 6
    {0,0,0,0,0,1,0,0}  // vertex 7
};

int visited[COL] = {0};

void dfs(int A[ROW][COL], int vertex)
{
    if (visited[vertex] == 0)
    {
        printf("%d ", vertex);
        visited[vertex] = 1;
        for (int column = 1; column < COL; column++)
        {
            if (A[vertex][column] == 1 && visited[column] == 0)
            {
                dfs(A, column);
            }
        }
    }
}


int main()
{
    dfs(A, 5);
    return 0;
}