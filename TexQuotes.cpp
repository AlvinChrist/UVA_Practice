#include <iostream>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string text;
  bool flag = true;
  while(getline(cin,text)) {
    string res = "";
    for(int i = 0; i < text.length(); i++){
      if((char) text[i]=='"'){
        if(flag) res+="``";
        else res += "''";
        flag = !flag;
      }
      else{
        res += text[i];
      }
    }
    cout << res << '\n';
  }
  return 0;
}