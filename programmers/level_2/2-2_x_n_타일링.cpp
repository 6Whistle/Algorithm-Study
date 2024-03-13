#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long a = 0, b = 1;
    for(int i = 0;i < n; i++){  swap(a, b);    b += a;    b %= 1000000007; }
    return b;     
}