#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> mv({{0, -1}, {0, 1}, {-1, 0}, {1, 0}});

vector<int> find_cur(vector<string> &park){  for(int i = 0; i < park.size(); i++)    for(int j = 0; j < park.begin()->size(); j++)   if(park[i][j] == 'S')   return {{i, j}};  };

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> cur = find_cur(park);  
    for_each(routes.begin(), routes.end(), [&](string s){
        int dir = s[0] == 'W' ? 0 : s[0] == 'E' ? 1 : s[0] == 'N' ? 2 : 3;
        vector<int> tmp(cur);
        for(int i = 0; i < s[2] - '0'; i++){
            tmp[0] += mv[dir].first; tmp[1] += mv[dir].second;
            if(min(tmp[0], tmp[1]) < 0 || tmp[0] >= park.size() || tmp[1] >= park.begin()->size() || park[tmp[0]][tmp[1]] == 'X')     return;
        }
        cur = tmp;
    });
    return cur;
}