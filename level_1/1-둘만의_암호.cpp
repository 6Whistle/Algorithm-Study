#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for_each(s.begin(), s.end(), [&](char c){
        for(int i = 0; i < index; i++){
            c = c == 'z' ? 'a' : c + 1;
            i -= find(skip.begin(), skip.end(), c) == skip.end() ? 0 : 1;
        }
        answer.push_back(c);
    });
    return answer;
}