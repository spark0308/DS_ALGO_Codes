#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1));

    for(int i=0; i<=w; i++){
        dp[0][i] = profit[0] * (i/weight[0]);
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            int notTake = dp[i-1][j];
            int take = INT_MIN;
            if(j >= weight[i]) take = profit[i] + dp[i][j - weight[i]];

            dp[i][j] = max(notTake, take);
        }
    }

    return dp[n-1][w];
}

int main(){

    #pragma region GetInputs
    int n, w;
    cin>>n>>w;

    vector<int> profit(n), weight(n);

    for(int i=0; i<n; i++){
        cin>>profit[i];
    }

    for(int i=0; i<n; i++){
        cin>>weight[i];
    }

    #pragma endregion GetInputs

    cout<<unboundedKnapsack(n, w, profit, weight);
    return 0;
}