#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    for_each(score.begin(), score.end(), [&](int i){
        pq.push(i);
        if(pq.size() > k)    pq.pop();
        answer.push_back(pq.top());
    });
    return answer;
}