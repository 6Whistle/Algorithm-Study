#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int correct[2] = { 0 };
    for_each(lottos.begin(), lottos.end(), [&](int temp){
        if(temp == 0)   return;
        correct[find(win_nums.begin(), win_nums.end(), temp) == win_nums.end() ? 1 : 0]++;
    });
    return vector({1 + correct[1] == 7 ? 6 : 1 + correct[1] , 7 - correct[0] == 7 ? 6 : 7 - correct[0]});
}