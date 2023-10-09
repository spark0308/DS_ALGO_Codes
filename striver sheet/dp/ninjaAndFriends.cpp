#include<bits/stdc++.h>
using namespace std;

int solution(int r, int c, vector<vector<int>> grid){
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    for(int j1 = 0; j1<c; j1++){
        for(int j2 = 0; j2<c; j2++){
            if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                int maxi = INT_MIN;
                for(int d1=-1; d1<=1; d1++){
                    for(int d2=-1; d2<=1; d2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        if((j1 + d1 < 0 || j1 + d1 >= c) || (j2 + d2 < 0 || j2 + d2 >= c))
                            value += -1e9;
                        else
                            value += dp[i+1][j1+d1][j2+d2];
                        
                        maxi = max(value, maxi);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c-1];
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(auto &x: grid){
        for(auto &y: x){
            cin>>y;
        }
    }
}