#include<bits/stdc++.h>
using namespace std;

int selectItems(int i, int weightLeft, int n, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
    if(i == 0 && weightLeft >= weight[0]) return value[0];
    if(i == 0) return 0;

    if(dp[i][weightLeft] != -1) return dp[i][weightLeft];

    int notTake = selectItems(i-1, weightLeft, n, weight, value, dp);
    int take = 0;
    if(weightLeft > weight[i]) take = value[i] + selectItems(i-1, weightLeft - weight[i], n, weight, value, dp);

    return dp[i][weightLeft] = max(notTake, take);  
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

    for(int i=weight[0]; i<=maxWeight; i++){
        dp[0][i] = value[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=maxWeight; j++){
            int notTake = dp[i-1][j];
            int take = INT_MIN;
            if(j >= weight[i]) take = value[i] + dp[i-1][j-weight[i]];
            dp[i][j] = max(notTake, take);
        }
    }

    return dp[n-1][maxWeight];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, w;
        cin>>n;
        vector<int> weights(n);
        vector<int> values(n);

        for(auto &x: weights){
            cin>>x;
        }
        for(auto &x: values){
            cin>>x;
        }
        cin>> w;

        cout<<"ans - "<<knapsack(weights, values, n, w)<<endl;;
    }
}