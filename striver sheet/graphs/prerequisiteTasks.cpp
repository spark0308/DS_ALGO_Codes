#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[N];

    for(auto it: prerequisites)
    {
        adj[it.first].push_back(it.second);
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

    if(topo.size() == N) return true;

    return false;
    
}

int main(){
    int N, P;
    cin>>N>>P;

    vector<pair<int, int>> prerequisites;

    for(int i=0; i<P; i++){
        int u, v;
        cin>>u>>v;

        prerequisites.push_back({u, v});
    }

    bool ans = isPossible(N, prerequisites);
    cout<<ans<<endl;
    if(ans) cout<<"Yes\n";
    else cout << "No\n";
}