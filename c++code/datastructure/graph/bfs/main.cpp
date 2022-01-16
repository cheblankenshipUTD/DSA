#include <cstdio>           // printf()
#include <queue>            // queue ADT
#include <unordered_set>    // hash-set ADT

#define ROW 8
#define COL 8

// Adjacency Matrix
int A[ROW][COL] = {
    {0,0,0,0,0,0,0,0}, // empty
    {0,0,1,1,1,0,0,0}, // vertex 1
    {0,1,0,1,0,0,0,0}, // vertex 2
    {0,1,1,0,1,1,0,0}, // vertex 3
    {0,1,0,1,0,1,0,0}, // vertex 4
    {0,0,0,1,1,0,1,1}, // vertex 5
    {0,0,0,0,0,1,0,0}, // vertex 6
    {0,0,0,0,0,1,0,0}  // vertex 7
};

// Queue to hold vertices
std::queue<int> q;

// HashSet to hold visited vertices
// std::unordered_set<int> visited;
int visited[COL] {0};



void bfs(int A[][COL])
{

    // 1. Declare an integer that tell which vertex to start
    int current = 5;

    // 2. Print the initial visited vertex data
    // printf("%d ", startVertex);

    // 3. Enqueue start verted into queue
    q.push(current);

    // 4. Loop until queue is empty
    // int current; // Declare current vertex variable
    while(!q.empty())
    {
        // printf("check");
        // 4-a. Dequeue the front and assign to the current vertex variable
        current = q.front(); 
        q.pop();

        // 4-b. Print the current vertex
        printf("%d ", current);

        // 4-c. Update the visited hash set
        // visited.insert(current);
        visited[current] = 1;

        // 4-d. Loop through the edges for current vertex
        for (int i = 1; i < COL; i++)
        {
            // printf("check 2");
            // auto it = visited.find(i);
            if(A[current][i] == 1 && visited[i] != 1)
            {
                q.push(i);
                visited[i] = 1;
                // visited.insert(i);
            }
        }
        

    }
}


int main()
{



    bfs(A);
    




    return 0;
}
