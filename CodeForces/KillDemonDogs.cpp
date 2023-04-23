#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll maxKills(vector<vector<ll>> grid, ll n){
    vector<vector<ll>> dp(n, vector<ll>(n));

    dp[0][0] = grid[0][0];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                continue;
            else if(i == 0)
                dp[i][j] = grid[i][j] + grid[i][j-1];
            else if(j == 0)
                dp[i][j] = grid[i][j] + grid[i-1][j];
            else{
                dp[i][j] = grid[i][j] + max(grid[i][j-1], grid[i-1][j]);
            }
        }
    }

    cout<<dp[n-1][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> grid(n, vector<ll>(n));

        for(auto &row: grid){
            for(auto &cell: row){
                cin>>cell;
            }
        }

        //solution;
        ll ans = maxKills(grid, n);

        return 0;
    }
}