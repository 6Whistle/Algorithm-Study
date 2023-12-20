#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int timeToInt(string time){ return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)); }
void updateCur(vector<vector<string>> &plans, tuple<string, int, int> &cur){   cur = { plans.back()[0], timeToInt(plans.back()[1]), stoi(plans.back()[2]) };   plans.pop_back();   }

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> st;
    sort(plans.begin(), plans.end(), [](vector<string> p1, vector<string>p2){   return timeToInt(p1[1]) < timeToInt(p2[1]); });
    tuple<string, int, int> cur = { plans[0][0], timeToInt(plans[0][1]), stoi(plans[0][2])}, tmp;
    for(int i = 1; i < plans.size(); i++){
        tmp = { plans[i][0], timeToInt(plans[i][1]), stoi(plans[i][2]) };
        for(; !st.empty() && get<1>(cur) + get<2>(cur) <= get<1>(tmp); st.pop_back()){
            answer.push_back(get<0>(cur));
            cur = {st.back().first, get<1>(cur) + get<2>(cur), st.back().second};
        }
        if(get<1>(cur) + get<2>(cur) <= get<1>(tmp))    answer.push_back(get<0>(cur));
        else    st.push_back({ get<0>(cur), get<1>(cur) + get<2>(cur) - get<1>(tmp) });
        cur = tmp;
    }
    answer.push_back(get<0>(cur));
    for(;!st.empty();st.pop_back()) answer.push_back(st.back().first);
    return answer;
}