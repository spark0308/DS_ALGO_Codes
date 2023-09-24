#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int solution(int n, int m, vector<vector<int>> mat){
    int dp[n][m];
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0) continue;
            else if(i == 0) dp[0][j] = dp[0][j-1];
            else if(j == 0) dp[i][0] = dp[i-1][0];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
        }
    }

    return dp[n-1][m-1]%MOD;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    cout<<solution(n, m, mat)<<endl;
    }
}