#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i = 1, size = 0, count = 1; i <= (s.size() >> 1); i++, size = 0, count = 1){
        string temp = s.substr(0, i);
        for(int j = i; j < s.size(); j += i)
            if(!s.compare(j, i, temp))     count++;
            else{   size += i + (int)(count == 1 ? 0 : to_string(count).size());     count = 1;    temp = s.substr(j, i);  }
        answer = min(answer, size + (int)temp.size() + (int)(count == 1 ? 0 : to_string(count).size()));
    }
    return answer;
}