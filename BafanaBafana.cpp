#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    int n,k,p; cin >> n >> k >> p;
    int res = p % n + k;
    if(res > n) res %= n;
    cout << "Case " << i << ": " << res << '\n';
  }
  return 0;
}