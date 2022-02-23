#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  while(n--){
    int a,b; cin >> a >> b;
    if(a > b) cout << '>';
    else if(a < b) cout << '<';
    else cout << '=';
    cout << '\n';
  }
  return 0;
}