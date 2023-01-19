#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer;
    for_each(new_id.begin(), new_id.end(), [&](unsigned char c){  if(isalnum(c) || strchr(".-_", c))    answer += tolower(c);  });
    answer = regex_replace(answer, regex("[.]+"), ".");
    if(*answer.begin() == '.')    answer.erase(answer.begin());
    if(*(answer.end() - 1) == '.')   answer.erase(answer.end() - 1);
    if(answer.empty())  answer = "a";
    if(answer.size() > 15)  answer.erase(answer.begin() + (answer[14] == '.' ? 14 : 15), answer.end());
    while(answer.size() < 3)   answer.push_back(answer.back());
        
    return answer;
}