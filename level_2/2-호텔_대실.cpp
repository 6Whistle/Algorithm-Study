#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0, t_table[1450] = { 0 };
    for_each(book_time.begin(), book_time.end(), [&](vector<string> &t_pair){
        ++t_table[stoi(t_pair[0].substr(0, 2)) * 60 + stoi(t_pair[0].substr(3, 2))];
        --t_table[stoi(t_pair[1].substr(0, 2)) * 60 + stoi(t_pair[1].substr(3, 2)) + 10];
    });
    for(int i = 0, tmp = 0; i < 1450; i++)   answer = max(answer, (tmp += t_table[i]));
    return answer;
}