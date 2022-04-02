#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string s;
  int c = 1;
  while(true){
    cin >> s;
    if(s == "#") break;
    cout << "Case " << c << ": ";
    c++;
    if(s == "HELLO") cout << "ENGLISH\n";
    else if(s == "HOLA") cout << "SPANISH\n";
    else if(s == "HALLO") cout << "GERMAN\n";
    else if(s == "BONJOUR") cout << "FRENCH\n";
    else if(s == "CIAO") cout << "ITALIAN\n";
    else if(s == "ZDRAVSTVUJTE") cout << "RUSSIAN\n";
    else cout << "UNKNOWN\n";
  }
  return 0;
}