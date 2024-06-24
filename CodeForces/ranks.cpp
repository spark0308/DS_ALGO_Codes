#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int ans = 1;
    int tomMarks = 0;
    for(int i=0; i<4; i++){
        int temp;
        cin>>temp;
        tomMarks+=temp;
    }

    for(int i=1; i<n; i++){
        int temp;
        int sum = 0;
        for(int j=0; j<4; j++){
            cin>>temp;
            sum += temp;
        }
        if(tomMarks < sum) ans++;
    }

    cout << ans << endl;


}