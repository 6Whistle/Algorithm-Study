#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    map<string, pair<int, int>> m;
    for(int i = 1; i < str1.size(); i++){
        if(!(isalpha(str1[i - 1]) && isalpha(str1[i]))) continue;
        auto f = m.insert({string{(char)tolower(str1[i - 1]), (char)tolower(str1[i])}, {1, 0}});
        if(!f.second)   ++(f.first->second.first);
    }
    for(int i = 1; i < str2.size(); i++){
        if(!(isalpha(str2[i - 1]) && isalpha(str2[i]))) continue;
        auto f = m.insert({string{(char)tolower(str2[i - 1]), (char)tolower(str2[i])}, {0, 1}});
        if(!f.second)   ++(f.first->second.second);
    }

    int sum = 0, same = 0;
    for_each(m.begin(), m.end(), [&sum, &same](pair<string, pair<int, int>> word){
        sum += max(word.second.first, word.second.second);
        same += min(word.second.first, word.second.second);
    });

    return sum == 0 ? 1 << 16 : (int)(((float)same / sum) * (1 << 16));
}