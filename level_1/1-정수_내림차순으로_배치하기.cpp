#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string temp = to_string(n);
    sort(temp.begin(), temp.end(), greater<char>());
    return stoll(temp);
}