#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>ans;
vector<int>maks;

void addEdge(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 1; v <= V; ++v) {
      cout << v << '=';
        for(auto x: adj[v]){
          cout << x << ' ';
        }
        cout << '\n';
        // cout << "\n Adjacency list of vertex " << v
        //      << "\n head ";
        // for (auto x : adj[v])
        //     cout << "-> " << x;
        // printf("\n");
    }
}

bool isInAns(int v) {
  for(auto i: ans){
    if(v == i) return true;
  }
  return false;
}

void dfs(vector<int> adj[],int idx, int V, vector<bool> vis){
  for(auto j: adj[idx]){ // mark all connected vertex
    if(!vis[j]){
      vis[j] = true; // visit all connected vertex
    }
  }
  bool found = false;
  for(int i = 1; i <= V; i++){
    if(!vis[i]){ // if not connected vertex found
      found = true;
      vis[i] = true;
      ans.push_back(i);
      dfs(adj,i,V, vis);
      ans.pop_back();
    }
  }
  if(!found){ // all vertex have been visited
    // sort(ans.begin(), ans.end());
    // for(auto a: ans){
    //   cout << a << ' ';
    // }
    // cout << '\n';
    if(ans.size() > maks.size()){
      maks = ans;
    }
    // else if(ans.size() == maks.size()){
    //   if(accumulate(ans.begin(),ans.end(),0) > accumulate(maks.begin(), maks.end(),0)){
    //     maks = ans;
    //   }
    // }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  int m; cin >> m;
  while(m--){
    int n,k; cin >> n >> k;
    vector<int> adj[n+1];
    for(int i = 0; i < k; i++){
      int u,v; cin >> u >> v;
      addEdge(adj,u,v);
    }
    for(int i = 1; i <= n; i++){
      vector<bool> vis((n+1),false);
      // cout << "i = " << i << '\n';
      ans.push_back(i);
      vis[i] = true;
      dfs(adj,i,n, vis);
      ans.pop_back();
    }
    cout << maks.size() << '\n' << maks[0];
    for(int i = 1; i < maks.size(); i++){
      cout << ' ' << maks[i];
    }
    cout << '\n';
    maks.clear();
    // printGraph(adj,n);
  }
  return 0;
}