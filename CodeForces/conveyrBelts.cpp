#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mod(ll num){
    if(num < 0)
        return num * -1;
    
    return num;
}

ll minEnergy(ll n, ll x1, ll y1, ll x2, ll y2){
    ll belt1 = min(mod(x1 - 0), mod(x1 - n));
    belt1 = min(belt1, mod(y1 - 0));
    belt1 = min(belt1, mod(y1-n));

    ll belt2 = min(mod(x2 - 0), mod(x2 - n));
    belt2 = min(belt2, mod(y2 - 0));
    belt2 = min(belt2, mod(y2-n));

    return mod(belt1 - belt2);
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n, x1, x2, y1, y2;
        cin>>n>>x1>>y1>>x2>>y2;
        cout<<minEnergy(n-1, x1-1, y1-1, x2-1, y2-1)<<endl;
    }
    
}