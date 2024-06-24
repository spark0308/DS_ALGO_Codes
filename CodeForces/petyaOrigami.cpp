#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin>>n>>k;

    int red = ceil((float)(n*2)/(float)k);
    int green = ceil((float)(n*5)/(float)k);
    int blue = ceil((float)(n*8)/(float)k);

    cout<<(red + green + blue)<<endl;
}