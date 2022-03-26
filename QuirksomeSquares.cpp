#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iomanip>
using namespace std;
vector<int> v;
vector<int> tmp;
unordered_map<int,vector<int>> m;
unordered_map<int,vector<int>>::iterator it;

bool splitNcheck(int num, int div) {
  int first = num / div;
  int second = num % div;
  return pow(first+second,2) == num;
}

int main(){
  ios_base::sync_with_stdio(false);
  for(int i = 0; i*i < 100000000; i++){
    v.push_back(i*i);
  }
  int n;
  while(cin >> n){
    it = m.find(n);
    if(it != m.end()){
      for(int i = 0; i < it->second.size(); i++) {
        cout << setw(n) << setfill('0');
        cout << it->second[i] << '\n';
      }
    }
    else{
      int limit = pow(10,n);
      int div = limit / 10;
      for(int i = 0; i < v.size(); i++){
        if(v[i] >= limit) break;
        if(splitNcheck(v[i],div)){
          cout << setw(n) << setfill('0');
          cout << v[i] << '\n';
          tmp.push_back(v[i]);
        }
      }
      m.insert(pair<int,vector<int>>(n,tmp));
      tmp.clear();
    }
  }
  return 0;
}