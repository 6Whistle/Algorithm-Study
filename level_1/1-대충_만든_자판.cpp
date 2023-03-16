#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<size_t> dic(26, -1);

    for_each(keymap.begin(), keymap.end(), [&](string s){
        for(size_t i = 0; i < s.size(); i++)
            dic[s[i] - 'A'] = dic[s[i] - 'A'] == -1 ? i : min(i, dic[s[i] - 'A']); 
    });

    for_each(targets.begin(), targets.end(), [&](string s){
        int sum = 0;
        for(size_t i = 0; i < s.size(); i++){
            if(dic[s[i] - 'A'] == -1){ answer.push_back(-1);   return; }
            sum += dic[s[i] - 'A'] + 1;
        }
        answer.push_back(sum);
    });
    return answer;
}