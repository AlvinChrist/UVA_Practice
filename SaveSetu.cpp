#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  ll n; cin >> n;
  ll money = 0;
  string action;
  while(n--){
    cin >> action;
    if(action == "donate"){
      ll donation; cin >> donation;
      money += donation;
    }
    else if(action == "report"){
      cout << money << '\n';
    }
  }
  return 0;
}