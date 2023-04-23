#include<bits/stdc++.h>
using namespace std;

bool dfs(int V, vector<int> adj[], vector<int> &vis, vector<int> pathVis, int node){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto adjNode: adj[node]){
        if(pathVis[adjNode] == 1) return true;

        if(vis[adjNode] == 0){
            if(dfs(V, adj, vis, pathVis, adjNode)) return true;
        }
    }

    return false;
}

bool detectCycle(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for(int i=0; i<V; i++){
        if(vis[i] == 0){
            if(dfs(V, adj, vis, pathVis, i)) return true;
        }
    }

    return false;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }

    cout<<detectCycle(n, adj)<<endl;
}