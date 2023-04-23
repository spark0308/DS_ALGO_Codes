#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solution(ll n){

    if(n%2 == 0){
        cout<<"YES\n";
        for( ll i=0; i<n; i++){
            if(i%2 == 0)
                cout<<1<<" ";
            else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    else if(n == 3){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        ll x = n/2;
        for(ll i=0; i<n/2; i++){
            cout<<1-x<<" "<<x<<" ";
        }
        cout<<1-x<<endl;
    }
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;

        solution(n);
    }
    
}