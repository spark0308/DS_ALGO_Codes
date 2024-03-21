#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string stays;

    cin>>n;
    cin>>stays;
    int s2f = 0;
    int f2s = 0;

    for(int i=0; i<n-1; i++){
        if(stays[i] == 'S' && stays[i+1] == 'F') s2f++;
        if(stays[i] == 'F' && stays[i+1] == 'S') f2s++;
    }

    if(s2f != 0 && (s2f > f2s)) cout<<"YES";
    else cout<<"NO";
}