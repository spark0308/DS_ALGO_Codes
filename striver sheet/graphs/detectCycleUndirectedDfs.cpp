#include<bits/stdc++.h>
using namespace std;

bool detect(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;

    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            if(detect(adjNode, node, adj, vis) == true)
                return true;
        }
        else{
            if(adjNode != parent)
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V] = {0};

    for(int i=0; i<V; i++){
        if(vis[i] != 1){
            if(detect(i, -1, adj, vis)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> arr[n];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    cout << isCycle(n, arr)<<endl;
}