#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <regex>

using namespace std;

int binary_search(vector<int> &ve, int find){
    int start = 0, end = ve.size(), mid = (start + end) >> 1;
    for(; start < end; mid = (start + end) >> 1)
        if(ve[mid] < find)  start = mid + 1;
        else    end = mid;
    return ve.size() - start;
}

vector<int> solution(vector<string> info, vector<string> query) {
    map<string, vector<int>> db;
    regex re(" ");
    for(auto i = 0; i < info.size(); i++){
        sregex_token_iterator iter(info[i].begin(), info[i].end(), re, -1);
        vector<string> q = vector<string>(iter, {});
        pair<map<string, vector<int>>::iterator, bool> key;
        key = db.insert({q[0]+q[1]+q[2]+q[3], vector<int>()});
        key.first->second.push_back(stoi(q[4]));
    }
    for(auto i = db.begin(); i != db.end(); i++)    sort(i->second.begin(), i->second.end());

    vector<int> answer;
    for_each(query.begin(), query.end(), [&](string temp){
        sregex_token_iterator iter(temp.begin(), temp.end(), re, -1);
        vector<string> q = vector<string>(iter, {});
        vector<vector<string>> key_list;
        key_list.push_back(q[0].compare("-") ? vector<string>(1, q[0]) : vector<string>({"cpp", "java", "python"}));
        key_list.push_back(q[2].compare("-") ? vector<string>(1, q[2]) : vector<string>({"backend", "frontend"}));
        key_list.push_back(q[4].compare("-") ? vector<string>(1, q[4]) : vector<string>({"junior", "senior"}));
        key_list.push_back(q[6].compare("-") ? vector<string>(1, q[6]) : vector<string>({"chicken", "pizza"}));

        answer.push_back(0);
        for(string lang : key_list[0])  for(string where : key_list[1]) for(string age : key_list[2]) for(string like : key_list[3])
            answer.back() += binary_search(db[lang + where + age + like], stoi(q[7]));
    });
    return answer;
}
