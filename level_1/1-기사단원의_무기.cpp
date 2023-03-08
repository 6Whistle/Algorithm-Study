#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> knight(number, 0);
    for(int i = 0; i < number; i++){
        for(int j = i + 1; j < number + 1; j += (i + 1))    knight[j - 1]++;
        answer += knight[i] > limit ? power : knight[i];
    }
    return answer;
}