#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = start;
    vector<int> temp(end +1);

    while( i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        while(j <= end){
            temp[k] = arr[j];
            k++; j++;
        }
    }
    else {
        while ( i<= mid )
        {
            temp[k] = arr[i];
            k++; i++;
        }
        
    }

    for(int i=start; i<=end; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    if(start >= end)
        return;

    int mid = (start + end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(auto &x: arr){
        cin>>x;
    }

    //sorting algorithm;
    mergeSort(arr, 0, n-1);

    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}