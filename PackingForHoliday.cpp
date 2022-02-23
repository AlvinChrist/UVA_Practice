#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for(int c = 1; c <= t; c++){
    bool stat = true;
    for(int i = 0; i < 3; i++){
      int s; cin >> s;
      stat = (s <= 20) && stat;
    }
    cout << "Case " << c << ": " << ((stat)?"good":"bad") << '\n';
  }
  return 0;
}