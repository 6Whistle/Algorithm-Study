#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);
    generate(answer.begin(), answer.end(), [x, n = 1]() mutable { return static_cast<long long>(x * n++); });
    return answer;
}