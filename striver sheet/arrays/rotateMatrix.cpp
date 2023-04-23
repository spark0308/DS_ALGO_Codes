#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> array){
    for(auto x: array){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void TransposeMatrix(vector<vector<int>> &matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseArray(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<=n/2; i++){
        swap(arr[i], arr[n-1-i]);
    }
}

void reverseMatrix(vector<vector<int>> &matrix, int n){
    for(auto &x: matrix){
        reverseArray(x);
    }
}

void RotateMatrix(vector<vector<int>> &matrix, int n){
    TransposeMatrix(matrix, n);
    reverseMatrix(matrix, n);
    cout<<"90 degree Rotated matrix"<<endl;
    cout<<" |\n V\n"<<endl;
    print(matrix);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for(auto &x: matrix){
        for (auto &y: x){
            cin>>y;
        }
    }

    RotateMatrix(matrix, n);

    return 0;

}