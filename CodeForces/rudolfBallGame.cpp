#include<bits/stdc++.h>
using namespace std;

void AllPosibility(int ind, int currentPlayer, set<int> &hasLastBall, int n, int m, int x, vector<pair<int, char>> passes){
    if(ind == (m)){
        hasLastBall.insert(currentPlayer);
        return;
    }

    int passValue = passes[ind].first%n;

    int nextClock = currentPlayer + passValue;
    nextClock = nextClock%n;
    if(nextClock == 0) nextClock = n;

    int nextAntiClock = n + currentPlayer - passValue;
    nextAntiClock = nextAntiClock%n;
    if(nextAntiClock == 0) nextAntiClock = n;

    if(passes[ind].second == '?'){
        AllPosibility(ind+1, nextClock, hasLastBall, n, m, x, passes);
        AllPosibility(ind+1, nextAntiClock, hasLastBall, n, m, x, passes);
    }
    else if(passes[ind].second == '0'){
        AllPosibility(ind+1, nextClock, hasLastBall, n, m, x, passes);
    }
    else{
        AllPosibility(ind+1, nextAntiClock, hasLastBall, n, m, x, passes);
    }
}

void AllPosibility(int ind, int currentPlayer, vector<int> &hasLastBall, int n, int m, int x, vector<pair<int, char>> passes){
    
}

vector<int> solution(int n, int m, int x, vector<pair<int, char>> passes){
    set<int> ans;
    vector<int> playersHasBall(n, 0);
    AllPosibility(0, x, ans, n, m, x, passes);

    vector<int> ret;
    for(auto x: ans) ret.push_back(x);
    return ret;
}

void printVector(vector<int> arr){
    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, m, x;
        cin>>n>>m>>x;

        vector<pair<int, char>> passes(m);

        for(int i=0; i<m; i++){
            int a;
            char b;
            cin>>a>>b;
            passes[i] = {a, b};
        }
        vector<int> ans = solution(n, m, x, passes);
        cout<<ans.size()<<endl;
        printVector(ans);

    }
    
}