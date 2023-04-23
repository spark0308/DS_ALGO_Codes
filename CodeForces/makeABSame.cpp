#include<bits/stdc++.h>
using namespace std;

#define ll long long

string solution(ll n, vector<int> A, vector<int> B){
    bool a = false, b = false;

    if(A[0] != B[0] || A[n-1] != B[n-1] ){
        return "NO\n";
    }

    for(ll i=0; i<n; i++){
        if(A[i] == 1 && B[i] == 0)
            return "NO\n";
        if(A[i] == 1)
            a = true;
        if(B[i] == 1)
            b = true;
    }

    for(ll i=1; i< n-1; i++){
        if(A[i] != B[i] && A[i] == 0 && !a){
            return "NO\n";
        }
    }

    return "YES\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        vector<int> A(n), B(n);
        for(auto &x: A){
            cin>>x;
        }
        for(auto &x: B){
            cin>>x;
        }

        cout<<solution(n, A, B);
    }
}