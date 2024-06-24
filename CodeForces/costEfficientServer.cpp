/*
Problem Statement:
You have a paid server and a free server and n tasks. 
You are given array of costs where cost[i] is a cost and takes time[i] units of time to run ith task.
You can run task on free server only if paid server is occupied. It takes 1 unit of time to run any 
task on free server.
Find minimum cost to run all the n tasks.
*/

#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int freeTimeLeft,int n, vector<int> cost, vector<int> time){
    if(i == 0){
        if(freeTimeLeft >= time[0]) return 1;
        else return cost[0];
    }

    int paidServer = cost[i] + recursion(i-1, freeTimeLeft + time[i] ,n, cost, time);
    int unPaidServer = 10e9;
    if(freeTimeLeft > 0) unPaidServer = recursion(i-1, freeTimeLeft-1, n, cost, time);

    return min(paidServer, unPaidServer);
}

int dp(int n, vector<int> cost, vector<int> time){
    int maxTime = *max_element(time.begin(), time.end());
    vector<vector<int>> dp(n, vector<int>(maxTime+1));

    for(int i=1; i<=maxTime; i++){
        if(i >= time[0]) dp[0][i] = 1;
        else dp[0][i] = cost[0];
    }


    for(int i=1; i<n; i++){
        
    }
}

int minimumCost(vector<int> cost, vector<int> time){
    int n = cost.size();
    return recursion(n-1, 0, n, cost, time);
}

int main(){
    int n;
    cin>>n;

    vector<int> cost(n);
    vector<int> time(n);

    for(auto &x : cost) cin>>x;
    for(auto &x : time) cin>>x;

    cout<<minimumCost(cost, time)<<endl;
}