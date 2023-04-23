#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int n, int m, int val){
    int initial = grid[row][col];
    grid[row][col] = val;

    for(int delRow = -1; delRow<=1; delRow++){
        for(int delCol = -1; delCol<=1; delCol++){
            int nRow = row + delRow;
            int nCol = col + delCol;
            if(nRow >=0 && nRow<n && nCol >= 0 && nCol < m && (delRow+delCol == 1 || delRow+delCol == -1 ) && !vis[nRow][nCol] && grid[nRow][nCol] == initial){
                vis[nRow][nCol] = 1;
                dfs(grid, vis, nRow, nCol, n, m, val);
            }
        }
    }
}

void floodFill(vector<vector<int>> grid, int sr, int sc, int val){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    vis[sr][sc] = 1;
    dfs(grid, vis, sr, sc, n, m, val);

    for(auto x: grid){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n, m, sr, sc, val;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(auto &x: grid){
        for(auto &y: x){
            cin>>y;
        }
    }

    cin>>sr>>sc>>val;

    floodFill(grid, sr, sc, val);


}