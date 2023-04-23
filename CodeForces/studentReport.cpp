#include<bits/stdc++.h>
using namespace std;

struct  Result
{
    Result(): output1(){};
    int output1[10000];
};

Result Solution(int input1, int input2, vector<vector<int>> arr){
    vector<int> ans;
    Result r;

    int lowest = INT_MAX;
    int position;
    int avg = 0;

    for(int i=0; i<input2; i++){
        avg = 0;
        for(int j=0; j<input1; j++){
            avg = avg + arr[j][i];
        }
        if(avg < lowest){
            position = i;
            lowest = avg;
        }
    }

    for(int i=0; i<input1; i++){
        int sum = 0;
        for(int j=0; j<input2; j++){
            if(j == position)
                continue;
            
            sum = sum + arr[i][j];
        }
        ans.push_back(sum);
    }

    for(int i=0; i< ans.size(); i++){
        r.output1[i] = ans[i];
    }

    return r;
}

int main(){
    int n, m;
    cin>>n>>m;

    //vector<int> ans;

    Result ans;

    vector<vector<int>> marks(n, vector<int>(m));

    for(auto &x: marks){
        for(auto &y: x){
            cin>>y;
        }
    }
    ans = Solution(n, m, marks);
}