#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> dic;
    map<char, int>::iterator iter;
    
    for(int i = 0; i < s.size(); i++){
        iter = dic.find(s[i]);
        answer.push_back(iter == dic.end() ? -1 : i - (*iter).second);
        dic[s[i]] = i;
    }

    return answer;
}
