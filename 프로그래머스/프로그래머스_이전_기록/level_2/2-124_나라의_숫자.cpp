#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(;n > 0; n = n / 3 - (n % 3 == 0))
        answer.insert(answer.begin(), n % 3 == 0 ? '4' : n % 3 + '0');
    return answer;
}