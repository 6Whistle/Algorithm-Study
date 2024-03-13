#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(int x) {
    int answer = 0;
    string s = to_string(x);
    for_each(s.begin(), s.end(), [&](char temp){ answer += atoi(&temp); });
    return (x % answer) == 0;
}