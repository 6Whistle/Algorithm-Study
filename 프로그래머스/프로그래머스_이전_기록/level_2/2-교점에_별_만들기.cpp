#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    long x_range[2] = { numeric_limits<long>::max(), numeric_limits<long>::min() }, y_range[2] = { x_range[0], x_range[1] };
    vector<pair<long, long>> pnt;
    for(int i = 0; i < line.size(); i++)
        for(long j = 0, tmp; j < line.size(); j++)
            if(tmp = (long)line[i][0] * (long)line[j][1] - (long)line[i][1] * (long)line[j][0]){
                double x = ((long)line[i][1] * (long)line[j][2] - (long)line[i][2] * (long)line[j][1]) / (double)tmp, y = ((long)line[i][2] * (long)line[j][0] - (long)line[i][0] * (long)line[j][2]) / (double)tmp;
                if(((int)floor(x) - (int)ceil(x)) || ((int)floor(y) - (int)ceil(y)))  continue;
                pnt.push_back({ (long)x, (long)y });
                x_range[0] = min(x_range[0], (long)x);     x_range[1] = max(x_range[1], (long)x);
                y_range[0] = min(y_range[0], (long)y);     y_range[1] = max(y_range[1], (long)y);
            }
    vector<string> answer(y_range[1] - y_range[0] + 1, string(x_range[1] - x_range[0] + 1, '.'));
    for_each(pnt.begin(), pnt.end(), [&](pair<long, long> &tmp){  answer[answer.size() - tmp.second + y_range[0] - 1][tmp.first - x_range[0]] = '*';  });
    return answer;
}