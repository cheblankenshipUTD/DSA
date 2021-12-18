#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// const int WIDTH = 10;
// const int HEIGHT = 10;

string block = "█";
string path = "░";
const int HEIGHT = 11;
const int WIDTH = 27;

// Function prototypes
void printMaze(vector<vector<string>> maze, int curx, int cury, vector<pair<int,int>>& p); 
bool validMove(vector<vector<string>> maze, bool visited[][WIDTH],int newX, int newY);
bool move(vector<vector<string>> maze, bool visited[][WIDTH],int &curX, int &curY, int newX, int newY);


// Return true or false if moving to the specified coordinate is valid // Return false if we have been to this cell already
bool validMove(vector<vector<string>>& maze, bool visited[][WIDTH],int newX, int newY)
{
  // Check for going off the maze edges
  if (newX < 0 || newX >= WIDTH)
    return false;
  if (newY < 0 || newY >= HEIGHT)
    return false;
  // Check if target is a wall
  if (maze[newY][newX]=='X')
    return false;
  // Check if visited
  if (visited[newY][newX])
    return false;
 
  return true;
}

//
bool move(vector<vector<string>>& maze, bool visited[][WIDTH],int &curX, int &curY, int newX, int newY)
{
  bool foundExit = false;
  if (maze[newY][newX]=='E') // Check for exit
    foundExit = true;
    curX = newX; // Update location curY = newY;
    visited[curY][curX] = true;
  
  return foundExit;
}


void printMaze(vector<vector<string>>& maze, int curx, int cury, vector<pair<int,int>>& p) {
  for (int y=0; y < HEIGHT;y++)
  {
    for (int x=0; x < WIDTH; x++)
    {
     if ((x==curx) && (y==cury))
     {
       cout << "@";
       p.push_back(make_pair(y,x));
     }
     else{
       cout << maze[y][x];
     }
    }
    cout << endl;
  }
}

void printSet(vector<pair<int,int>>& p)
{
  for (int i=0; i < p.size(); i++)
  {
    cout << p[i].first << " " << p[i].second << endl;
  }
  
}



bool search(vector<vector<string>>& maze, bool visited[][WIDTH], int x, int y, vector<pair<int,int>>& p) {
  bool foundExit;
  if (maze[y][x]=='E')
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
    printMaze(maze,x,y,p);
    cout << endl;
    return true;
  }

  return false;
}




int main() {

  vector<pair<int,int>> p;

  char maze[HEIGHT][WIDTH] = {
    {'X','X','X','X','X','X','X','X','X','X'}, 
    {'X',' ',' ',' ',' ',' ','X',' ',' ','X'}, 
    {'X',' ','X',' ',' ',' ','X',' ',' ','X'}, 
    {'X',' ','X','X','X',' ','X',' ',' ','X'}, 
    {'X',' ',' ',' ','X',' ','X',' ',' ','X'}, 
    {'X',' ',' ',' ','X',' ',' ',' ','X','X'}, 
    {'X',' ','X','X','X',' ',' ',' ',' ','X'}, 
    {'X',' ','X',' ',' ',' ','X',' ',' ','X'}, 
    {'X',' ',' ',' ',' ',' ','X',' ','E','X'}, 
    {'X','X','X','X','X','X','X','X','X','X'}
  };

  bool visited[HEIGHT][WIDTH];
  int x = 1, y = 1;
  bool foundExit = false;
  // Initialize visited locations to false
  for (int x = 0; x < WIDTH; x++)
    for (int y = 0; y < HEIGHT; y++)
      visited[y][x] = false;
  visited[y][x] = true;
  cout << search(maze,visited,x,y,p) << endl;

  cout << "check..." << endl;
  cout << "set >> ";
  reverse(p.begin(), p.end());
  printSet(p);
}