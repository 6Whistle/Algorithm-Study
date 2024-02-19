#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> m;
    vector<int> answer;
    for(int i = 0; i < name.size(); i++)    m.insert({name[i], yearning[i]});
    for_each(photo.begin(), photo.end(), [&](vector<string> person){
        answer.push_back(accumulate(person.begin(), person.end(), 0, [&](int i, string s){ return i + m[s]; }));
    });
    return answer;
}