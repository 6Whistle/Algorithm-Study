#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    map<int, int> check;
    map<int, vector<int>> table;
    
    for_each(edges.begin(), edges.end(), [&](vector<int> edge){ 
        check[edge[1]]++;
        auto iter = table.insert({ edge[0], { edge[1] } });
        if(!iter.second)    iter.first->second.push_back(edge[1]);
    });
    for(auto iter = table.begin(); iter != table.end() && (iter->second.size() < 2 || check[answer[0] = iter->first]); iter++);
    for_each(table[answer[0]].begin(), table[answer[0]].end(), [&](int i){
        for(set<int> visit;;){
            auto iter = table.find(i);
            if(iter == table.end()){        answer[2]++;          return;     }
            if(iter->second.size() > 1){    answer[3]++;          return;     }
            if(!visit.insert(i).second){    answer[1]++;          return;     }
             i = iter->second[0];
        }
    });
    return answer;
}