#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> max_vec(course.size(), 0);
    map<string, int> dic;
    for_each(orders.begin(), orders.end(), [&](string temp){
        sort(temp.begin(), temp.end());
        for(int i = 1, j; i < (1 << temp.size()); i++){
            string str;
            for(int j = 0; j < temp.size(); j++)    if(i & (1 << j))    str += temp[j];
            for(j = 0; j < course.size() && str.size() > course[j]; j++);
            if(str.size() == course[j]){
                auto iter = dic.insert({str, 1});
                if(!iter.second){   iter.first->second++;   max_vec[j] = max(max_vec[j], iter.first->second);   }
            }   
        }
    });
    for_each(dic.begin(), dic.end(), [&](pair<string, int> temp){   if(max_vec[distance(course.begin(), find(course.begin(), course.end(), temp.first.size()))] == temp.second) answer.push_back(temp.first);   });

    return answer;
}