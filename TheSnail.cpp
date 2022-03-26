#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  double h;
  while(true){
    cin >> h;
    if(h == 0) break;
    double u,d;
    double f;
    double cur = 0;
    cin >> u >> d >> f;
    f = (f/100.0) * u;
    int days = 0;
    while(true){
      days++;
      if(days > 1){
        if(u - f > 0){
          u -= f;
        }
        else u = 0;
      }
      cur += u;
      if(cur > h){
        cout << "success on day " << days << '\n';
        break;
      }
      cur -= d;
      if(cur < 0){
        cout << "failure on day " << days << '\n';
        break;
      }
    }
  }
  return 0;
}