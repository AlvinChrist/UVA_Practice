#include <iostream>
typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  ll m,n; 
  while(cin >> m >> n){
    if(n > m) cout << n - m;
    else cout << m - n;
    cout << '\n';
  };
  return 0;
}