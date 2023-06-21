#include <string>
#include <vector>
#include <set>
#include <algorithm>
// #include <iostream>

using namespace std;

bool operator==(const pair<int, int> &a, const pair<int, int> &b){  return a.first == b.first && a.second == b.second;  }

void turn(pair<int, int> &cur_arrow, char state){
    if(state == 'S')    return;     else    swap(cur_arrow.first, cur_arrow.second);
    if((state == 'L' && cur_arrow.first) || (state == 'R' && cur_arrow.second)){    cur_arrow.first = -cur_arrow.first;     cur_arrow.second = -cur_arrow.second;   }
}

void move_pnt(pair<int, int> &cur_pnt, pair<int, int> &cur_arrow, const int row_max, const int col_max){
    cur_pnt.first = (cur_pnt.first + cur_arrow.first + row_max) % row_max;
    cur_pnt.second = (cur_pnt.second + cur_arrow.second + col_max) % col_max;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer(1, 0);
    vector<pair<int, int>> arrows({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
    set<pair<pair<int, int>, pair<int, int>>> cycles;
    for_each(arrows.begin(), arrows.end(), [&](pair<int, int> arrow){
        set<pair<pair<int, int>, pair<int, int>>> past;
        pair<int, int> cur_pnt = {0, 0}, cur_arrow = arrow;
        // cout << "case : " << arrow.first << ", " << arrow.second << endl;
        while((past.insert({cur_pnt, cur_arrow})).second && cycles.find({cur_pnt, cur_arrow}) == cycles.end()){  
            move_pnt(cur_pnt, cur_arrow, grid.size(), grid.begin()->size());
            turn(cur_arrow, grid[cur_pnt.first][cur_pnt.second]);
            // cout << "pnt(" << cur_pnt.first << ", " << cur_pnt.second << ")\t arrow : " << (cur_arrow.first == 1 ? "D" : cur_arrow.first == -1 ? "U" : cur_arrow.second == 1 ? "R" : "L") << endl;
        }
        // cout << "-------------------------------------------------" << endl;
        if(cur_pnt.first || cur_pnt.second || cur_arrow != arrow)  return;
        for(auto i = past.begin(); i != past.end(); i++)    if(!(cycles.insert(*i)).second)  return;
        if(answer.back() == past.size())    answer.push_back(past.size());
        else if(answer.back() < past.size()){   answer.clear(); answer.push_back(past.size());  }
    });
    return answer;
}

/*
    S case -> Continue

    L case
    1, 0(down) -> 0, 1(right)
    -1, 0(up) -> 0, -1(left)
    0, 1(right) -> -1, 0(up)
    0, -1(left) -> 1, 0(down)

    R case
    1, 0(down) -> 0, -1(left)
    -1, 0(up) -> 0, 1(right)
    0, 1(right) -> 1, 0(down)
    0, -1(left) -> -1, 0(up)
*/