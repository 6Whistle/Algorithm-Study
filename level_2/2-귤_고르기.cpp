#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

auto cmp = [](pair<int, int> a, pair<int, int> b){ return a.second > b.second; };

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> dic;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for_each(tangerine.begin(), tangerine.end(), [&dic](int i){ dic[i]++;   });
    for_each(dic.begin(), dic.end(), [&pq](pair<int, int> i){   pq.push(i); });
    for(int i = 0, answer = 0; i < k; i += pq.top().second, answer++, pq.pop());
    
    return answer;
}