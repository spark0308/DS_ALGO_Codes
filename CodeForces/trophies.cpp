#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solution(ll n, string lamps){
    ll l = 0;
    ll r = 0;

    for(auto x: lamps){
        if(x == 'R')
            r++;
        else
            l++;
    }

    if(l == 0 || r == 0){
        return -1;
    }

    for(ll i = 0; i<n; i++){
        if(lamps[i] == 'L' && lamps[i+1] == 'R'){
            return i+1;
        }
    }

    return 0;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string lamps;
        cin>>lamps;

        cout<<solution(n, lamps)<<endl;

    }
}