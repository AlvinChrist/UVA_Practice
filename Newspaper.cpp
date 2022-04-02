#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <string>
using namespace std;

unordered_map<char,int> m;
unordered_map<char,int>::iterator it;

int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while(t--){
    int k; cin >> k;
    while(k--){
      char c; int cent;
      cin >> c >> cent;
      m.insert(pair<char,int>(c,cent));
    }
    int M; cin >> M;
    M++;
    int total = 0;
    while(M--){
      string text;
      getline(cin,text);
      for(int i = 0; i < text.size(); i++){
        it = m.find(text[i]);
        if(it != m.end()){
          total += it->second;
        }
      }
    }
    cout << ((total/100 > 0)? total/100: 0) << '.' << setw(2) << setfill('0') << (total%100) << "$\n";
    m.clear();
  }
  return 0;
}