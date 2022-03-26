#include <iostream>
#include <string>
using namespace std;

int splitNsum(string num){
  int sum = num[0] - '0';
  for(int i = 1; i < num.length(); i++){
    sum += (num[i] - '0');
    if(sum == 10) sum = 1;
    else if(sum > 10) sum = splitNsum(to_string(sum));
  }
  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(true){
    cin >> n;
    if(n == 0) break;
    cout << splitNsum(to_string(n)) << '\n';
  }
  return 0;
}