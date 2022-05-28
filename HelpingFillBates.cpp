#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char,int> m;
unordered_map<char,int>::iterator it;
vector<pair<char,pair<int,int>>> order;

vector<string> splitString(string ss){
  int start = 0;
  vector<string> v;
  for(int i = 1; i < ss.length(); i++){
    if(ss[i] != ss[i-1]){
      string t = ss.substr(start,i-start);
      start = i;
      v.push_back(t);
    }
  }
  v.push_back(ss.substr(start,ss.length()));
  return v;
}

int main(){
  ios_base::sync_with_stdio(false);
  string s; cin >> s;
  for(int i = 0; i < s.length(); i++){
    it = m.find(s[i]);
    if(it != m.end()){
      it->second++;
    }
    else{
      m.insert(pair<char,int>(s[i],1));
      order.push_back(pair<char,pair<int,int>>(s[i],pair<int,int>()));
    }
  }
  int q; cin >> q;
  while(q--){
    string ss; cin >> ss;
    vector<string> res = splitString(ss);
    // check character occurences
    bool check = true;
    for(int i = 0; i < res.size(); i++){
      it = m.find(res[i][0]);
      if(it == m.end()){
        bool check = false;
        break;
      }
      else if(it != m.end() && it->second != res[i])
    }
  }
  return 0;
}