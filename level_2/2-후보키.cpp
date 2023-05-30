#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(vector<int> &ans, int bi){
    for(int i : ans)    if((i & bi) == i)     return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> ans;
    for(int i = 1; i < (1 << relation.begin()->size()); i++){
        set<string> dic;
        for(int j = 0; j < relation.size(); j++){
            string col;
            for(int k = 0; k < relation.begin()->size(); k++)   if(i & (1 << k))    col += relation[j][k];
            if(!dic.insert(col).second)     break;
        }
        if(dic.size() == relation.size() && check(ans, i))  ans.push_back(i);
    }
    return ans.size();
}