#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n,p,c = 1;
  while(true){
    cin >> n >> p;
    cin.ignore();
    if(n == 0 && p == 0) break;
    for(int i = 0; i < n; i++){
      string tmp;
      cin.ignore();
      getline(cin,tmp);
    }
    string cur_proposal = "";
    double cur_price = 0.0;
    int m = 0;
    for(int i = 0; i < p; i++){
      string proposal;
      double price;
      getline(cin,proposal);
      int met = 0;
      cin >> price >> met;
      cin.ignore();
      for(int j = 0; j < met; j++){
        string tmp;
        cin.ignore();
        getline(cin,tmp);
      }
      if(met > m || (met == m && price < cur_price)){
        m = met;
        cur_proposal = proposal;
        cur_price = price;
      }
    }
    cout << "RFP #" << c << '\n';
    cout << cur_proposal << '\n';
    if((char) cin.peek() != '0') cout << '\n';
    c++;
  }
  return 0;
}