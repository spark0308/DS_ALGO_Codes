#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums){
            int n = nums.size();
            vector<int> ans;
            for(int i=0; i<n-1; i++)
            {
                if(nums[i] == nums[i+1])
                {
                    nums[i]*=2;
                    nums[i+1] = 0;
                }
            }

            for(int i=0; i<n; i++){
                if(nums[i] != 0) ans.push_back(nums[i]);
            }

            while (ans.size() != n)
            {
                ans.push_back(0);
            }
            

            return ans;
        }
};

int main(){
    Solution obj = Solution();
    int n;
    cin>>n;
    vector<int> nums = vector<int>(n);

    for(auto &x: nums) cin>>x;

    vector<int> ans = obj.applyOperations(nums);

    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}