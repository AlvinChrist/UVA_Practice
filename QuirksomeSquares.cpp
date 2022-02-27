#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string arr[4][9] = {
  {"00","01","81"}, 
  {"0000","0001","2025","3025","9801"},
  {"000000", "000001", "088209", "494209", "998001"}, 
  {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"}
};

string formatInt(int n, int digits){
  string cpy = to_string(n);
  if(cpy.length() < digits){
    string pre = "";
    for(int i = 0; i < digits - cpy.length(); i++){
      pre += "0";
    }
    return pre + cpy;
  }
  else return cpy;
}

bool isQuirksome(int n, int digits){
  string str = formatInt(n, digits);
  int mid = digits/2;
  int n1 = stoi(str.substr(0,mid));
  int n2 = stoi(str.substr(mid,mid));
  return formatInt(pow((n1 + n2),2),digits) == str;
}


int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n) {
    int idx = n / 2 - 1;
    for(int i = 0; i < 9; i++){
      if(arr[idx][i] != "") cout << arr[idx][i] << '\n';
    }
  }
  return 0;
}