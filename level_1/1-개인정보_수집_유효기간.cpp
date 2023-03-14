#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

bool day_compare(vector<string> &today, vector<string> &compare, map<char, int> &period){
    short year = stoi(today[0]), month = stoi(today[1]), day = stoi(today[2]);
    short com_year = stoi(compare[0]), com_day = stoi(compare[2]);
    short com_month = stoi(compare[1]) + period[compare[3][0]];
    if(com_month > 12){     com_year++;     com_month -= 12;    }
    
    if(year > com_year) return true;
    else if(year == com_year && month > com_month)  return true;
    else if(year == com_year && month == com_month && day >= com_day)   return true;
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> period;
    regex re("[. ]");
    sregex_token_iterator it(today.begin(), today.end(), re, -1);
    vector<string> current(it, {});
    for_each(terms.begin(), terms.end(), [&](string s){ 
        sregex_token_iterator iter(s.begin(), s.end(), re, -1);
        period.insert(make_pair(iter->str()[0], stoi((++iter)->str())));
    });
    for(int i = 0; i < privacies.size(); i++){
        sregex_token_iterator iter(privacies[i].begin(), privacies[i].end(), re, -1);
        vector<string> split_data(iter, {});
        if(day_compare(current, split_data, period))    answer.push_back(i + 1);
    } 
    
    return answer;
}