#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    bool visit[1000000] = { 0 };
    queue<pair<int, int>> q;  q.push({x, 0});
    while(!q.empty()){
        pair<int, int> tmp = q.front();    q.pop();
        if(tmp.first == y)  return tmp.second;  else if(tmp.first > y || visit[tmp.first])  continue;
        visit[tmp.first] = true;
        q.push({tmp.first << 1, tmp.second + 1});
        q.push({tmp.first * 3, tmp.second + 1});
        q.push({tmp.first + n, tmp.second + 1});
    }
    return -1;
}
