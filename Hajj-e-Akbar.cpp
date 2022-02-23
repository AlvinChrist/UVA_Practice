#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  string tmp;
  ll c = 1;
  while(cin >> tmp){
    if(tmp == "*") break;
    cout << "Case " << c << ": ";
    c++;
    if(tmp == "Hajj") cout << "Hajj-e-Akbar";
    else if(tmp == "Umrah") cout << "Hajj-e-Asghar";
    cout << '\n';
  }
  return 0;
}