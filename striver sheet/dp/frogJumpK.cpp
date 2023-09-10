#include<bits/stdc++.h>
using namespace std;

int solution(int n, int k,vector<int> heights){
    int dp[n];

    dp[0] = 0;

    for(int i=1; i<n; i++){
        int temp = INT_MAX;

        for(int j=i-1; j>=i-k && j >=0; j--){
            temp = min(temp, (dp[j] + abs(heights[i] - heights[j])));
        }
        dp[i] = temp;
    }

    return dp[n-1];
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> heights(n);

    for(auto &x: heights){
        cin>>x;
    }

    cout<<solution(n, k, heights)<<endl;
}