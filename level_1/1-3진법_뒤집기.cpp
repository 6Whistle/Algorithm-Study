#include <cmath>

using namespace std;

int solution(int n) {
    int temp = n, count = 0, answer = 0;
    for(; temp; count++, temp /= 3);
    temp = pow(3, count - 1);
    for(; n; n /= 3, temp /= 3) answer += temp * (n % 3);

    return answer;
}