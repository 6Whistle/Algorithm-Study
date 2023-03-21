#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool bfs(vector<string> &room, pair<int, int> p){
    queue<pair<int, int> > q;
    vector<vector<int> > visited(5, vector<int>(5, 0));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    visited[p.first][p.second] = 1;
    q.push(p);
    for(;!q.empty(); q.pop()){
        int x = q.front().first, y = q.front().second;
        for(int i = 0; i < 4; i++){
            int moved_x = x + dx[i], moved_y = y + dy[i];
            if(moved_x < 0 || moved_x > 4 || moved_y < 0 || moved_y > 4 || visited[moved_x][moved_y] || room[moved_x][moved_y] == 'X')    continue;
            if(room[moved_x][moved_y] == 'P')   return false;
            if(visited[x][y] != 2){
                q.push(make_pair(moved_x, moved_y));
                visited[moved_x][moved_y] = visited[x][y] + 1;
            }
        }
    }
    return true;
}

int check_room(vector<string> &room){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(room[i][j] == 'P' && !bfs(room, make_pair(i, j)))
                return 0;
        
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for_each(places.begin(), places.end(), [&](vector<string> i){ answer.push_back(check_room(i)); });
    return answer;
}