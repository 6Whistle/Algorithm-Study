#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<pair<int, float>> rate;
    vector<int> answer;

    sort(stages.begin(), stages.end());

    for(int i = 1; i <= N; i++){
        vector<int>::iterator begin = find(stages.begin(), stages.end(), i);
        vector<int>::iterator end = find_if(begin, stages.end(), [&](int a){ return a > i;   });
        auto fail = distance(begin, end), success = distance(end, stages.end());
        rate.push_back(make_pair(i, fail + success == 0 ? 0 : (float)fail / (fail + success)));
    }
    
    sort(rate.begin(), rate.end(), [](pair<int, float> a, pair<int, float> b){  return a.second == b.second ? a.first < b.first : a.second > b.second;  });
    for_each(rate.begin(), rate.end(), [&](pair<int, float> temp){ answer.push_back(temp.first);   });

    return answer;
}