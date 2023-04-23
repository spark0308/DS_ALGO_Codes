#include<bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> solution(ll n, ll A[], ll Adash[]){
    ll l, r, templ, tempr, count, highestCount;
    l = r = templ = tempr = count = highestCount = 0;

    for(int i=1; i<n; i++){
        if(Adash[i] >= Adash[i-1]){
            count++;
            tempr++;
        }
        else if(count > highestCount){
            l = templ;
            r = tempr;
            highestCount = count;
        }

        if(Adash[i] < Adash[i-1]){
            templ = tempr = i;
            count = 0;
        }
    }

    if(count > highestCount){
        l = templ;
        r = tempr;
        highestCount = count;
    }

    return {l+1, r+1};
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        /* code */
        ll n;
        cin>>n;
        ll A[n], Adash[n];
        
        for(ll i=0; i<n; i++)
            cin>>A[i];

        for(ll i=0; i<n; i++)
            cin>>Adash[i];

        pair<ll, ll> ans = solution(n, A, Adash);

        cout<<ans.first<<" "<<ans.second<<endl;
    }
    
}