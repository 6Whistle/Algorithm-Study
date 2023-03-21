#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, end = 0;
    for(auto i = section.begin(); i < section.end(); i++){
        if(end > *i)    continue;
        answer += 1;    end = *i + m;
    }
    return answer;
}