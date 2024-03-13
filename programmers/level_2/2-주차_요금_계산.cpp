#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> visit, in_out;
    regex re(" |\:");
    for_each(records.begin(), records.end(), [&](string &record){
        sregex_token_iterator iter(record.begin(), record.end(), re, -1);
        vector<string> tmp(iter, {});
        int car_num = stoi(tmp[2]);
        if(tmp[3] == "IN"){     visit.insert({car_num, 0});     in_out.insert({car_num, stoi(tmp[0]) * 60 + stoi(tmp[1])});     }
        else{           visit[car_num] += stoi(tmp[0]) * 60 + stoi(tmp[1]) - in_out[car_num];       in_out.erase(car_num);      }
    });
    for_each(in_out.begin(), in_out.end(), [&](pair<int, int> tmp){  visit[tmp.first] += 1439 - tmp.second; });
    for_each(visit.begin(), visit.end(), [&](pair<int, int> tmp){   
        int time_fee = tmp.second - fees[0];
        answer.push_back(fees[1] + (time_fee < 0 ? 0 : (time_fee / fees[2] + (bool)(time_fee % fees[2])) * fees[3]));
    });
    
    return answer;
}