#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ns = 0, zs = 0;
    string letters;
    cin>>n;
    cin>>letters;

    for(auto x: letters){
        if(x == 'n') ns++;
        if(x == 'z') zs++;
    }

    for(int i=0; i<ns; i++) cout<<"1 ";
    for(int i=0; i<zs; i++) cout<<"0 ";
}