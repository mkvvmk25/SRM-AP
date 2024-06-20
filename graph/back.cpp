#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xadd[] = {0,1,0,-1}; 
int yadd[] = {1,0,-1,0};

int  ratDfs(int x, int y, vector<vector<int>> &maze,
            int row, int col, int &cnt)
{
    // base reched des 
    if( x == row - 1 && y == col-1)
    {
        cnt++;
        for(int i = 0; i < row; i++)
        {
            for(int j =0 ; j < col; j++)
            {
                cout << maze[i][j] <<" ";
            }
            cout << endl; 
        }
            cout << endl; 
        return true;  
    }

    // look at the dire
    for(int i = 0; i < 4; i++)
    {
        int nextx = x + xadd[i];
        int nexty = y + yadd[i];

        if (maze[nextx][nexty] == 1 && nextx < row && nextx >= 0 &&
            nexty < col && nexty >= 0)
        {
            // mark this its is vis
            maze[nextx][nexty] = 2; 
            ratDfs(nextx, nexty, maze, row, col ,cnt);  
            // if( cnt >= 1 )
            // {
            //     return cnt; 
            // }
            // mark it  unv 
            maze[nextx][nexty] = 1; 
        }
        
    }

    return cnt; 


}



int main()
{
    vector<vector<int>> maze = {{1,1,0,1},
                                {0,1,1,0},
                                {0,1,1,1},
                                {1,1,1,1}}; 
    // int arr[][] = { {}}; 
    int row = 4, col = 4;
    //     x  y
    int cnt = 0; 
    if( maze[0][0] == 1)
    {
        maze[0][0] = 2; 
        ratDfs(0, 0, maze, row, col, cnt) ;  
    }
    cout << cnt; 
}