#include<bits/stdc++.h>
using namespace std;

int tryAll(int i, int rodLeft, vector<int> price){
    if(i == 0) return rodLeft*price[0];

    int notCut = tryAll(i-1, rodLeft, price);
    int cut = 0;
    if(rodLeft >= (i+1)) cut = price[i] + tryAll(i, rodLeft-(i+1), price);

    return max(cut, notCut);
}

int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1));

    for(int i=0; i<n; i++) dp[0][i] = i*price[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=n; j++){
            int notCut = dp[i-1][j];
            int cut = 0;
            if(j >= (i+1)) cut = price[i] + dp[i][j-(i+1)];
            dp[i][j] = max(notCut, cut);
        }
    }

    return dp[n-1][n];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> arr(n);
        for(auto &x: arr) cin>>x;
    }
    
}