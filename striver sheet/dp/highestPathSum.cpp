#include<bits/stdc++.h>
using namespace std;

int GetMaxPathSum(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int dp[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0){
                dp[i][j] = matrix[i][j];
            }
            else{
                int topLeft = matrix[i][j];
                int top = dp[i-1][j] + matrix[i][j];
                int topRight = matrix[i][j];

                if(j != 0) topLeft += dp[i-1][j-1];
                if(j != m-1) topRight += dp[i-1][j+1];
                
                dp[i][j] = top;
                if(j != 0) dp[i][j] = max(dp[i][j], topLeft);
                if(j != m-1) dp[i][j] = max(dp[i][j], topRight);
            }

        }
    }

    int ans = INT_MIN;

    for(int i=0; i<m; i++){
        if(ans < dp[n-1][i]) ans = dp[n-1][i];
    }
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> matrix(n, vector<int>(m));

        for(auto &row: matrix){
            for(auto &col: row){
                cin>>col;
            }
        }

        cout<<GetMaxPathSum(matrix)<<endl;

    }
}