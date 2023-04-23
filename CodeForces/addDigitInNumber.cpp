#include<bits/stdc++.h>
using namespace std;

#define ll long long

string solution(string number, ll n, char digit){
    string ans = "";
    bool added = false;
    for(auto x: number){
        if(x < digit && !added){
            ans += digit;
            ans += x;
            added = true;
        }
        else{
            ans += x;
        }
    }

    if(!added) ans += digit;

    return ans;
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        char digit;
        string number;
        cin>>n>>digit;
        cin>>number;

        cout<<solution(number, n, digit)<<endl;
    }
    
}