#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int count = 0, temp;
    for(int i = 1; i <= n; i++){
        if(!((temp = (n << 1) - i * i + i) / (i << 1)))  return count;
        if(!(temp % (i << 1)))  count++;
    }
}