#include<bits/stdc++.h>
using namespace std;

void dfs(int n, int m, vector<vector<int>> grid, vector<vector<int>> &vis, int row, int col, int delRow[], int delCol[]){
    vis[row][col] = 1;

    for(int i=0; i<4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
            dfs(n, m, grid, vis, nRow, nCol, delRow, delCol);
        }
    }
}

int solution(int n, int m, vector<vector<int>> grid){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i=0; i<n; i++){
        if(grid[i][0] == 1 && vis[i][0] == 0)
            dfs(n, m, grid, vis, i, 0, delRow, delCol);
        if(grid[i][n-1] == 1 && vis[i][n-1] == 0)
            dfs(n, m, grid, vis, i, 0, delRow, delCol);
    }

    for(int i=0; i<m; i++){
        if(grid[0][i] == 1 && vis[0][i] == 0)
            dfs(n, m, grid, vis, 0, i, delRow, delCol);
        if(grid[n-1][i] == 1 && vis[n-1][i] == 0)
            dfs(n, m, grid, vis, n-1, i, delRow, delCol);
    }

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1)
                count++;
        }
    }

    return count;

}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for(auto &x: grid){
        for(auto &y: x){
            cin>>y;
        }
    }

    cout<<solution(n, m, grid)<<endl;
}

/*
7 7
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 1 1 1 1 0
0 0 0 0 0 1 0
0 0 0 0 1 0 0
*/