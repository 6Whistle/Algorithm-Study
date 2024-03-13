#include <string>
#include <vector>

using namespace std;

int count(int t){    return t * 719 / 43200 + t * 59 / 3600 - (t >= 43200 ? 2 : 1);    }

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int t1 = h1 * 3600 + m1 * 60 + s1, t2 = h2 * 3600 + m2 * 60 + s2;
    return count(t2) - count(t1) + (!(t1 * 719 % 43200) || !(t1 * 59 % 3600));
}