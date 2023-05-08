#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    int cycle = 0;  p--;
    string num("0123456789ABCDEF"), answer;
    for(int i = 0, j; answer.size() < t; i++){
        string temp;
        for(j = i; j / n > 0; j /= n)  temp += num[j % n];
        temp += num[j];
        for(j = temp.size() - 1; j >= 0 && answer.size() < t; j--, cycle = ++cycle % m)
            if(cycle == p)  answer += temp[j];
    }
    return answer;
}