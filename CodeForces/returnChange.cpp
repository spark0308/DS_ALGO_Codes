#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll x;
        cin >>x;

        int temp = x % 10;

        if(temp < 5){
            x = x - temp;
        }
        else{
            temp = 10 - temp;
            x = x + temp;
        }

        cout<<100 - x<<endl;
    }
    
}