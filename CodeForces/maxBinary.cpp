#include<bits/stdc++.h>
using namespace std;

#define ll long long

string solution(int n, int k, string binary){
    ll bal = k;
    if(binary[0] == '0'){
        bal = k-1;
    }

    binary = '1' + binary.substr(1, n-1);

    for(int i=0; i<bal; i++){
        binary += '0';
    }

    return binary;
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n, k;
        string binary;
        cin>>n>>k;
        cin>>binary;
        cout<<solution(n, k, binary)<<endl;
    }
    
}