#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;


#ifndef SOLVE_H
#define SOLVE_H


class Solve{

public:
    
    const string block = "█";
    const string path = "*";


    bool validMove(string maze[][29], bool visited[][29],int newX, int newY)
    {
        // Check for going off the maze edges
        if (newX < 0 || newX >= 29)
            return false;
        if (newY < 0 || newY >= 13)
            return false;
        // Check if target is a wall
        if (maze[newY][newX]=="█")
            return false;
        // Check if visited
        if (visited[newY][newX])
            return false;

        return true;
    }


    bool move(string maze[][29], bool visited[][29],int &curX, int &curY, int newX, int newY)
    {
        bool foundExit = false;
        if (maze[newY][newX]=="G") // Check for exit
            foundExit = true;
            curX = newX; // Update location curY = newY;
            visited[curY][curX] = true;
        
        return foundExit;
    }


    void printMaze(string maze[][29])
    {
        for (int y=0; y < 13;y++)
        {
            for (int x=0; x < 29; x++)
            {
                cout << maze[y][x];
            }
            cout << endl;
        }
    }

    void modifyMaze(string maze[][29], vector<pair<int,int>>& p)
    {
        for (int i=0; i < p.size(); i++)
        {
            maze[p[i].first][p[i].second] = "*";
        }
    }

    // compare the current and next position and find the firction SENW
    // store them in another list
    void direction(vector<string>& pathDir, vector<pair<int,int>> p)
    {
        string dir[4] = {"N", "S", "W", "E"};
        int curX, curY;
        int nextX, nextY;
        curX = p[0].first;
        curY = p[0].second;
        for (int i = 1; i < p.size(); i++)
        {
            nextX = p[i].first;
            nextY = p[i].second;
            int dirX = curX - nextX;
            int dirY = curY - nextY;
            // up (N)
            if ( dirX == -1 && dirY == 0 )
            {
                pathDir.push_back("S");
            }
            // down (S)
            if ( dirX == 1 && dirY == 0 )
            {
                pathDir.push_back("N");
            }
            // down (W)
            if ( dirX == 0 && dirY == 1 )
            {
                pathDir.push_back("W");
            }
            // down (E)
            if ( dirX == 0 && dirY == -1 )
            {
                pathDir.push_back("E");
            }
            // update currendX,Y
            curX = p[i].first;
            curY = p[i].second;
        }

        // print the list of directions
        cout << "Set of directions from start to goal" << endl;
        int count = pathDir.size()/5;
        for (string d: pathDir)
        {
            cout << d << " ";
        }
        cout << endl << endl;;
    }


    bool search(string maze[][29], bool visited[][29], int x, int y, vector<pair<int,int>>& p) {
        bool foundExit;
        if (maze[y][x]=="G")
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



};


#endif