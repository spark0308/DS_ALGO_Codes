#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

void sort012(vector<int> arr){
    int low, mid, high;
    low = mid = 0;
    high = arr.size() -1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    print(arr);
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(auto &x: arr){
        cin>>x;
    }

    sort012(arr);

}