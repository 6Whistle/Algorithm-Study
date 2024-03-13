#include <string>
#include <vector>
#include <regex>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> dic;
    regex r("[\{\},]{1,}");
    sregex_token_iterator iter(s.begin(), s.end(), r, -1), end;
    for_each(iter, end, [&](string temp){
        if(temp.empty())    return;
        pair<map<int, int>::iterator, bool> find = dic.insert({stoi(temp), 1});
        if(!find.second)    find.first->second++;
    });
    vector<pair<int, int>>  pq(dic.begin(), dic.end());
    sort(pq.begin(), pq.end(), [](pair<int, int> &a, pair<int, int> &b){    return a.second > b.second;     });
    for_each(pq.begin(), pq.end(), [&answer](pair<int, int> &temp){    answer.push_back(temp.first);    });

    return answer;
}