#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void update(vector<int> &target, int num){  target.back() = min(target.back(), num);  };

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    int x[4] = {-startX, startX, (m << 1) - startX, startX}, y[4] = {startY, -startY, startY, (n << 1) - startY};
    for_each(balls.begin(), balls.end(), [&](vector<int> &ball){
        answer.push_back(numeric_limits<int>::max());
        if(ball[0] != startX || ball[1] > startY)   update(answer, pow(ball[0] - startX, 2) + pow(ball[1] + startY, 2));
        if(ball[0] != startX || ball[1] < startY)   update(answer, pow(ball[0] - startX, 2) + pow((n << 1) - ball[1] - startY, 2));
        if(ball[1] != startY || ball[0] > startX)   update(answer, pow(ball[0] + startX, 2) + pow(ball[1] - startY, 2));
        if(ball[1] != startY || ball[0] < startX)   update(answer, pow((m << 1) - ball[0] - startX, 2) + pow(ball[1] - startY, 2));
    });
    return answer;
}