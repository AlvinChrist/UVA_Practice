#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

void DFS(int arr[], int n, int level, int cache[], int p1[], int p2[], int c[], int m) {
  if(level == n) {
    bool pass = m == 0;
    if(!pass) {
      for(int i = 0; i < m; i++){
        int p1_idx = -1;
        int p2_idx = -1;
        bool isMax = c[i] > 0;
        int constrain = abs(c[i]);
        for(int j = 0; j < level; j++){
          if(cache[j] == p1[i]) p1_idx = j;
          else if(cache[j] == p2[i]) p2_idx = j;
          if(p1_idx >= 0 && p2_idx >= 0) break;
        }
        int delta = abs(p1_idx - p2_idx);
        if(isMax && delta <= constrain || !isMax && delta >= constrain) pass = true;
        else{
          pass = false;
          break;
        }
      }
    }
    if(pass) cnt++;
    return;
  }
  for(int i = 0; i < n; i++){
    if(level == 0){
      cache[level] = arr[i];
      DFS(arr,n,level+1,cache, p1, p2, c, m);
    }
    else{
      bool exist = false;
      for(int j = 0; j < level;j++){
        if(arr[i] == cache[j]){
          exist = true;
          break;
        }
      }
      if(!exist){
        cache[level]=arr[i];
        DFS(arr,n,level+1,cache, p1, p2, c, m);
      }
    }
  }
} 

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  while(true) {
    cin >> n >> m;
    if(n == 0) break;
    int cache[n] = {0};
    int arr[8] = {0,1,2,3,4,5,6,7};
    int p1[m] = {0};
    int p2[m] = {0};
    int c[m] = {0};
    for(int i = 0; i < m; i++){
      cin >> p1[i];
      cin >> p2[i];
      cin >> c[i];
    }
    DFS(arr,n,0,cache,p1,p2,c,m);
    cout << cnt << '\n';
    cnt = 0;
  }
  return 0;
}