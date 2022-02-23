#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  cout.precision(3);
  for(int i = 1; i <= t; i++){
    double d,v,u; cin >> d >> v >> u;
    double t1 = d/u, t2 = d / sqrt(pow(u,2.0) - pow(v,2.0));
    double dt = t2 - t1;
    cout << "Case " << i << ": ";
    if(dt - 0 < 0.001 || isnan(dt) || isinf(dt)) cout << "can't determine\n";
    else cout << fixed << (t2-t1) << '\n';
  }
  return 0;
}