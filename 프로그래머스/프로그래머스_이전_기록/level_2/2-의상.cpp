#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> dic;
    pair<map<string, int>::iterator, bool> iter;
    for_each(clothes.begin(), clothes.end(), [&](vector<string> cloth){
        if(!(iter = dic.insert({cloth[1], 2})).second)  (iter.first->second)++;
    });
    for_each(dic.begin(), dic.end(), [&](pair<string, int> p){  answer *= p.second; });
    return answer - 1;
    
}