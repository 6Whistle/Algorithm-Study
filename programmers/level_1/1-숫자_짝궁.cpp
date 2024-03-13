#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

string solution(string X, string Y) {
    vector<int> compare_x(10, 0), compare_y(10, 0);
    for_each(X.begin(), X.end(), [&](char c){ compare_x[c - 48]++; });
    for_each(Y.begin(), Y.end(), [&](char c){ compare_y[c - 48]++; });

    string com;
    for(int i = 9; i >= 0; i--) com += string(min(compare_x[i], compare_y[i]), i + 48);
    return com.empty() ? to_string(-1) : find_if(com.begin(), com.end(), [](char c){ return c != '0'; }) == com.end() ? to_string(0) : com;
}