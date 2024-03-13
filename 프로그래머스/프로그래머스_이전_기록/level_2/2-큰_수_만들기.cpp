#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string number, int k) {
    string answer;
    char c;
    for(auto i : number){  
        for(; answer.back() < i && k > 0 && answer.size(); k--) answer.pop_back();
        answer += i;
    }
    answer.erase(answer.end() - k, answer.end());
    return answer;
}