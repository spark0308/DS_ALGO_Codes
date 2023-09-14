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

int bestofTwo(vector<int> nums){
    vector<int> temp1, temp2;
    int n = nums.size();

    if(n == 1) return nums[0];

    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
    }

    return max(solution(temp1), solution(temp2));
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

    cout<<bestofTwo(wealths)<<endl;
    }
}