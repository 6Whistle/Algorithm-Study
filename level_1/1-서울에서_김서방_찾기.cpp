#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    answer += to_string(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin()); 
    return "김서방은 " + answer + "에 있다";
}