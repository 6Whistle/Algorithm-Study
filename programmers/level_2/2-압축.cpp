#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    int i = 0, dic_num = 27;
    unordered_map<string, int> dic;
    vector<int> answer;

    while(i < msg.size()){
        int size = 2, before_num = msg[i] - 'A' + 1;
        for(; i + size <= msg.size(); size++){
            auto iter = dic.insert({string{msg.begin() + i, msg.begin() + i + size}, dic_num});
            if(iter.second)     break;
            before_num = iter.first->second;
        }
        answer.push_back(before_num);
        dic_num++;      i += size - 1;
    }
    
    return answer;
}