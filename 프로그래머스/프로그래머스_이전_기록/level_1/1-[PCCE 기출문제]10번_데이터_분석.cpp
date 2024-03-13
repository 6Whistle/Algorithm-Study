#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int name_to_int(string str){
    return str == "code" ? 0 : str == "date" ? 1 : str == "maximum" ? 2 : 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int ext_int = name_to_int(ext), sort_by_int = name_to_int(sort_by);
    auto cmp = [&](vector<int> a, vector<int> b){   return a[sort_by_int] > b[sort_by_int];    };
    vector<vector<int>> answer;
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for_each(data.begin(), data.end(), [&](vector<int> d){
        if(d[ext_int] < val_ext)    pq.push(d);
    });
    for(;!pq.empty(); pq.pop()) answer.push_back(pq.top());
    return answer;