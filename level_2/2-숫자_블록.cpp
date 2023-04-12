#include <string>
#include <vector>

using namespace std;

int find_div(long long value){
    vector<int> temp;
    for(long long i = 2; i * i <= value; i++)
        if(value % i == 0){
            temp.push_back(i);
            if(value / i <= 10000000)  return value / i;
        }
    return temp.empty() ? (value == 1 ? 0 : 1) : temp.back();
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(;begin <= end; begin++)     answer.push_back(find_div(begin));
    return answer;
}