#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i = 0, sum = 0; i < (1 << numbers.size()); i++, sum = 0){
        for(int j = 0; j < numbers.size(); j++)     sum += (i & (1 << j)) ? numbers[j] : -numbers[j];
        answer += (sum == target);
    }
    return answer;
}