#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>

using namespace std;

vector<int> oil_cnt(1, 0);
vector<vector<int>> mv = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 

void oil_check(vector<vector<int>> &land, vector<vector<int>> &table, int x, int y, int cnt = 1){
    if(!land[x][y] || table[x][y])      return;
    queue<pair<int, int>> bfs;
    for(bfs.push({x, y}), table[x][y] = oil_cnt.size(); !bfs.empty(); bfs.pop()){
        for_each(mv.begin(), mv.end(), [&](vector<int> arrow, int i = 0, int j = 0){
            if((i = bfs.front().first + arrow[0]) < 0 || i >= land.size())    return;
            if((j = bfs.front().second + arrow[1]) < 0 || j >= land.begin()->size())   return;
            if(land[i][j] == 1 && table[i][j] != oil_cnt.size()){    cnt++;     bfs.push({i, j});   table[i][j] = oil_cnt.size();   }
        });
    }
    oil_cnt.push_back(cnt);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    set<int> s;
    vector<vector<int>> table(land.size(), vector<int>(land.begin()->size(), 0));
    for(int j = 0; j < land.begin()->size(); j++, s.clear()){
        for(int i = 0; i < land.size(); s.insert(table[i++][j]))   oil_check(land, table, i, j);
        answer = max(answer, accumulate(s.begin(), s.end(), 0, [&](int a, int b){ return a + oil_cnt[b]; }));
    }
    return answer;
}