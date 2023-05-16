#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location) {
    map<int, int> dic;
    pair<map<int, int>::iterator, bool> iter;
    for(int i = 0; i < priorities.size(); i++)   if(!(iter = dic.insert({priorities[i], 1})).second)    (iter.first->second)++;
    for(int i = 9, cur = 0, count = 0; i > 0; i--){
        for(int j = dic[i]; j > 0; j--){
            while(priorities[cur] != i) cur = ++cur % priorities.size();
            priorities[cur] = 0;  count++;
            if(cur == location) return count;
        }
    }
    return -1;
}