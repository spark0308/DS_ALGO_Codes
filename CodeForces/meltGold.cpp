#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll x,y;

        cin>>x>>y;

        ll s = x - y;

        ll ans = ceil(((sqrt(8*s + 1) - 1)/2));
        cout<<ans<<endl;
    }
    
}