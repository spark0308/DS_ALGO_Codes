#include<bits/stdc++.h>
using namespace std;

int timeForRotOrange(vector<vector<int>> carton){
    int n = carton.size();
    int m = carton[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(carton[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 1;    
            }
        }
    }

    int time = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);

        q.pop();
        for(int i=0; i<4; i++){
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
            && vis[nRow][nCol] != 1 && carton[nRow][nCol] == 1){
                vis[nRow][nCol] = 1;
                q.push({{nRow, nCol}, t+1});
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 1 && carton[i][j] == 1){
                return -1;
            }
        }
    }

    return time;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> carton(n, vector<int>(n));

    for(auto &x: carton){
        for(auto &y: x){
            cin>>y;
        }
    }

    cout<<timeForRotOrange(carton)<<endl;
}