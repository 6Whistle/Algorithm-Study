#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> names;
    vector<pair<string, bool>> rec_state;
    vector<string> answer;
    string temp1, temp2, temp3;
    for_each(record.begin(), record.end(), [&](string str){
        stringstream ss;    ss.str(str);
        ss >> temp1 >> temp2 >> temp3;
        if(!temp1.compare("Enter")){    names[temp2] = temp3;    rec_state.push_back({temp2, 1});    }
        else if(!temp1.compare("Leave"))    rec_state.push_back({temp2, 0});
        else    names[temp2] = temp3;
    });
    for_each(rec_state.begin(), rec_state.end(), [&](pair<string, bool> state){ 
        answer.push_back(names[state.first] + "님이 " + (state.second ? "들어왔습니다." : "나갔습니다."));
    });
    return answer;
}