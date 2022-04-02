#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  int c = 1;
  while(t--){
    int n; cin >> n;
    int high = 0;
    int low = 0;
    int h1 = 0;
    cin >> h1;
    for(int i = 1; i < n; i++){
      int h2; cin >> h2;
      if(h2 > h1) high++;
      else if(h2 < h1) low++;
      h1 = h2;
    }
    cout << "Case " << c << ": " << high << ' ' << low << '\n';
    c++;
  }
  return 0;
}