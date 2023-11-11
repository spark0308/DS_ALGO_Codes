#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int calculateSubsets(int i, int k, int n, vector<int> arr){
    if(k == 0) return 1;
    if(i == 0) return (k == arr[0])?1:0;

    int notTake = calculateSubsets(i-1, k, n, arr);
    int take = 0;
    if(k >= arr[i]) take = calculateSubsets(i-1, k-arr[i], n, arr);
    
    return (take + notTake);
}

int findWays(vector<int> arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j >= arr[i]) take = dp[i-1][j-arr[i]];
            dp[i][j] = (notTake + take)%MOD;
        }
    }

    return dp[n-1][k]%MOD;
}

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);

    for(auto &x: arr){
        cin>>x;
    }

    cout<<findWays(arr, k)<<endl;

    return 0;
}