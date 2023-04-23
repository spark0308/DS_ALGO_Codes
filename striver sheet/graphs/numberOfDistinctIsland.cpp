#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> grid,
         vector<vector<int>> &vis,
         int n, int m, int row, int col, int baseRow, int baseCol,
         vector<pair<int, int>> &dfsArray,
         int delRow[], int delCol[])
{
    vis[row][col] = 1;
    dfsArray.push_back({row - baseRow, col - baseCol});

    for(int i=0; i<n; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m && 
        vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
            dfs(grid, vis, n, m, nRow, nCol, baseRow, baseCol, dfsArray, delRow, delCol);
        }
    }
}

int solution(vector<vector<int>> grid, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    set<vector<pair<int, int>>> unique;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                vector<pair<int, int>> dfsArray;
                dfs(grid, vis, n, m, i, j, i, j, dfsArray, delRow, delCol);
                unique.insert(dfsArray);
            }
        }
    }

    return unique.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (auto &row : grid)
    {
        for (auto &cell : row)
        {
            cin >> cell;
        }
    }

    cout<<solution(grid, n, m);
    
    return 0;
}

/*
7 7
1 1 0 0 1 1 0
1 0 0 0 0 0 0
0 1 1 0 1 1 0
0 1 0 0 0 1 0
0 0 1 1 0 0 0
1 1 0 0 1 1 1
1 0 0 0 0 0 0
*/