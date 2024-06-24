#include <bits/stdc++.h>
using namespace std;

long long solution(long long x, long long y, vector<long long> batsmen, vector<long long> bowlers){
    if(x<4 || y<4 || (x+y) < 11) return -1;

    sort(batsmen.begin(), batsmen.end(), greater<long long>());
    sort(bowlers.begin(), bowlers.end(), greater<long long>());

    long long ans = batsmen[0] + batsmen[1] + batsmen[2] + batsmen[3] + bowlers[0] + bowlers[1] + bowlers[2] + bowlers[3];

    // long long i = 4, j = 4;

    // for(long long p = 9; p<= 11; p++){
    //     if(i >= x){
    //         ans += bowlers[j];
    //         j++;
    //     }
    //     else if(j >= y){
    //         ans += batsmen[i];
    //         i++;
    //     }
    //     else{
    //         if(batsmen[i] > bowlers[j]){
    //             ans += batsmen[i];
    //             i++;
    //         }
    //         else if(bowlers[j] > batsmen[i]){
    //             ans += bowlers[j];
    //             j++;
    //         }
    //         else if(batsmen[i+1])
    //     }
    // }
    long long ans1=0, ans2=0, ans3=0, ans4=0;
    if(x - 4 >= 3) ans1 = batsmen[4] + batsmen[5] + batsmen[6];
    if(x - 4 >= 2 && y-4 >= 1) ans2 = batsmen[4] + batsmen[5] + bowlers[4];
    if(x - 4 >= 1 && y-4 >= 2) ans3 = batsmen[4] + bowlers[4] + bowlers[5];
    if(y - 4 >= 3) ans4 = bowlers[4] + bowlers[5] + bowlers[6];

    // cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;

    ans += max(ans1, max(ans2, max(ans3, ans4)));

    return ans;
}

int main() {
	// your code goes here
    long long t;
    cin>>t;
    while(t--){
        long long x, y;
        cin>>x>>y;

        vector<long long> batsmen(x);
        vector<long long> bowlers(y);

        for(long long i=0; i<x; i++) cin>>batsmen[i];
        for(long long i=0; i<y; i++) cin>>bowlers[i];

        cout<<solution(x, y, batsmen, bowlers)<<endl;
    }
}
