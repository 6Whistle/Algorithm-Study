#include <string>
#include <vector>

using namespace std;

void erase_0(vector<int> &tmp){  for(; !tmp.empty() && !tmp.back(); tmp.pop_back());    };
void move_box(vector<int> &tmp, int cap, int cnt = 0){  for(; tmp.back() + cnt <= cap && !tmp.empty(); cnt += tmp.back(), tmp.pop_back());     if(!tmp.empty()) tmp.back() -= cap - cnt;   };

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    erase_0(deliveries), erase_0(pickups);
    for(; !deliveries.empty() || !pickups.empty();){
        answer += max(deliveries.size(), pickups.size()) << 1;
        move_box(deliveries, cap);  move_box(pickups, cap);
    }
    return answer;
}