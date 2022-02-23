#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool diff(string a, string b) {
  int diff = 0;
  for(int i = 0; i < a.length(); i++){
    if(a[i] != b[i]) diff++;
  }
  return diff == 1 || diff == 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  int map[] = {0,1,2,3,4,5,6,7,8,9,10};
  string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
  int t; cin >> t;
  while(t--){
    string word; cin >> word;
    for(int i = 0; i <= 10; i++){
        if(word.length() == arr[i].length()){
          if(diff(arr[i],word)){
            cout << map[i] << '\n';
            break;
          }
        }
    }
  }
  return 0;
}