#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll calXOR(ll num1, char num2){
    if(num2 == '1' && num1 == 1) return 0;
    if(num2 == '1' && num1 == 0) return 1;
    if(num2 == '0' && num1 == 1) return 1;
    if(num2 == '0' && num1 == 0) return 0;
}

ll solution(ll n, string s){
    ll count1 = 1;
    ll count2 = 0;

    ll xor1 = 1;
    ll xor2 = 0;

    for(int i=0; i< n-1; i++){
        xor1 = calXOR(xor1, s[i]);
        xor2 = calXOR(xor2, s[i]);
        //cout<<xor1<<" "<<xor2<<endl;
        count1 += xor1;
        count2 += xor2;
    }

    return max(count1, count2);
}
int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        string s;

        cin>>n;
        cin>>s;
        cout<<solution(n, s)<<endl;
    }

    
}