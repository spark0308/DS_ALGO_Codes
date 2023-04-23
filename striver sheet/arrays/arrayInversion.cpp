#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = start;
    int inv_count = 0;
    vector<int> temp(end +1);

    while( i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
            inv_count += 1;
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

    return inv_count;
}

int mergeSort(vector<int> &arr, int start, int end){
    int inv_count =0;
    if(start >= end)
        return inv_count;

    int mid = (start + end)/2;

    inv_count += mergeSort(arr, start, mid);
    inv_count += mergeSort(arr, mid+1, end);
    inv_count += merge(arr, start, mid, end);

    return inv_count;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(auto &x: arr){
        cin>>x;
    }

    //sorting algorithm;
    cout<<mergeSort(arr, 0, n-1)<<endl;

    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}