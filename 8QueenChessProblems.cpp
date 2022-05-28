#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
int col[8],c,r, line = 1;

bool check(int r,int c){
  for(int i = 0; i < c; i++){ // check col
    if(col[i] == r || abs(col[i] - r) == abs(i - c)) return false;
  }
  return true;
}

void solve(int _c){
  if(_c == 8 && col[c] == r){
    cout << setfill(' ') << std::setw(2) << line << "      " << (col[0] + 1);
    for(int i = 1; i < 8; i++){
      cout << ' ' << (col[i]+1);
    }
    cout << '\n';
    line++;
  }
  for(int i = 0; i < 8; i++){ // try all row
    if(check(i,_c)){
      col[_c] = i;
      solve(_c+1);
    }
  }
}

int main(){
  int n; cin >> n;
  while(n--){
    cin >> r >> c;
    line = 1;
    r--;
    c--;
    memset(col,0,sizeof col);
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    solve(0);
    if(n) cout << "\n";
  }
}