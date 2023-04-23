#include<bits/stdc++.h>
using namespace std;
 
 #define ll long long

 string solution(ll n, vector<int> arr){
    sort(arr.begin(), arr.end());
    map<int, int> mp;

    for(auto x: arr){
        mp[x]++;
    }

    ll a = arr[n-1], b = arr[n-2];

    if(a == b){
        ll count = (n+1)/2;
        return (mp[a] <= count) ? "YES" : "NO";
    }
    return (mp[b] < n-1) ? "YES" : "NO";
 }

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<int> arr(n);
        for(auto &x: arr){
            cin>>x;
        }

        cout<<solution(n, arr)<<endl;

    }
    
}