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
            int front = 0;
            int back = nums.size() -1;
            vector<pair<int, int>> numIndicesPair;
            for(int i=0; i<nums.size(); i++){
                numIndicesPair.push_back({nums[i], i});
            }
            sort(numIndicesPair.begin(), numIndicesPair.end());
            while (front < back)
            {
                int sum = numIndicesPair[front].first+numIndicesPair[back].first;
                if(sum == target)
                {
                    return {numIndicesPair[front].second, numIndicesPair[back].second};
                }
                if(sum < target) front++;
                if(sum > target) back--;
                /* code */
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