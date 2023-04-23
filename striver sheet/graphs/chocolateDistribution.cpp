#include<bits/stdc++.h>
using namespace std;

bool dfs(int V, vector<pair<int, int>> adj[], int vis[], int pathVis[], int check[], int node){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto adjNode: adj[node]){
        if(pathVis[adjNode.first] == 1) return true;

        if(vis[adjNode.first] == 0){
            if(dfs(V, adj, vis, pathVis, check, adjNode.first)) return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> findGreedyFriends(int V, vector<pair<int, int>> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> unSafeState;

    for(int i=0; i<V; i++){
        if(vis[i] == 0){
            dfs(V, adj, vis, pathVis, check, i);
        }
    }

    for(int i=0; i<V; i++){
        if(check[i] == 0) unSafeState.push_back(i);
    }
    return unSafeState;
}

void findNoOfChocolates(int N, int frnd, vector<pair<int, int>> wishlist[], int chocolates[]){
    if(wishlist[frnd].size() == 0){
        chocolates[frnd] = 1;
        return;
    }

    for(auto x: wishlist[frnd]){
        if(chocolates[x.first] != -1){
            chocolates[frnd] = max(chocolates[frnd], chocolates[x.first]+x.second);
        }
        else{
            findNoOfChocolates(N, x.first, wishlist, chocolates);
            chocolates[frnd] = max(chocolates[frnd], chocolates[x.first]+x.second);
        }
    }
}

int main(){
    int N, M;
    cin>>N>>M;

    vector<pair<int, int>> wishlist[N];

    for(int i=0; i<M; i++){
        int x, y, m;
        cin>>x>>y>>m;
        wishlist[x-1].push_back({y-1, m});
    }

    int chocolates[N];
    
    vector<int> greedyFriends = findGreedyFriends(N, wishlist);

    fill(chocolates, chocolates+N, -1);

    for(auto x: greedyFriends){
        chocolates[x] = 0;
    }

    for(int i=0; i<N; i++){
        if(chocolates[i] == -1){
            findNoOfChocolates(N, i, wishlist, chocolates);
        }
    }

    int ans = 0;
    for(auto x: chocolates){
        ans += x;
    }

    cout<<ans<<endl;
}

/*
15 12
1 2 1
4 5 2
5 6 2
6 8 3
7 6 1
8 5 6
5 9 2
9 10 4
10 11 8
11 6 7
12 6 5
13 12 11


output: 6
*/