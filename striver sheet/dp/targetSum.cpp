#include<bits/stdc++.h>
using namespace std;

int targetSum(int n, int target, vector<int> arr){
    int sum = 0;
    for(auto x: arr) sum += x;

    int temp = sum - target;
    if((temp) % 2 != 0) return 0;
    int k = (temp)/2;

    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j >= arr[i]) take = dp[i-1][j-arr[i]];

            dp[i][j] = notTake + take;
        }
    }

    return dp[n-1][k];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, target;
        cin>>n>>target;

        vector<int> arr(n);

        for(auto &x: arr) cin>>x;

        // cout<<n<<" "<<target<<endl;
        // for(auto x: arr) cout<<x<<" ";
        // cout<<endl;

        cout<<targetSum(n, target, arr)<<endl;
    }
    
}