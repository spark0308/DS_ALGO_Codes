#include<bits/stdc++.h>
using namespace std;

int droidRun(vector<vector<int>> spreadTime, int n, int m, int row, int col, int startTime, vector<vector<int>> &vis, pair<int, int> diff[]){
    if(startTime >= spreadTime[row][col]){
        return startTime;
    }

    int ans = spreadTime[row][col];

    for(int i=0; i<4; i++){
        int nRow = row + diff[i].first;
        int nCol = col + diff[i].second;

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0 && spreadTime[nRow][col] != -1){
            vis[nRow][nCol] = 1;
            ans = max(ans, droidRun(spreadTime, n, m, nRow, nCol, startTime+1, vis, diff));
        }
    }

    return ans;
}

int droidSurviveTime(vector<vector<int>> maze, int n, int m){
    vector<vector<int>> ghostSpreadTime(n, vector<int>(m, -1));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int drRow, drCol;
    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] == 5){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            if(maze[i][j] == 3){
                drRow = i;
                drCol = j;
            }
        }
    }

    pair<int, int> diff[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        ghostSpreadTime[row][col] = dis;
        q.pop();

        for(int i=0; i<4; i++){
            int nRow = row + diff[i].first;
            int nCol = col + diff[i].second;

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0 && maze[nRow][nCol] != 1){
                q.push({{nRow, nCol}, dis+1});
                vis[nRow][nCol] = 1;
            }
        }
    }

    if(ghostSpreadTime[drRow][drCol] == -1)
        return -1;

    vis = vector<vector<int>>(n, vector<int>(m, 0));
    return droidRun(ghostSpreadTime, n, m, drRow, drCol, 0, vis, diff);
}

int main(){
    int n, m;
    // int upper = 20, lower = 1;
    // n = (rand()%(upper - lower + 1)) + lower;
    // m = (rand()%(upper - lower + 1)) + lower;
    cin>>n>>m;
    vector<vector<int>> maze(n, vector<int>(m));

    int characters[] = {0, 1, 5};

    for(auto &row: maze){
        for(auto &cell: row){
            cin>>cell;     //cell = characters[rand()%3];
        }
    }

    // maze[rand()%n][rand()%m] = 3;

    // cout<<n<<" "<<m<<endl;
    // for(auto x: maze){
    //     for (auto y: x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<droidSurviveTime(maze, n, m)<<endl;

}


/*
Inputs                                  Outputs
9 9
0 0 0 0 1 0 3 0 0
0 5 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
*/