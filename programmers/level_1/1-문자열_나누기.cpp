#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int first = s[0], x = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        s[i] == first ? x++ : y++;
        if(x == y) {    answer++;   first = s[i+1];     x = 0;      y = 0;       }
        else if(i == s.size() - 1)   answer++;
    }
    return answer;
}