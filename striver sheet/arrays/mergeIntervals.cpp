#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> intervals){
    for(auto x: intervals){
        cout<<"["<<x[0]<<","<<x[1]<<"], \n";
    }
}

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals, int n){
    sort(intervals.begin(), intervals.end());

    vector<int> interval = intervals[0];

    vector<vector<int>> mergedIntervals;

    for(int i=1; i<n; i++){
        if(intervals[i][0] <= interval[1]){
            interval[1] = max(interval[1], intervals[i][1]);
        }
        else{
            mergedIntervals.push_back(interval);
            interval = intervals[i];
        }
    }
    mergedIntervals.push_back(interval);
    return mergedIntervals;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n, vector<int>(2));

    for(auto &x: intervals){
        cin>>x[0]>>x[1];
    }

    print(mergeIntervals(intervals, n));
    return 0;
}