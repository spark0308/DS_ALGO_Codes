#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> grid, int n, int m){
    queue<pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});

    while(!q.empty()){
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();

        for(int delRow = -1; delRow <= 1; delRow++){
            for(int delCol = -1; delCol <= 1; delCol++){
                int nRow = crow + delRow;
                int nCol = ccol + delCol;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}

void dfs(vector<vector<int>> grid, vector<vector<int>> &vis , int row, int col,int n, int m){
    for(int delRow = -1; delRow <= 1; delRow++){
        for(int delCol = -1; delCol <= 1; delCol++){
            int nRow = row + delRow;
            int nCol = col + delCol;

            if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                vis[nRow][nCol] = 1;
                dfs(grid, vis, nRow, nCol, n, m);
            }
        }
    }

}

pair<int, int> numIslands(vector<vector<int>> grid, int n, int m){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    int countDfs = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == 1){
                count++;
                bfs(row, col, vis, grid, n, m);
            }
        }
    }

    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == 1){
                countDfs++;
                dfs(grid, vis, row, col, n, m);
            }
        }
    }

    return {count, countDfs};
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    pair<int, int> ans = numIslands(grid, n, m);

    cout<<ans.first<<" "<<ans.second<<endl;

}