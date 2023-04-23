#include<bits/stdc++.h>
using namespace std;

//Binary search to search a key in Two D Array;
void Search(vector<vector<int>> arr, int m, int n, int searchKey){
    int l = 0;
    int r = m*n;
    int mid = (l+r)/2;
    int prevMid = 0;

    //to calculate two D indices by mid;
    int i = mid/m;
    int j = mid%m;


    while(arr[i][j] != searchKey && prevMid != mid){
        if(searchKey > arr[i][j]){
            l = mid;
        }
        else{
            r = mid;
        }

        prevMid = mid;
        mid = (l+r)/2;
        i = mid/m;
        j = mid%m;
    }

    if(arr[i][j] == searchKey){
        cout<<"Key found.\n";
    }
    else{
        cout<<"Key not found. \n";
    }
}

int main(){
    int n, m, key;
    cin>>m>>n;

    vector<vector<int>> arr(n, vector<int>(m));

    for(auto &x: arr){
        for(auto &y: x){
            cin>>y;
        }
    }

    cin>>key;

    Search(arr, m, n, key);

    return 0;
}