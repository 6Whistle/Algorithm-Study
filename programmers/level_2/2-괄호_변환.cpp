#include <string>
#include <vector>

using namespace std;

void DFS(string &answer, string &p, int start, int end){
    if(start == end)    return;
    bool state = p[start] == '(' ? false : true;
    int i = start + 1, count[2] = { 0, 0 };    count[state]++;
    for(; count[0] != count[1]; i++){
        count[p[i] == '(' ? 0 : 1]++;
        if(count[0] < count[1]) state = true;
    }
    if(state){
        answer.push_back('(');  DFS(answer, p, i, end); answer.push_back(')');
        for(int j = start + 1; j < i - 1; j++)  answer.push_back(p[j] == '(' ? ')' : '(');
    }
    else{   answer += p.substr(start, i - start);   DFS(answer, p, i, end);   }
}

string solution(string p) {
    string answer = "";
    DFS(answer, p, 0, p.size());
    return answer;
}