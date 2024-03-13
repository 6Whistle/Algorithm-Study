#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.top() < K){
        if(pq.size() == 1)  return -1;
        int temp = pq.top();    pq.pop();
        pq.push(temp + (pq.top() << 1));    pq.pop();
    }
    return scoville.size() - pq.size();
}