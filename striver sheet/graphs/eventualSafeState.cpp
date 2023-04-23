#include<bits/stdc++.h>
using namespace std;

bool dfs(int V, vector<int> adj[], int vis[], int pathVis[], int check[], int node){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto adjNode: adj[node]){
        if(pathVis[adjNode] == 1) return true;

        if(vis[adjNode] == 0){
            if(dfs(V, adj, vis, pathVis, check, adjNode)) return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> detectCycle(int V, vector<int> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeState;

    for(int i=0; i<V; i++){
        if(vis[i] == 0){
            dfs(V, adj, vis, pathVis, check, i);
        }
    }

    for(int i=0; i<V; i++){
        if(check[i] == 1) safeState.push_back(i);
    }
    return safeState;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    auto ans = detectCycle(n, adj);

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}