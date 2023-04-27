#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;

    while (t--)
    {
        ll x, y;
        cin>>x>>y;

        ll lhs = x + 2*(y/x);
        lhs = lhs*lhs;
        ll rhs = 8 * y;

        if(lhs == rhs) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
}