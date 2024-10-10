#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int crash = 0;
    map<int, int> m;
    for_each(routes.begin(), routes.end(), [&](vector<int> route){
        int time = 0;
        for(int i = 0; i < route.size() - 1; i++){
            for(vector<int> cur = points[route[i] - 1], des = points[route[i+1] - 1]; cur != des; time++){
                m[(cur[0] << 8) | cur[1] | (time << 16)]++;
                cur = {
                        cur[0] == des[0] ? cur[0] : cur[0] > des[0] ? cur[0] - 1 : cur[0] + 1,
                        cur[0] != des[0] ? cur[1] : cur[1] > des[1] ? cur[1] - 1 : cur[1] + 1
                      };
            }
        }
        m[(points[route.back() - 1][0] << 8) | points[route.back() - 1][1] | (time << 16)]++;
    });
    for_each(m.begin(), m.end(), [&](pair<int, int> tmp){  crash += tmp.second > 1;    });
    
    return crash;
}