#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, long long> dic;
    for_each(weights.begin(), weights.end(), [&](int i){  dic[i]++;   });
    for(auto i = dic.begin(), j = i; i != dic.end(); ++j = ++i){
        int cmp;    answer += (i->second * (i->second - 1)) >> 1;
        for(int cmp = i->first << 2; j != dic.end() && j->first * 3 <= cmp; j++)    if(j->first * 3 == cmp)   answer += i->second * j->second;
        for(int cmp = i->first * 3; j != dic.end() && j->first << 1 <= cmp; j++)    if(j->first << 1 == cmp)   answer += i->second * j->second;
        for(int cmp = i->first << 1; j != dic.end() && j->first <= cmp; j++)    if(j->first == cmp)   answer += i->second * j->second;
    }
    return answer;
}