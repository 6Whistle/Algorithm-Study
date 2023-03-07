#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> s;
    for(int i : ingredient){
        if(s.size() > 2 && *(s.end() - 3) == 1 && *(s.end() - 2) == 2 && *(s.end() - 1) == 3 && i == 1){
            answer++;
            for(int j = 0; j < 3; j++)  s.pop_back();
        }   else    s.push_back(i);
    }
    return answer;
}