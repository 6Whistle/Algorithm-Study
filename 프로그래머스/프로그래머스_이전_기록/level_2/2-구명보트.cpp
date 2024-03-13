#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, temp = 0;
    sort(people.begin(), people.end());
    deque<int> d(people.begin(), people.end());
    for(; d.size() > 1; d.pop_back(), answer++)   if(d.back() + d.front() <= limit)   d.pop_front();
    return d.empty() ? answer : answer + 1;
}