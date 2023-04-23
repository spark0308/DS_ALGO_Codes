#include<bits/stdc++.h>
using namespace std;

vector<int> isPossible(int N, int P, vector<vector<int>> &prerequisites)
{
    vector<int> adj[N];

    for(auto it: prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    int indegree[N] = {0};

    for(int i=0; i<N; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        /* code */
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(topo.size() == N) return topo;

    return {};
    
}

int main(){
    int N, P;
    cin>>N>>P;

    vector<vector<int>> prerequisites;

    for(int i=0; i<P; i++){
        int u, v;
        cin>>u>>v;

        prerequisites.push_back({u, v});
    }

    vector<int> ans = isPossible(N, P, prerequisites);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}