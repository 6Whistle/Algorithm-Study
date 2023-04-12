#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n & 0x1)   return 0;
    long long a = 3, b = 1;
    for(int i = 2; i < n; i += 2){  swap(a, b); a = ((b << 2) - a)% 1000000007;  }
    return a;
}