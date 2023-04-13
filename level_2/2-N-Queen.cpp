#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_queue(vector<int> &q, int i){
    for(int k = 0; k < i; k++)
        if(i - k == abs(q[k] - q[i]) || q[k] == q[i])  return false;
    return true;
}

void DFS(vector<int> &q, int n, int i, int &count){
    if(i == n)  {  count++;    return; }
    for(int j = 0; j < n; j++){
        q[i] = j;
        if(check_queue(q, i))   DFS(q, n, i + 1, count);
    }
}

int solution(int n) {
    vector<int> q(n, 0);
    int answer = 0;
    DFS(q, n, 0, answer);
    return answer;
}
