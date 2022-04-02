#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

stack<int> splitString(string str, string delimiter){
  stack<int> _s;
  int start = 0;
  int end = str.find(delimiter);
  if(end == -1){
    end = str.find('\0',start);
    _s.push(stoi(str.substr(start,end - start)));
  }
  else{
    while(end != -1){
      _s.push(stoi(str.substr(start,end - start)));
      start = end + delimiter.size();
      end = str.find(delimiter,start);
      if(end == -1) {
        end = str.find('\0',start);
        // cout << str.substr(start,end-start) << '\n';
        _s.push(stoi(str.substr(start,end-start)));
        end = -1;
      }
    }
  }
  return _s;
}

stack<int> flip(int start,int end,stack<int> s){
  queue<int> q;
  for(int i = start; i >= end; i--){
    q.push(s.top());
    s.pop();
  }
  for(int i = start; i >= end; i--){
    s.push(q.front());
    q.pop();
  }
  return s;
}

int main(){
  ios_base::sync_with_stdio(false);
  string seq;
  while(getline(cin,seq)){
    stack<int> s;
    s = splitString(seq," ");
    cout << seq;
    stack<int> s_copy = s;
    int start = s.size();
    int end = 0;
    while(true){
      int prev = s.top();
      int flipIndex = start;
      bool asc = true;
      for(int i = start-1; i > end; i--){
        cout << s_copy.top();
        if(prev > s_copy.top())asc = false;
        else if(prev < s_copy.top()){
          prev = s_copy.top();
          flipIndex = i;
        }
        s_copy.pop();
      }
      if(flipIndex != start) s = flip(start,flipIndex,s);
      s = flip(start,1,s);
      if(asc) {
        cout << 0 << '\n';
      }
      else{
        cout << flipIndex << ' ';
      }
    }
    cin >> ws;
  }
  return 0;
}
