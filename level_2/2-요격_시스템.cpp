#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), [](vector<int> &a, vector<int> &b){ return a[0] < b[0];    });
    vector<int> tmp(targets[0]);
    for_each(targets.begin(), targets.end(), [&](vector<int> target){
        if(target[0] < tmp[1])  tmp[1] = min(tmp[1], target[1]);
        else{   answer++;   tmp = target;   }
    });
    return answer;
}