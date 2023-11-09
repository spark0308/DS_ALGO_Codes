#include<bits/stdc++.h>
using namespace std;
bool subSetSum(int n, int k, vector<int> arr, int i, vector<vector<int>> &dp){
    if(k == 0){ 
        return true;
    }
    if(i == 0){
        return (arr[0] == k);
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }
    bool notTake = subSetSum(n, k, arr, i-1, dp);
    bool take  = false;
    if(k >= arr[i]) take = subSetSum(n, k-arr[i], arr, i-1, dp);
    
    return dp[i][k] = notTake || take;
}

bool subSetExists(int n, int k, vector<int> arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool notTake = dp[i-1][j];
            bool take  = false;
            if(j >= arr[i]) take = dp[i-1][j-arr[i]];
            dp[i][j] = notTake || take;
        }
    }

    return dp[n-1][k];
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n, k;

        cin>>n>>k;
        vector<int> arr(n);

        for(auto &x: arr){
            cin>>x;
        }

        cout<<subSetExists(n, k, arr)<<endl;
    }
}