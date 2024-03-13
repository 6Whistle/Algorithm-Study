#include <string>
#include <vector>
#include <cmath>

using namespace std;

int DC(long long l, long long r, long long div, long long cnt_1, int l_div = 0, int r_div = 0){
    if(!div)    return 1;
    if((l_div = l / div) == (r_div = r / div))  return l_div == 2 ? 0 : DC(l % div, r % div, div / 5, cnt_1 >> 2);
    return (l_div == 2 ? 0 : DC(l % div, div - 1, div / 5, cnt_1 >> 2))
            + (r_div == 2 ? 0 : DC(0, r % div, div / 5, cnt_1 >> 2))
            + (r_div - l_div - 1 - (l_div < 2 && r_div > 2)) * cnt_1;
}

int solution(int n, long long l, long long r) {     return DC(--l, --r, powl(5, n - 1), powl(4, n - 1));    }
