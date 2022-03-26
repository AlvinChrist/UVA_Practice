#include <iostream>
#include <map>
using namespace std;
map<char,int> memory;
map<char,int> temp;
map<char,int>::iterator it;
map<char,int>::iterator _it;

int main(){
  ios_base::sync_with_stdio(false);
  string seq; cin >> seq;
  int totalDistinctChar = 0;
  for(int i = 0; i < seq.size(); i++){
    it = memory.find(seq[i]);
    if(it != memory.end()){
      it->second++;
    }
    else{
      memory.insert(pair<char,int>(seq[i],1));
      totalDistinctChar++;
    }
  }
  int n; cin >> n;
  while(n--){
    string q; cin >> q;
    int _totalDistinctChar = 0;
    bool increasing = true;
    bool existNlowerTotal = true;
    int prevPos = 0;
    char prevChar = ' ';
    int start = seq.find(q[0]);
    int end = 0;
    for(int i = 0; i < q.size(); i++){
      it = temp.find(q[i]);
      if(it != temp.end()){
        it->second++;
      }
      else{
        temp.insert(pair<char,int>(q[i],1));
        _totalDistinctChar++;
      }
      int pos = seq.find(q[i]);
      while(pos < prevPos) {
        int next = seq.find(q[i],pos+1);
        pos = next;
        if(pos == -1) break;
        if(q[i] == prevChar && pos > prevPos) break;
        if(q[i] != prevChar && pos >= prevPos) break;
      }
      // cout << q[i] << ' ' << pos << ' ' << prevPos << '\n';
      if(pos < prevPos || pos == -1){
        increasing = false;
        break;
      }
      prevPos = pos;
      prevChar = q[i];
    }
    if(_totalDistinctChar > totalDistinctChar || !increasing){
      cout << "Not matched\n";
    }
    else{
      // for(_it = temp.begin(); _it != temp.end(); _it++){
      //   cout << _it->first << ' ' << _it->second << '\n';
      // }
      for(_it = temp.begin(); _it != temp.end(); _it++){
        it = memory.find(_it->first);
        
        if(it == memory.end() || it->second < _it->second){ // check if character exist and not more than sequence character
          existNlowerTotal = false;
          break;
        }
      }
      if(!existNlowerTotal) cout << "Not matched\n";
      else{
        it = temp.find(q[q.size()-1]);
        cout << "Matched " << start << ' ' << prevPos << '\n';
      }
    }
    // cout << "incr: " << increasing << '\n';
    // cout << "existNlowerTotal: " << existNlowerTotal << '\n';
    // cout << totalDistinctChar << ' ' << _totalDistinctChar << '\n';
    temp.clear();
  }
  return 0;
}