#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> splitString(string str, string delimiter){
  vector<int> res;
  int start = 0;
  int end = str.find(delimiter);
  while(end != -1){
    res.push_back(stoi(str.substr(start,end - start)));
    start = end + delimiter.size();
    end = str.find(delimiter,start);
  }
  end = str.find('\0',start);
  res.push_back(stoi(str.substr(start,end - start)));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  vector<int> arr;
  for(int i = 1; i <= t; i++){
    string N;
    getline(cin >> ws,N);
    arr = splitString(N, " ");
    sort(arr.begin(),arr.end(),greater<int>());
    cout << "Case " << i << ": " << arr[0] << '\n';
    arr.clear();
  }
  return 0;
}