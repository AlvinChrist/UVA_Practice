#include <iostream>
using namespace std;

int ans[25][1005];
int bars[25];
int t,n,p;

bool dp(int ind, int acc){
  if(acc == n){
    return true;
  }
  else if(acc > n || ind == p){ // jika akumulasi panjang > target atau index > total bars
    return false;
  }
  if(ans[ind][acc] != -1){ // jikalau ans[ind][acc] sudah pernah diakses
    return ans[ind][acc];
  }
  
  bool poss = false;
  for(int i = ind; i < p; i++){
    poss = dp(i + 1, acc + bars[i]);
    if(poss) break;
  }
  return ans[ind][acc] = poss;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--)
  {
    cin >> n >> p;
    for(int i = 0; i < p; i++){
      cin >> bars[i];
    }

    for(int i = 0; i < p; i++){
      for(int j = 0; j <= n; j++){
        ans[i][j] = -1;
      }
    }
    if(dp(0,0)){
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}