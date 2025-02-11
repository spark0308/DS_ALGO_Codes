#include<bits/stdc++.h>
using namespace std;

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto x: walls)
        {
            grid[x[0]][x[1]] = 3;
        }

        for(auto x: guards)
        {
            grid[x[0]][x[1]] = 2;
        }

        for(auto x: guards)
        {
            //Go north;
            for(int i=x[0]-1; i>=0; i--){
                if(grid[i][x[1]] == 2) break;
                if(grid[i][x[1]] == 3) break;
                grid[i][x[1]] = 1;
            }

            //Go south
            for(int i=x[0]+1; i<m; i++){
                if(grid[i][x[1]] == 2) break;
                if(grid[i][x[1]] == 3) break;
                grid[i][x[1]] = 1;
            }

            //Go left
            for(int i=x[1]-1; i>=0; i--){
                if(grid[x[0]][i] == 2) break;
                if(grid[x[0]][i] == 3) break;
                grid[x[0]][i] = 1;
            }

            //Go right
            for(int i=x[1]+1; i<n; i++){
                if(grid[x[0]][i] == 2) break;
                if(grid[x[0]][i] == 3) break;
                grid[x[0]][i] = 1;
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) ans++;
            }
        }

        return ans;
    }

int main(){

}