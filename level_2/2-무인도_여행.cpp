#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<pair<int, int>> q;
    int m_x[4] = {-1, 1, 0, 0}, m_y[4] = {0, 0, -1, 1};
    for(int i = 0; i < maps.size(); i++)    for(int j = 0; j < maps.begin()->size(); j++)
        if(maps[i][j] != 'X'){
            answer.push_back(0);   q.push({i, j});
            for(;!q.empty(); q.pop()){
                if(q.front().first < 0 || q.front().first == maps.size() || q.front().second < 0 || q.front().second == maps.begin()->size() || maps[q.front().first][q.front().second] == 'X')    continue;
                for(int k = 0; k < 4; q.push({ q.front().first + m_x[k], q.front().second + m_y[k] }), k++);
                answer.back() += maps[q.front().first][q.front().second] - '0';
                maps[q.front().first][q.front().second] = 'X';
            }
        }
    sort(answer.begin(), answer.end());
    return answer.empty() ? vector<int>(1, -1) : answer;
}