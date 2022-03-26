#include <iostream>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  const string tes = "aaaaa";
  int pos = tes.find('a');
  while(true) {
    int next = tes.find('a',pos+1);
    if(next == -1) break;
    else pos = next;
  }
  cout << pos;
  return 0;
}