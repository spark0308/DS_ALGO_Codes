//1780. Check if Number is a Sum of Powers of Three
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int powerOfThrees = 1;
            for(int i=1; i<=16; i++){
                powerOfThrees = 3*powerOfThrees;
            }
            cout<<powerOfThrees<<endl;
            while(powerOfThrees > 0){
                if(n==0) return true;
                if(n>=powerOfThrees) n-=powerOfThrees;
                powerOfThrees/=3;
            }
            cout<<powerOfThrees<<endl;
            if(n == 0) return true;
            return false;
        }
};

int main() {
    Solution sln = Solution();
    int n;
    cin>>n;
    cout<<sln.checkPowersOfThree(n)<<endl;
}