#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits.h>  
using namespace std;
typedef long long ll;
map<string,int> memory;
map<char,int> mapping;
map<string,int>::iterator it;
ll bin[3][3] = {0};
ll result = INT64_MAX;
string bin_order = "";
ll total = 0;

void solve(string str){
  ll temp = total - bin[mapping.find((char) str[0])->second][0] - bin[mapping.find((char) str[1])->second][1] - bin[mapping.find((char) str[2])->second][2];
  if(temp < result){
    result = temp;
    bin_order = str;
  }
  else if(result == temp && str < bin_order){
    bin_order = str;
  }
  // cout << str << ' ' << temp << '\n';
}

void permute(string str, int i, int n){
  if(i == n - 1){
    solve(str);
    // cout << str << '\n';
    return;
  }  
  for(int j = i; j < n; j++){
    swap(str[i],str[j]);
    permute(str, i + 1, n);
    swap(str[i],str[j]);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  mapping.insert(pair<char,int>('B',0));
  mapping.insert(pair<char,int>('G',1));
  mapping.insert(pair<char,int>('C',2));
  while(true){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        cin >> bin[j][i];
        if(cin.peek() == EOF) return 0;
        total += bin[j][i];
      }
    }
    // B = 0, G = 1, C = 2
    // bin[0] = B, bin[1] = G, bin[2] = C
    permute("BCG",0,3);
    cout << bin_order << ' ' << result << '\n';
    total = 0;
    bin_order = "";
    result = INT64_MAX;
  }
  return 0;
}