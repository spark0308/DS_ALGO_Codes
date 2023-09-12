#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    int dp[n];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], (nums[i] + dp[i-2]));
    }

    return dp[n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int number_of_houses;
    cin>>number_of_houses;

    vector<int> wealths(number_of_houses);

    for(auto &x : wealths){
        cin>>x;
    }

    cout<<solution(wealths)<<endl;
    }
}