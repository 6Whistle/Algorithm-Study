#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int m_x[4] = {-1, 1, 0, 0}, m_y[4] = {0, 0, -1, 1};

int BFS(vector<string> maps, int i, int j, char end_char, int tmp = -1){
    queue<tuple<int, int, int>> q;  q.push({i, j, 0});
    for(int x, y; !q.empty(); q.pop()){
        if((x = get<0>(q.front())) < 0 || x == maps.size() || (y = get<1>(q.front())) < 0 || y == maps.begin()->size() || maps[x][y] == 'X')    continue;
        if(maps[x][y] == end_char)  return get<2>(q.front());   else    maps[x][y] = 'X';
        for(int k = 0; k < 4; k++)  q.push({x + m_x[k], y + m_x[k], get<2>(q.front()) + 1});
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer[2] = { 0 };
    for(int i = 0; i < maps.size(); i++)    for(int j = 0; j < maps[i].size(); j++) if(maps[i][j] == 'L'){  answer[0] = BFS(maps, i, j, 'S'), answer[1] = BFS(maps, i, j, 'E');   break;  }
    return answer[0] > 0 && answer[1] > 0 ? answer[0] + answer[1] : -1;
}