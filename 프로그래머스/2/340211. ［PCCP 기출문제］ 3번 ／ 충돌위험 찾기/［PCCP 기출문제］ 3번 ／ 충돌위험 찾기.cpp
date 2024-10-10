#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int crash = 0;
    map<tuple<int, int, int>, int> m;
    for_each(routes.begin(), routes.end(), [&](vector<int> route){
        int time = 0;
        for(int i = 0; i < route.size() - 1; i++){
            for(vector<int> cur = points[route[i] - 1], des = points[route[i+1] - 1]; cur != des; time++){
                m[{cur[0], cur[1], time}]++;
                cur = {
                        cur[0] == des[0] ? cur[0] : cur[0] > des[0] ? cur[0] - 1 : cur[0] + 1,
                        cur[0] != des[0] ? cur[1] : cur[1] > des[1] ? cur[1] - 1 : cur[1] + 1
                      };
            }
        }
        m[{points[route.back() - 1][0], points[route.back() - 1][1], time}]++;
    });
    for_each(m.begin(), m.end(), [&](pair<tuple<int, int, int>, int> tmp){  crash += tmp.second > 1;    });
    
    return crash;
}