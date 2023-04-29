#include<bits/stdc++.h>
using namespace std;


vector<char> alienOrder(int n, int k, string arr[]){
    char alphas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    vector<int> adj[26];
    int indegree[26] = {0};
    int added[k] = {0};

    for(int i=0; i<n-1; i++){
        for(int j=0; j<min(arr[i].size(), arr[i+1].size()); j++){
            if(arr[i][j] != arr[i+1][j]){
                int u, v;
                u = arr[i][j]%'a';
                v = arr[i+1][j]%'a';
                indegree[v]++;
                adj[u].push_back(v);
                break;
            }
        }
    }

    queue<int> q;
    vector<int> topo;
    for(int i=0; i<26; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node < k){
            topo.push_back(node);
            added[node] = 1;
        }
        count++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(count < 26) return {};
    
    for(int i=0; i<k; i++){
        if(added[i] == 0){
            topo.push_back(i);
        }
    }

    vector<char> ans;

    for(auto it: topo){
        ans.push_back(alphas[it]);
    }

    return ans;
}

int main(){
    int n, k;

    cin>>n>>k;
    string arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<char> ans = alienOrder(n, k, arr);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

}