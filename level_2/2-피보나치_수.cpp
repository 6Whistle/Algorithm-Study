#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cur, before_1 = 1, before_2 = 1;
    for(int i = 0; i < n - 2; i++){
        cur = (before_1 + before_2) % 1234567;
        before_2 = before_1; before_1 = cur;
    }
    return cur;
}