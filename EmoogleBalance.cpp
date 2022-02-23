#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n,c = 1;
  while(true){
    cin >> n;
    if(!n) break;
    for(int i = 1; i <= n; i++){
      int e = 0;
      while(n--){
        int t; cin >> t;
        if(t > 0) e++;
        else e--;
      }
      cout << "Case " << c << ": " << e << '\n';
      c++;
    }
  }
  return 0;
}