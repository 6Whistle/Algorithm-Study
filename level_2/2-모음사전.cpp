#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string word) {
    int answer = 0, num = 781;
    unordered_map<char, int> dic({{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}});
    for_each(word.begin(), word.end(), [&](char c){     answer += 1 + dic[c] * num;     num /= 5;    });
    return answer;
}