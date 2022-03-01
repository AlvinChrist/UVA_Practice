#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    int n; cin >> n;
    vector<int> arr;
    for(int j = 0; j < n; j++){
      int tmp; cin >> tmp;
      arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    cout << "Case " << i << ": " << arr[n/2] << '\n';
  }
  return 0;
}