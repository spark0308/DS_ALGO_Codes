#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
    vis[node] = 1;

    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges){
    vector<pair<int, int>> adj[N];
    for(int i=0; i<N; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    int vis[N] = {0};
    stack<int> st;

    for(int i=0; i<N; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N);

    for(int i=0; i<N; i++) dist[i] = 1e9;

    dist[0] = 0;
    while (!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    for(int i=0; i<N; i++){
        if(dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges;

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u, v, w});
    }

    auto ans = shortestPath(n, m, edges);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}