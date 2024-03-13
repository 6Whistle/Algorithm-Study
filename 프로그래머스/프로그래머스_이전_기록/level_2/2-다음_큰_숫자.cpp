#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int lb = n & -n, n_1 = n + lb;
    return n_1 | ((n_1 ^ n) / lb) >> 2;
}
