#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int x, y, tx, ty;
    int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while(!bfs.empty() && maps.back().back() == 1){
        x = bfs.front().first;   y = bfs.front().second;      bfs.pop();
        for(int i = 0; i < 4; i++){
            tx = dx[i] + x; tx = tx < 0 ? 0 : tx == maps.size() ? tx - 1 : tx;
            ty = dy[i] + y; ty = ty < 0 ? 0 : ty == maps.begin()->size() ? ty - 1 : ty;
            if(maps[tx][ty] == 0)   continue;
            if(maps[tx][ty] > maps[x][y] + 1){
                maps[tx][ty] = maps[x][y] + 1;
                bfs.push({tx, ty});
            }
        }
    }
    return maps.back().back() == 1 ? -1 : maps.back().back();
}