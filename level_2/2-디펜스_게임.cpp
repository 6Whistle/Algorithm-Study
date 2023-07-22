#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(; answer < min(k, (int)enemy.size()); pq.push(enemy[answer++]));
    for(; answer < enemy.size() && min(pq.top(), enemy[answer]) <= n; answer++)
        if(pq.top() < enemy[answer]){  n -= pq.top();  pq.pop();   pq.push(enemy[answer]); }    else    n -= enemy[answer];
    
    return answer;
}