#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;

int solve(ll n){
  int cycle = 1;
  while(n != 1){
    if(n%2 == 0) n /= 2;
    else n = 3*n + 1;
    cycle++;
    // cout << n << '\n';
  }
  return cycle;
}

void swap(ll &a, ll &b) {
    ll temp = a;
    a = b;
    b = temp;
}

int main() {
  ios_base::sync_with_stdio(false);
  ll i,j; 
  for(int a = 1; a <= 50000; a++){
    solve(a);
  }
  while(cin >> i >> j){
    cout << i << ' ' << j << ' ';
    if(i > j) swap(i,j);
    int maks = 0;
    for(ll a = i; a <= j; a++){
      maks = max(maks,solve(a));
    }
    cout << maks << '\n';
  }
  return 0;
}