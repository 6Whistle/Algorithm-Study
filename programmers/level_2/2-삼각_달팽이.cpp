#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> &lines, int start, int end, int num){
    if(start >= end)    return;
    for(int i = start; i < end; i++)   lines[i].push_back(num++);
    for(int i = start + 1; i < end; i++)    lines[end - 1].push_back(num++);
    DFS(lines, start + 2, end - 1, end - start + num - 2);
    for(int i = end - 2; i > start; i--)   lines[i].push_back(num++);
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> lines(n, vector<int>());
    DFS(lines, 0, n, 1);
    for_each(lines.begin(), lines.end(), [&](vector<int> temp){ answer.insert(answer.end(), temp.begin(), temp.end());   });
    return answer;
}