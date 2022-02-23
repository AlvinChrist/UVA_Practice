#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for(int c = 1; c <= t; c++){
    int p[3] = {0};
    for(int i = 0; i < 3; i++){
      cin >> p[i];
    }
    sort(p,p+3);
    cout << "Case " << c << ": " << p[1] << '\n';
  }
  return 0;
}