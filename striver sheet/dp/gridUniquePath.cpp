#include<bits/stdc++.h>
using namespace std;

int solution(int n, int m){
    int dp[n][m];
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;
            else if(i == 0) dp[0][j] = dp[0][j-1];
            else if(j == 0) dp[i][0] = dp[i-1][0];
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    return dp[n-1][m-1];
}

int main(){
    int n, m;
    cin>>n>>m;

    cout<<solution(n, m)<<endl;
}