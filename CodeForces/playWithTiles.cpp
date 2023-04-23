#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1000000007;

ll wayToPutTiles(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    ll dp[n+1][3];

    //dp[i][0] -- tiles filed upto i with both rows filled;
    //dp[i][1] -- tiles filed upto i with upper rows filled;
    //dp[i][2] -- tiles filed upto i with bottom rows filled;

    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for(int i =3; i<= n; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-2][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-2][0] + dp[i-1][1]) % MOD;
    }

    return dp[n][0];
}

int main(){
    int t,n;
    cin>>t;

    while (t--)
    {
        cin>>n;

        vector<vector<int>> dp(2, vector<int>(n, -1));
        cout<<wayToPutTiles(n)<<endl;
    }
    
}


/*
Test Cases:
Input                   Outut
public:
3
1                       1
2                       2
4                       11

private:
5
50                      451995198
35                      29460134
52                      108041490
59                      119370057
65                      26208334

8
99                      337638801
100                     190242381
150                     773955023
200                     627399438
250                     872044590
280                     19408435
300                     768506587
350                     500798594

20
500                     603582422
550                     727269359
559                     45061181
600                     771568221
666                     208871016
696                     342425475
699                     939053561
700                     637136622
717                     328336450
765                     959933779
777                     747701526
800                     177362789
818                     367514752
834                     709495102
890                     332353729
900                     422258822
911                     833350453
945                     765583862
970                     611348902
1000                    979232805

*/