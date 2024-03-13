#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    vector<char> st;
    for_each(s.begin(), s.end(), [&](char c){   (!st.empty() && st.back() == c) ? st.pop_back() : st.push_back(c);   });

    return st.empty();
}