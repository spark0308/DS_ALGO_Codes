//1. Two Sum
#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Input {
    public:
        static T singleInput()
        {
            cin>>T;
            return T;
        }
};

class Ouptut {

};

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(nums[i]+nums[j] == target) return {i, j};
                }
            }

            return {-1, -1};
        }
};

int main() {
    Solution sln = Solution();
    
    int n, target;
    cin>>n;
    vector<int> arr = vector<int>(n);

    for(auto &x: arr) cin>>x;
    cin>>target;

}