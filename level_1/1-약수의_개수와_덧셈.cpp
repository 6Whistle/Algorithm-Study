#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(;left <= right; left++){ answer += pow(round(sqrt(left)), 2) == left ? -left : left; }
    return answer;
}