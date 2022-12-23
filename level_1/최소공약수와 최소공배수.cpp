#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);
    answer[1] = n * m;
    if(n < m)   swap(n, m);
    while(m != 0){
        n -= m;
        if(n < m)   swap(n, m);
    }
    answer[0] = n;
    answer[1] /= n;
    return answer;
}