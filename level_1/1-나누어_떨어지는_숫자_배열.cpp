#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for_each(arr.begin(), arr.end(), [&](int a){  if(a % divisor == 0)    answer.push_back(a);});
    answer.empty() ? answer.push_back(-1) : sort(answer.begin(), answer.end());
    return answer;
}