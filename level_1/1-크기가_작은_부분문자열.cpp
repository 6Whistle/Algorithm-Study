#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    list<int> window;
    for(int i = 0; i < t.size(); i++){
        window.push_back(t[i]);
        if(window.size() < p.size()) continue;
        list<int>::iterator iter = window.begin();
        string::iterator com_iter = p.begin();
        while(com_iter < p.end() - 1 && *iter == *com_iter){    iter++; com_iter++; }
        answer += *iter <= *com_iter ? 1 : 0;
        window.pop_front();
    }
    return answer;
}