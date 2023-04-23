#include<bits/stdc++.h>
using namespace std;

void permut(string ans, string remain, int n){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    for(int i = 0; i < n; i++){
        permut(ans + remain[i], remain.substr(0, i) + remain.substr(i+1), n-1);
    }
}

void permutation(string input){
    permut("", input, input.size());
}

int main(){
    string input;
    cin>>input;

    permutation(input);

    return 0;
}