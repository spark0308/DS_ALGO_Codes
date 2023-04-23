#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> grid, vector<vector<int>> &ans, int n, int m){

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
            }
        }
    }

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1}; 
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;

        //cout<<row<<" "<<col<<" "<<dis<<endl;
        ans[row][col] = dis;
        q.pop();
        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 0 && vis[nRow][nCol] == 0){
                q.push({{nRow, nCol}, dis+1});
                vis[nRow][nCol] = 1;
            }
        }
    }
    
    cout<<" --------- \n";
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
}

void nearestOne(vector<vector<int>> grid, int n, int m){
    vector<vector<int>> ans(n, vector<int>(m, 0));

    bfs(grid, ans, n, m);
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(auto &x: grid){
        for(auto &y: x){
            cin>>y;
        }
    }

    nearestOne(grid, n, m);
}