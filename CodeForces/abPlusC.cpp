#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> solution(ll x){
    vector<ll> ans(3);
    if(x <= 1000000){
        ans[0] = 1;
        ans[2] = 1;
        ans[1] = x - 1;
    }
    else if(x%1000000 == 0){
        ans[0] = x/1000000;
        ans[1] = 1000000;
        ans[2] = 1000000;
    }
    else{
        ans[0]  = x/1000000;
        ans[1] = 1000000;
        ans[2] = 1000000;
    }

    return ans;
}

int main(){
    ll t;
    cin>>t;

    while (t--){
        ll x;
        cin>>x;

        if(x == 1) cout<<-1<<endl;
        else{
            vector<ll> ans = solution(x);

            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        }
    }
}