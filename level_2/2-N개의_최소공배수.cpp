#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b) (a > b) ? a -= b : b -= a;
    return a;
}

int lcm(int a, int b){ return a * b / gcd(a, b); };

int solution(vector<int> arr) {
    int answer = 1;
    for_each(arr.begin(), arr.end(), [&](int i){ answer = lcm(answer, i); });
    return answer;
}