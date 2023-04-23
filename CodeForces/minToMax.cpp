#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(auto &x: arr){
            cin>>x;
        }

        map<int, int> mp;
        for(auto x: arr){
            mp[x]++;
        }

        cout<<n - mp.begin()->second<<endl;
    }
}