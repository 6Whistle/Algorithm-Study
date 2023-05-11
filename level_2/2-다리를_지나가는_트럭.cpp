#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int q_weight = 0, time = 0;
    queue<int> q; 
    for(; time < bridge_length; time++)  q.push(0);
    for(int i = 0; i < truck_weights.size();){
        q_weight -= q.front();    time++;    q.pop();
        q.push(truck_weights[i] + q_weight > weight ? 0 : truck_weights[i++]);
        q_weight += q.back();
    }
    return time;
}