#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string s = "RTCFJMAN", answer = "";
    map<char, int> point;
    for_each(s.begin(), s.end(), [&](int temp){ point.insert(make_pair(temp, 0)); });
    for(int i = 0; i < survey.size(); i++)
        choices[i] < 4 ? (point[survey[i][0]] -= choices[i] - 4) : (point[survey[i][1]] += choices[i] - 4);
    for(int i = 0; i < 8; i += 2)
        answer.push_back(point[s[i]] < point[s[i + 1]] ? s[i + 1] : s[i]);
    return answer;
}