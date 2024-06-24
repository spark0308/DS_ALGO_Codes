#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int a, b, c, d, k;

        cin>>a>>b>>c>>d>>k;

        int pens = ceil((float)a/(float)c);
        int pencils = ceil((float)b/(float)d);

        if((pencils + pens) <= k) cout<<pens<<" "<<pencils<<endl;
        else cout<<-1<<endl;

    }
    
}