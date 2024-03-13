#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer;
    for(int i = 0; i < food.size(); i++)
        answer.insert(answer.size() / 2, string((size_t)(food[i] & 0xFFFE), '0' + i));
    answer.insert(answer.size() / 2, "0");
    return answer;
}