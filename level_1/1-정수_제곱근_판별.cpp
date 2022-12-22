#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = floor(sqrt(n));    
    return powl(answer, 2) == n ? pow(answer + 1, 2) : -1;
}