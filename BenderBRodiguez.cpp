#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int l;
  while(true){
    cin >> l;
    if(!l) break;
    string direction = "+x";
    for(int i = 1; i < l; i++){
      string bend;
      cin >> bend;
      if(bend == "No"){

      }
      else if(direction[1] == 'x'){
        if(bend[0] == direction [0]) direction[0] = '+';
        else direction[0] = '-';
        direction[1] = bend[1];
      }
      else if(direction[1] == bend[1]){
        if(direction[0] != bend[0]) direction[0] = '+';
        else direction[0] = '-';
        direction[1] = 'x';
      }
    }
    cout << direction << '\n';
  }
  return 0;
}