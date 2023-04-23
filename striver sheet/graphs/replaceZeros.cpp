#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int n, int m, int row, int col, pair<int, int> diff[]){
    vis[row][col] = 1;

    for(int i=0; i<n; i++){
        int nRow = row + diff[i].first;
        int nCol = col + diff[i].second;

        if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == '0'){
            dfs(grid, vis, n, m, nRow, nCol, diff);
        }
    }
}

void replaceEnclosedZeros(vector<vector<char>> &grid, int n, int m){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    pair<int, int> diff[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    for(int i=0; i<m; i++){
        if(grid[0][i] == '0' && vis[0][i] == 0)
            dfs(grid, vis, n, m, 0, i, diff);
        
        if(grid[n-1][i] == '0' && vis[n-1][i] == 0)
            dfs(grid, vis, n, m, n-1, i, diff);
    }

    for(int i=0; i<n; i++){
        if(grid[i][0] == '0' && vis[i][0] == 0)
            dfs(grid, vis, n, m, i, 0, diff);
        
        if(grid[i][n-1] == '0' && vis[i][n-1] == 0)
            dfs(grid, vis, n, m, i, n-1, diff);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 0){
                grid[i][j] = 'x';
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(auto &x: grid){
        for(auto &y: x){
            cin>>y;
        }
    }

    replaceEnclosedZeros(grid, n, m);

    cout<<"===============\n\n";
    for(auto x: grid){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}