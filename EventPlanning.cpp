#include <iostream>
#include <map>
#include <vector>
#include <limits>

using namespace std;
map<int,vector<int>> m;
map<int,vector<int>>::iterator m_it;
vector<int> weeks;
vector<int>::iterator v_it;

int main(){
  ios_base::sync_with_stdio(false);
  int N,B,H,W;
  while(cin >> N >> B >> H >> W){
    for(int i = 0; i < H; i++){
      int price; cin >> price;
      for(int j = 0; j < W; j++){
        int week; cin >> week;
        weeks.push_back(week);
      }
      m.insert(pair<int,vector<int>>(price,weeks));
      weeks.clear();
    }
    int min_cost = INT32_MAX;
    for(m_it = m.begin(); m_it != m.end(); m_it++){
      for(v_it = m_it->second.begin(); v_it != m_it->second.end(); v_it++){
        if(*v_it >= N){
          int cost = N * m_it->first;
          if(cost < min_cost && cost <= B){
            min_cost = cost;
            break;
          }
        }
      }
    }
    if(min_cost == INT32_MAX) cout << "stay home\n";
    else cout << min_cost << '\n';
    m.clear();
  }
  return 0;
}