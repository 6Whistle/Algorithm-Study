#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

void binary_transform(string &s, vector<int> &answer){
    int i = 0;
    for_each(s.begin(), s.end(), [&](char c){ c == '1' ? i++ : 0; });
    answer[0]++; answer[1] += s.length() - i;
    s.clear();
    for(; i; i/=2)
        s.append(to_string(i % 2), 0);
    if(s.size() != 1) binary_transform(s, answer);
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    binary_transform(s, answer);
    return answer;
}