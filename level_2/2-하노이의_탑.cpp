#include <string>
#include <vector>

using namespace std;

//(1 -> 3)_n = (1 -> 2)_n-1 + (1->3)_1 + (2 -> 3)_n-1
void sub_func(vector<vector<int>> &answer, short start, short end, short via, short n){
    if(n){
        sub_func(answer, start, via, end, n - 1);
        answer.push_back(vector<int>({start, end}));
        sub_func(answer, via, end, start, n - 1);        
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    sub_func(answer, 1, 3, 2, n);
    return answer;
}