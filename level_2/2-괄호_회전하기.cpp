#include <string>
#include <vector>

using namespace std;

int check_string(string &s, int &begin, int &size){
    string st;
    int sub_cnt = 0;
    for(int i = begin; i < begin + size; i++, sub_cnt += st.empty())
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')   st.push_back(s[i]);
        else if(s[i] == (st.back() + 1) || s[i] == (st.back() + 2))     st.pop_back();
        else    return 0;
    return (st.empty()) ? sub_cnt : 0;
}

int solution(string s) {
    s += s;
    for(int i = 0, size = s.size() >> 1, answer; i < size; i++)    if(answer = check_string(s, i, size))   return answer;
    return 0;
}