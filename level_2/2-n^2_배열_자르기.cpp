#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(int div = left / n, mod = left % n; left <= right; left++, div = left / n, mod = left % n)  answer.push_back((mod < div ? div : mod) + 1);
    return answer;
}