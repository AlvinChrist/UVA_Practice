#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int cnt = 0;

void BFS(int arr[], int n, int p1[], int p2[], int c[], int m){
  queue<vector<int>> q;
  vector<int> v;
  q.push(v);
  while(q.size() > 0){
    vector<int> front = q.front();
    q.pop();
    if(front.size() == n){
      bool pass = m == 0;
      if(!pass) {
        for(int i = 0; i < m; i++){
          int p1_idx = -1;
          int p2_idx = -1;
          bool isMax = c[i] > 0;
          int constrain = abs(c[i]);

          for(int j = 0; j < n; j++){
            if(front[j] == p1[i]) p1_idx = j;
            else if(front[j] == p2[i]) p2_idx = j;
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
    }
    else{
      for(int i = 0; i < n; i++){
        bool exist = false;
        for(int j = 0; j < front.size(); j++){
          if(arr[i] == front[j]){
            exist = true;
            break;
          }
        }
        if(!exist){
          vector<int> y = front;
          y.push_back(arr[i]);
          q.push(y);
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  while(true){
    cin >> n >> m;
    if(n == 0) break;
    int p1[m] = {0};
    int p2[m] = {0};
    int c[m] = {0};
    for(int i = 0; i < m; i++){
      cin >> p1[i] >> p2[i] >> c[i];
    }
    int arr[8] = {0,1,2,3,4,5,6,7};
    BFS(arr,n,p1,p2,c,m);
    cout << cnt << '\n';
    cnt = 0;
  }
  return 0;
}