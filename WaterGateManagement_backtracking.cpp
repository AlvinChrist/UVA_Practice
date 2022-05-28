#include <iostream>
using namespace std;
typedef long long ll;
int n, f[21], c[21], maxVol, t;
ll res;

void backTracking(int i, ll flow, ll cost) {
  if (cost >= res) return;
  if (flow >= maxVol) {
      res = min(res, cost);
      return;
  }
  if (i == n) return;
  backTracking(i + 1, flow + f[i] * (ll)t, cost + c[i]);
  backTracking(i + 1, flow, cost);
}

int main(){
  ios_base::sync_with_stdio(false);
  int m;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> f[i] >> c[i];
  }
  cin >> m;
  for(int i = 1; i <= m; i++){
    cin >> maxVol >> t;
    cout << "Case " << i << ": ";
    res = INT64_MAX;
    backTracking(0,0,0);
    if (res != INT64_MAX) cout << res;
    else cout << "IMPOSSIBLE";
    cout << '\n';
  }
  return 0;
}