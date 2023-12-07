#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int x, int n, vector<int> num){
    if(i == 0){
        if(x%num[0] == 0) return x/num[0];
        else return 1e9;
    }

    int notTake = recursion(i-1, x, n, num);
    int take = INT_MAX;
    if(x >= num[i]) take = 1 + recursion(i, x-num[i], n, num);

    return min(take, notTake);
}

int minimumElements(vector<int> num, int x){
    int n = num.size();
    //return recursion(n-1, x, n, num);
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    for(int i=0; i<x+1; i++){
        if(i%num[0] == 0) dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<=x; j++){
            int notTake = dp[i-1][j];
            int take = INT_MAX;
            if(j >= num[i]) take = 1 + dp[i][j-num[i]];
            dp[i][j] = min(notTake, take);
        }
    }

    int ans = dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, x;
        cin>>n>>x;

        vector<int> coins(n);

        for(int i=0; i<n; i++){
            cin>>coins[i];
        }

        cout<<minimumElements(coins, x)<<endl;
    }
    
}