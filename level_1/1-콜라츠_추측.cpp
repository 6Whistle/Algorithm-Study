#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int i = 0;  long long temp = num;
    for(; i < 500 && temp != 1; i++)    temp = (temp & 1) ? (temp * 3 + 1) : (temp >> 1);
    return temp == 1 ? i : -1;
}