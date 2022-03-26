#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while(t--){
    double x,y,z; cin >> x >> y >> z;
    int res = (x+(x-y))/(x+y) * z;
    cout << res << '\n';
  }
  return 0;
}