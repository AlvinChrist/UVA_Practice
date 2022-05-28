#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,bool> m;
map<int,bool>::iterator it;
int t,p,n;

bool dfs(int bars[], int p, vector<int> cache, int target){
  it = m.find(target);
  if(it != m.end()){
    return it->second;
  }
  if(target == 0) return true;
  else if(target < 0 || cache.size() == p){
    return false;
  }
  for(int i = 0; i < p; i++){
    bool exist = false;
    for(int j = 0; j < cache.size(); j++){
      if(i == cache[j]){
        exist = true;
        break;
      }
    }
    if(!exist){
      cache.push_back(i);
      if(dfs(bars,p,cache,target - bars[i])) {
        m.insert(pair<int,bool>(target, true));
        return true;
      }
      m.insert(pair<int,bool>(target, false));
      cache.pop_back();
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while(t--){
    cin >> n >> p;
    int bars[p] = {0};
    for(int i = 0; i < p; i++){
      cin >> bars[i];
    }
    if(n == 0 || p == 0) {
      cout << "YES\n";
      continue;
    }
    bool found = false;
    for(int i = 0; i < p; i++){
      vector<int> cache;
      cache.push_back(i);
      if(dfs(bars,p,cache,n - bars[i])){
        cout << "YES\n";
        found = true;
        break;
      }
    }
    if(!found) cout << "NO\n";
    m.clear();
  }
  return 0;
}