//1358. Number of Substrings Containing All Three Characters
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int front = 0;
            int back = 1;
            int ans = 0;
            map<char, int> freq;
            int n = s.length();
            freq[s[front]]++;
            freq[s[back]]++;

            while((front<back)){
                if(freq['a']>0 && freq['b']>0 && freq['c']>0){
                    ans = ans + (n-(back+1)+1);
                    freq[s[front]]--;
                    front++;
                }
                else{
                    if(back<(n-1)){
                        back++;
                        freq[s[back]]++;
                    }
                    else{
                        freq[s[front]]--;
                        front++;
                    }
                }
            }

            return ans;
        }
};

int main() {
    Solution sln = Solution();
}