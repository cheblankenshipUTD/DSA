#include "string"
#include "vector"
#include "unordered_map"
#include "queue"
#include "cstdlib"
#include "ctime"
#include <iostream>
#include "algorithm"
#include "stack"

using namespace std;
#include "maze.h"
#include "solve.h"


int main(int argc, char const *argv[])
{
    // Generate maze
	Maze m;
    const int WIDTH = 27;
    const int HEIGHT = 11;
    srand(time(0));
    vector<string> row(WIDTH);
    vector<vector<string>> map;
    for (int i = 0; i < HEIGHT; ++i)
    {
        map.push_back(row);
    }
    m.maze(map);
    m.showMaze(map);

    

    // solve maze
    Solve s;
    vector<pair<int,int>> p;
    // Convert vector into 2D array
    string maze[13][29] = {
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}, 
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}
    };

    // convert generated vector maze into 2D array maze
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            maze[i+1][j+1] = map[i][j];
        }
    }

    bool visited[13][29];
    int x = 1, y = 1;
    bool foundExit = false;
    // Initialize visited locations to false
    for (int x = 0; x < 29; x++)
        for (int y = 0; y < 13; y++)
        visited[y][x] = false;
    visited[y][x] = true;
    // find path
    s.search(maze, visited, x, y, p);
    reverse(p.begin(), p.end());
    s.modifyMaze(maze, p);
    // get hte list of directions
    vector<string> pathDir;
    // print the direction
    s.direction(pathDir, p);
    cout << ">>>> Press ENTER key to show the path on the maze <<<<";
    cin.ignore(); 
    // drint the result of maze and path
    s.printMaze(maze);

    return 0;
}