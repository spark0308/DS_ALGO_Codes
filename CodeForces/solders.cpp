#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int count = 0;
    cin>>n;
    vector<vector<int>> soldiers(n, vector<int>(2));

    for(auto &x: soldiers){
        cin>>x[0]>>x[1];
    }

    vector<int> row(8, 0), col(8, 0);

    for(auto x: soldiers){
        row[x[0]] = 1;
        col[x[1]] = 1;
    }

    for(int i = 0; i< 8; i++){
        for(int j = 0; j< 8; j++){
            if(row[i] == 1 || col[j] == 1){
                count++;
            }
        }
    }

    cout<<count<<endl;
}