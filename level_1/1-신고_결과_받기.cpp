#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector<vector<int> > count(id_list.size());
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for(string s : report){ 
        stringstream ss(s);
        string user, terget;
        ss >> user >> terget;
        count[find(id_list.begin(), id_list.end(), terget) - id_list.begin()].push_back((int)(find(id_list.begin(), id_list.end(), user) - id_list.begin()));
    }
    
    for(auto i : count)
        if(i.size() >= k)   for_each(i.begin(), i.end(), [&](int j){ answer[j]++; });
    
    return answer;
}