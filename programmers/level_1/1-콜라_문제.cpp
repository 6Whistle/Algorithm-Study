#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int count = 0;
    while(n >= a){
        int coke = (n / a) * b;
        count += coke;
        n = (n % a) + coke;
    }
    return count;
}