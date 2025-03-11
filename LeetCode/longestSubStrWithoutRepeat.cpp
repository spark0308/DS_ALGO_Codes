//3. Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s){
        int front = 0;
        int back = 0;
        int n = s.length();
        if(n == 0) return 0;
        int ans = 0;
        vector<int> freqArr(96);
        freqArr[s[front]-' '] = 1;
        while (back<n)
        {
            if(freqArr[s[back]-' '] > 1){
                freqArr[s[front]-' ']--;
                front++;
            }
            else{
                back++;
                if(back<n) freqArr[s[back]-' ']++;
                ans = max(ans, back-front);
            }
        }
        return ans;
    }
};

int main() {
    Solution sln = Solution();
    string s;
    cin>>s;
    cout<<sln.lengthOfLongestSubstring(s)<<endl;
}