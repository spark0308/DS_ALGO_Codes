#include<bits/stdc++.h>
using namespace std;

long exploreWays(int i, int value, int *denominations, int n){
    if(i == 0){
        if(value%denominations[0] == 0) return 1;
        else return 0;
    }

    long notTake = exploreWays(i-1, value, denominations, n);
    long take = 0;
    if(value >= denominations[i]) take = exploreWays(i, value-denominations[i], denominations, n);

    return take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //return exploreWays(n-1, value, denominations, n);

    vector<vector<long>> dp(n, vector<long>(value+1));

    for(int i=0; i<=value; i++){
        if(i%denominations[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=value; j++){
            long notTake = dp[i-1][j];
            long take = 0;
            if(j >= denominations[i]) take = dp[i][j-denominations[i]];

            dp[i][j] = notTake+take;
        }
    }

    return dp[n-1][value];
}

int main(){

    #pragma region GetInputs
    int n, v;
    cin>>n;
    int *coins = new int[n];

    for(int i=0; i<n; i++) cin>>coins[i];
    cin>>v;
    #pragma endregion GetInputs

    cout << countWaysToMakeChange(coins, n, v);

    return 0;
}