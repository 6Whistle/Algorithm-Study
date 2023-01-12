#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int cnt = 0, money = 0;
    sort(d.begin(), d.end());
    for(; cnt < d.size() && d[cnt] + money <= budget; money += d[cnt++]);
    return cnt;
}
