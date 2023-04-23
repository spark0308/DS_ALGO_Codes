#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, a, b, t;
    cin>>t;
    while (t--)
    {
        cin>>n>>a>>b;

        ll evenEpis = n/2;
        ll oddEpis = n/2 + n%2;

        cout<<(evenEpis*a + oddEpis*b)<<endl;
    }
    }
    