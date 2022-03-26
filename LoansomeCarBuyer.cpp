#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int duration,depreciation;
  double loans, dp;
  while(true){
    cin >> duration >> dp >> loans >> depreciation;
    double arr[100] = {0};
    if(duration > 0){
      // cout << cur_value << ' ' << owes << '\n';
      while(depreciation--){
        int _m;
        cin >> _m;
        cin >> arr[_m];
      }
      double per_month = loans/duration;
      double cur_value = cur_value = (1 - arr[0]) * loans + (1 - arr[0]) * dp;
      double owes = loans;
      double p = arr[0];
      int months = 1;
      int counter = 0;
      while(owes >= cur_value){
        if(arr[months] == 0){
          cur_value = (1 - p) * cur_value;
        }
        else{
          cur_value = (1 - arr[months]) * cur_value;
          p = arr[months];
        }
        owes -= (per_month);
        // cout << cur_value << ' ' << owes << '\n';
        months++;
        counter++;
      }
      cout << counter << ' ';
      (counter > 1 || counter == 0)?cout << "months\n" : cout << "month\n";
    }
    else break; 
  }
  return 0;
}