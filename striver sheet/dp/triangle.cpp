#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle, int n){
    int dp[n][n];

    for(int i=0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int downRight = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, downRight);
        }
    }

    return dp[0][0];
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> triangle(n, vector<int>(n));
    for(auto &x: triangle){
        for(auto &y: x){
            cin>>y;
        }
    }

}