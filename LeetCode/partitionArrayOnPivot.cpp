#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> first;
        vector<int> middle;
        vector<int> last;

        for(int x: nums){
            if(x < pivot){
                first.push_back(x);
            }
            else if(x == pivot){
                middle.push_back(x);
            }
            else{
                last.push_back(x);
            }
        }

        for(int x: first) ans.push_back(x);
        for(int x: middle) ans.push_back(x);
        for(int x: last) ans.push_back(x);

        return ans;
    }
};

int main() {
    Solution sln = Solution();
}