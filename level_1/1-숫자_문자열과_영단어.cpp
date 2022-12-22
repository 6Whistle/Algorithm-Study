#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;


int solution(string s){
    vector<string> eng_num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 10; i++)
        s = regex_replace(s, regex(eng_num[i]), to_string(i));

    return stoi(s);
}