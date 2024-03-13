#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> &lion, vector<int> &answer, vector<int> &info, int &lion_max, int n, int pnt){
    if(n && pnt < 10){   
        if(info[pnt] + 1 <= n){   lion[pnt] = info[pnt] + 1;    DFS(lion, answer, info, lion_max, n - info[pnt] - 1, pnt + 1);    }
        lion[pnt] = 0;  DFS(lion, answer, info, lion_max, n, pnt + 1);
        return;
    }
    int sum = 0, min_pnt = -1;
    lion[10] = n;
    for(int i = lion.size() - 1; i >= 0; i--){
        sum += (10 - i) * (lion[i] > info[i] ? 1 : !info[i] ? 0 : -1);
        if(min_pnt == -1 && answer[i] != lion[i])    min_pnt = i;
    }
    if(sum > lion_max || sum == lion_max && lion[min_pnt] > answer[min_pnt]){ answer = lion;  lion_max = sum; }
}

vector<int> solution(int n, vector<int> info) {
    int lion_max = -55;
    vector<int> answer(info), lion(11, 0);
    DFS(lion, answer, info, lion_max, n, 0);
    return lion_max > 0 ? answer : vector<int>(1, -1);
}