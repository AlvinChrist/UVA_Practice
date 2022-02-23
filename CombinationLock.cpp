#include <iostream>
using namespace std;

int init, n1, n2, n3;
int res = 720 + 360;

int spin(int a, int b, bool cw = true) {
  int res = 0;
  if(cw) res = a - b;
  else res = b - a;
  if(res < 0) res += 40;
  return res;
}

void solve() {
  res += spin(init,n1,true) * 9;
  res += spin(n1,n2,false) * 9;
  res += spin(n2,n3,true) * 9;
}

int main() {
  ios_base::sync_with_stdio(false);
  while(cin >> init >> n1 >> n2 >> n3){
    if(init == 0 && n1 == 0 && n2 == 0 && n3 == 0){
      break;
    }
    solve();
    cout << res << '\n';
    res = 720 + 360;
  };
  return 0;
}