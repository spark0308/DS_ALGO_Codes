#include<bits/stdc++.h>
using namespace std;

#define  ll long long

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;

        while(n){
            int temp = n%10;
            if(temp == 7){
                cout<<"YES\n";
                break;
            }
            n /= 10;
        }

        if(n == 0){
            cout<<"NO\n";
        }
    }
    
}