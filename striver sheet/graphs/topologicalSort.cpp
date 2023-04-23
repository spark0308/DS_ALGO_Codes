#include<bits/stdc++.h>
using namespace std;

void dfs(int V, vector<int> adj[], int node, int vis[], stack<int> &topoSeq){
    vis[node] = 1;
    //cout<<node<<" ";
    for(auto adjNode : adj[node]){
        if(vis[adjNode] == 0){
            dfs(V, adj, adjNode, vis, topoSeq);
        }
    }

    topoSeq.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
    int vis[V] = {0};
    stack<int> topoSeq;

    for(int i=0; i<V; i++){
        if(vis[i] == 0){
            dfs(V, adj, i, vis, topoSeq);
            //cout<<endl;
        }
    }

    vector<int> ans;
    while(!topoSeq.empty()){
        ans.push_back(topoSeq.top());
        topoSeq.pop();
    }
    return ans;
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

    // for(int i=0; i<n; i++){
    //     cout<<i<<" -> ";
    //     for(auto x: adj[i]){
    //         cout<<x<<", ";
    //     }
    //     cout<<endl;
    // }

    auto ans = topoSort(n, adj);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
}