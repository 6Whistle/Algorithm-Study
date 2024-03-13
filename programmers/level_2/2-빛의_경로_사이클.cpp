#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arrows({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

void move_and_turn(vector<string> &grid, tuple<int, int, int> &cur_pnt){
    get<0>(cur_pnt) = (get<0>(cur_pnt) + arrows[get<2>(cur_pnt)].first + grid.size()) % grid.size();
    get<1>(cur_pnt) = (get<1>(cur_pnt) + arrows[get<2>(cur_pnt)].second + grid.begin()->size()) % grid.begin()->size();
    get<2>(cur_pnt) = (get<2>(cur_pnt) + 4 + (grid[get<0>(cur_pnt)][get<1>(cur_pnt)] == 'L' ? -1 : grid[get<0>(cur_pnt)][get<1>(cur_pnt)] == 'R' ? 1 : 0)) % 4;
}

void find_cycle(vector<vector<short>> &table, vector<string> &grid, vector<int> &answer, const int i, const int j, const int k, int cnt = 0){
    tuple<int, int, int> cur_pnt = {i, j, k};
    for(; !(table[get<0>(cur_pnt)][get<1>(cur_pnt)] & (1 << get<2>(cur_pnt))); cnt++){  table[get<0>(cur_pnt)][get<1>(cur_pnt)] |= (1 << get<2>(cur_pnt));  move_and_turn(grid, cur_pnt);   }
    if(cur_pnt != tuple<int, int, int>{i, j, k} || !cnt)    return;
    answer.push_back(cnt);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<short>> table(grid.size(), vector<short>(grid.begin()->size(), 0));
    for(int i = 0; i < grid.size(); i++)    for(int j = 0; j < grid.begin()->size(); j++)   for(int k = 0; k < 4; k++)  find_cycle(table, grid, answer, i, j, k);
    sort(answer.begin(), answer.end());
    return answer;
}