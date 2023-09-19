#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> arr){
    int task1 = arr[0][0];
    int task2 = arr[0][1];
    int task3 = arr[0][2];
    int curr1 = 0;
    int curr2 = 0;
    int curr3 = 0;

    for(int i=1; i<n; i++){
        curr1 = arr[i][0] + max(task2, task3);
        curr2 = arr[i][1] + max(task1, task3);
        curr3 = arr[i][2] + max(task1, task2);

        task1 = curr1;
        task2 = curr2;
        task3 = curr3;
    }

    int ans = max(task1, task2);
    ans = max(ans, task3);

    return ans;
}

int main(){
    int n;
    vector<vector<int>> arr(n, vector<int>(3));

    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }


}