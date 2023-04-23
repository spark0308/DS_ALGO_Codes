#include<bits/stdc++.h>
using namespace std;

bool check(int V, vector<int> adj[], vector<int> &color, int node){
    queue<int> q;
    q.push(node);
    color[node] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x: adj[node]){
            if(color[x] == -1){
                color[x] = !color[node];
                q.push(x);
            }
            else if(color[x] == color[node])
                return false;
        }
    } 
    return true;
}

bool isBipartite(int V, vector<int> adj[]){
    vector<int> color(V, -1);

    for(int i=1; i<=V; i++){
        if(color[i] == -1){
            if(!check(V, adj, color, i)) return false;
        }
    }

    return true;
}

int main(){
    int n, e;
    cin>>n>>e;

    vector<int> adj[n+1];

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto isit = isBipartite(n, adj);
    if(isit){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}