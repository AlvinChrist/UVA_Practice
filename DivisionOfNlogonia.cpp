#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  while(true){
    cin >> N;
    if(!N) break;
    int n,m; cin >> n >> m;
    while(N--){
      int x,y; cin >> x >> y;
      if(x == n || y == m){
        cout << "divisa";
      }
      else if(x > n){
        if(y > m) cout << "NE";
        else cout << "SE";
      }
      else if (x < n){
        if(y > m) cout << "NO";
        else cout << "SO";
      }
      cout << '\n';
    }
  }
  return 0;
}