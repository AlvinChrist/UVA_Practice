#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;
double v = 0;
double s = 0;
ll t = 0;

vector<string> splitString(string str, string delimiter){
  vector<string> res;
  int start = 0;
  int end = str.find(delimiter);
  if(end == -1){
    end = str.find('\0',start);
    res.push_back(str.substr(start,end - start));
  }
  else{
    while(end != -1){
      res.push_back(str.substr(start,end - start));
      start = end + delimiter.size();
      end = str.find(delimiter,start);
      if(end == -1) {
        end = str.find('\0',start);
        // cout << str.substr(start,end-start) << '\n';
        res.push_back(str.substr(start,end-start));
        end = -1;
      }
    }
  }
  return res;
}

ll parseTime(string time){
  vector<string> res;
  res = splitString(time,":");
  // cout << res[0] << " " << res[1] << " " << res[2] << '\n';
  return stoll(res[0]) * 3600 + stoll(res[1]) * 60 + stoll(res[2]);
}

int main() {
  ios_base::sync_with_stdio(false);
  string q;
  while(getline(cin,q)){
    // cout << q;
    vector<string> split;
    split = splitString(q," ");
    // cout << split.size() << '\n';
    ll _t = parseTime(split[0]);
    s += (v * (_t - t));
    t = _t;
    if(split.size() == 2){
      v = stoi(split[1]) * (1/3600.00);
      // cout << t << " " << v << '\n';
    }
    else{
      cout << fixed << setprecision(2);
      cout << split[0] << " " << s << " km\n";
    }
  }
  return 0;
}