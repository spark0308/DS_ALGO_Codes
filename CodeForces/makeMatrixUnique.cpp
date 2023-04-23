#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int n){
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int num = 1;
    for(int i=0; i<n; i+=2){
        for(int j=0; j<n; j+=2){
            matrix[i][j] = num;
            num++;
        }
    }

    for(int i=1; i<n; i+=2){
        for(int j=0; j<n; j+=2){
            matrix[i][j] = num;
            num++;
        }
    }

    for(int i=0; i<n; i+=2){
        for(int j=1; j<n; j+=2){
            matrix[i][j] = num;
            num++;
        }
    }

    for(int i=1; i<n; i+=2){
        for(int j=1; j<n; j+=2){
            matrix[i][j] = num;
            num++;
        }
    }

    return matrix;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<vector<int>> ans = solve(n);

        for(auto x: ans){
            for(auto y: x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
}