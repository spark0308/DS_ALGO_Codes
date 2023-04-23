#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, t;
    cin>>t;

    while (t--)
    {
        cin>>n;
        vector<ll> arr(n);

        for(auto &x: arr){
            cin>>x;
        }

        ll ans = 1;
        for(auto x: arr){
            ans *= x;
        }

        ans += (n-1);

        cout<<ans*2022<<endl;
    }
    
}

