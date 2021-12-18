// #include "string"
// #include "vector"
// #include "unordered_map"
// #include "queue"
// #include "cstdlib"
// #include "ctime"
// #include <iostream>
// #include "algorithm"
// #include "stack"
// #include <unordered_map>


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

const int WIDTH = 27;
const int HEIGHT = 11;
string block = "█";
string path = "░";


// Function prototypes
void printMaze(string maze[][WIDTH]); 
bool validMove(string maze[][WIDTH], bool visited[][WIDTH],int newX, int newY);
bool move(string maze[][WIDTH], bool visited[][WIDTH],int &curX, int &curY, int newX, int newY);



bool validMove(string maze[][WIDTH], bool visited[][WIDTH],int newX, int newY)
{
  // Check for going off the maze edges
  if (newX < 0 || newX >= WIDTH)
    return false;
  if (newY < 0 || newY >= HEIGHT)
    return false;
  // Check if target is a wall
  if (maze[newY][newX]=="█")
    return false;
  // Check if visited
  if (visited[newY][newX])
    return false;
 
  return true;
}


bool move(string maze[][WIDTH], bool visited[][WIDTH],int &curX, int &curY, int newX, int newY)
{
  bool foundExit = false;
  if (maze[newY][newX]=="E") // Check for exit
    foundExit = true;
    curX = newX; // Update location curY = newY;
    visited[curY][curX] = true;
  
  return foundExit;
}


void printMaze(string maze[][WIDTH])
{
  for (int y=0; y < HEIGHT;y++)
  {
    for (int x=0; x < WIDTH; x++)
    {
      cout << maze[y][x];
    }
    cout << endl;
  }
}

void modifyMaze(string maze[][WIDTH], vector<pair<int,int>>& p)
{
  
  for (int i=0; i < p.size(); i++)
  {
    maze[p[i].first][p[i].second] = "░";
  }
}


bool search(string maze[][WIDTH], bool visited[][WIDTH], int x, int y, vector<pair<int,int>>& p) {
  bool foundExit;
  if (maze[y][x]=="E")
    return true;
  visited[y][x]=true;
  if (validMove(maze,visited,x,y-1))
    foundExit = search(maze,visited,x,y-1, p); 
  if (!foundExit && (validMove(maze,visited,x,y+1)))
    foundExit = search(maze,visited,x,y+1, p); 
  if(!foundExit && (validMove(maze,visited,x-1,y)))
    foundExit = search(maze,visited,x-1,y, p); 
  if(!foundExit && (validMove(maze,visited,x+1,y)))
    foundExit = search(maze,visited,x+1,y, p);
  if (foundExit)
  {
    p.push_back(make_pair(y,x));
    return true;
  }

  return false;
}



int main() {

  vector<pair<int,int>> p;

  // string maze[HEIGHT][WIDTH] = {
  //   {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}, 
  //   {"█"," "," "," "," "," ","█"," "," ","█","█","█","█","█"," "," "," "," "," ","█","█"," "," "," "," ","█","█"}, 
  //   {"█"," ","█"," "," "," ","█"," "," ","█"," "," "," ","█","█"," ","█","█"," ","█","█"," ","█","█"," "," ","█"}, 
  //   {"█"," ","█","█","█"," ","█"," "," ","█"," ","█"," "," "," "," "," ","█"," "," ","█"," ","█","█","█","█","█"}, 
  //   {"█"," "," "," ","█"," ","█"," "," ","█"," ","█"," ","█","█","█","█","█"," ","█","█"," "," "," "," ","█","█"}, 
  //   {"█"," "," "," ","█"," "," "," ","█","█","█","█"," "," "," "," "," ","█"," ","█","█","█","█","█"," ","█","█"}, 
  //   {"█"," ","█","█","█"," "," "," "," ","█","█"," "," ","█","█"," ","█","█"," ","█","█"," ","█"," "," ","█","█"}, 
  //   {"█"," ","█"," "," "," ","█"," "," ","█"," "," ","█"," ","█"," "," ","█"," "," "," ","█","█"," ","█","█","█"}, 
  //   {"█"," "," "," "," "," ","█"," "," "," "," ","█","█"," "," ","█"," ","█"," ","█"," ","█"," "," "," "," ","█"}, 
  //   {"█","█","█","█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," "," "," ","█"," ","E","█"},
  //   {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}
  // };
  string maze[HEIGHT][WIDTH] = {
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," "," "," ","█","█","█","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," ","█","█","█","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," ","█","█","█","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," "," "," "," ","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," ","█","█"," ","█","█","█","█","█","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█"," "," ","█"," "," "," "," "," "," ","█"}, 
    {"█"," ","█","█","█","█","█","█","█","█","█","█","█","█","█"," ","█","█","█","█","█","█","█","█","█"," ","█"}, 
    {"█"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","█","E","█"},
    {"█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█","█"}
  };


  bool visited[HEIGHT][WIDTH];
  int x = 1, y = 1;
  bool foundExit = false;
  // Initialize visited locations to false
  for (int x = 0; x < WIDTH; x++)
    for (int y = 0; y < HEIGHT; y++)
      visited[y][x] = false;
  visited[y][x] = true;
  //  find path
  cout << search(maze,visited,x,y,p) << endl;
  // get the path
  reverse(p.begin(), p.end());
  modifyMaze(maze, p);
  // print the path
  printMaze(maze);

}