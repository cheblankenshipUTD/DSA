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

#ifndef MAZE_H
#define MAZE_H



class Maze{

    string block = "█";
    string path = "░";

    const int ROW = 11;
    const int COL = 27;


public:
  // Definition for singly-linked list.
    void maze(vector<vector<string>>& map){
        // █ block, ' ' street
        for (int i = 0; i < map.size(); ++i)
        {
            for (int j = 0; j < map[0].size(); ++j)
            {
                map[i][j] = "█";
            }
        }
        helper(map, 0, 0);
    }

    void showMaze(vector<vector<string>>& map){
        // print up wall
        for (int i = 0; i < map[0].size()+2; i++)
            cout << "█";
        cout << endl;
        for (int i = 0; i < map.size(); ++i)
        {   
            cout << "█";
            map[map.size()-1][map[0].size()-1] = "G";
            for (int j = 0; j < map[0].size(); ++j)
            {
                cout << map[i][j];
            }
            cout << "█" <<endl;
        }
        // print down wall
        for (int i = 0; i < map[0].size()+2; i++)
            cout << "█";
        cout << endl;
    }

    // DFS
    void helper(vector<vector<string>>& map, int i, int j){
        int direct[][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int visitOrder[] = {0,1,2,3};
        //out of boundary
        if(i < 0 || j < 0 || i >= map.size() || j >= map[0].size()) return ;
        
        //visited
        if(map[i][j] == " ") return ;

        //check cycle
        if(countVisitedNeighbor(map, i, j) > 1) return ;

        map[i][j] = ' '; 

        shuffle(visitOrder, 4);
        
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + direct[visitOrder[k]][0];
            int nj = j + direct[visitOrder[k]][1];
            helper(map, ni, nj);
        }
    }

    int countVisitedNeighbor(vector<vector<string>>& map, int i, int j){
        int direct[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int count = 0;
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + direct[k][0];
            int nj = j + direct[k][1];
            //out of boundary
            if(ni < 0 || nj < 0 || ni >= map.size() || nj >= map[0].size()) continue;
            if(map[ni][nj] == " ") count++;//visited
        }
        return count;
    }

    //
    void shuffle(int a[], int n){
        for (int i = 0; i < n; ++i)
        {
            swap(a[i], a[rand() % n]);
        }
    }
    //
    void swap(int & a, int &b){
        int c = a;
        a = b;
        b = c;
    }
    
};


#endif