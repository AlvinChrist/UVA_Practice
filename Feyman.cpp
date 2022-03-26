#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(true){
    cin >> n;
    if(n == 0) break;
    ll res = 0;
    for(ll a = 1; a <= n; a++){
      res += pow(a,2);
    }
    cout << res << '\n';
  }
  return 0;
}