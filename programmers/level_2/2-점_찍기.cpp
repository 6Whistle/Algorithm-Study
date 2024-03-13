#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0, pd = powl(d, 2);
    for(int i = 0; i <= d / k; i++)     answer += (int)sqrtl(pd - powl(i * k, 2)) / k + 1;
    return answer;   
}