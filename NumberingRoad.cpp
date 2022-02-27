#include <iostream>
#include <cmath>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int i = 1;
  float r,n;
  while(cin >> r >> n){
    if(!r and !n) break;
    else {
      int res = ceil((r-n) / n);
      cout << "Case " << i << ": " ;
      if(res > 26) cout << "impossible\n";
      else cout << res << '\n';
    }
    i++;
  }
  return 0;
}