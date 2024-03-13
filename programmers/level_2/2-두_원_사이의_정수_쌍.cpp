#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = r2 - r1 + 1, rr1 = powl(r1, 2), rr2 = powl(r2, 2), ii1 = 1;
    for(int i = 1; i < r2; ii1 = powl(++i, 2)){
        answer += floor(sqrt(rr2 - ii1));
        if(rr1 > ii1)   answer -= ceil(sqrt(rr1 - ii1)) - 1;
    }
    return answer * 4;
}