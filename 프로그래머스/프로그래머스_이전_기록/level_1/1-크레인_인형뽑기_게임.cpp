#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> bucket;
    vector<int>::iterator iter = moves.begin();
    int answer = 0, temp, i, doll;
    for_each(moves.begin(), moves.end(), [&](int temp){
        for(i = 0, temp-- ;board[i][temp] == 0 && i < board.size() - 1; i++);
        doll = board[i][temp];  board[i][temp] = 0;

        if(!bucket.empty() && doll == bucket.top()){  answer += 2;   bucket.pop();   }
        else if(doll != 0)  bucket.push(doll);
    });
    
    return answer;
}