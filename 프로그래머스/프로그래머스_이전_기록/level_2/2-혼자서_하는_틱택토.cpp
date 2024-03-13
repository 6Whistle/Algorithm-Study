#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    bool state[3] = { 0 };
    int cnt[3] = { 0 };
    for(int i = 0; i < 3; i++)  for(int j = 0; j < 3; j++)  cnt[board[i][j] == 'O' ? 0 : board[i][j] == 'X' ? 1 : 2]++; 
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])    state[board[i][0] == 'O' ? 0 : board[i][0] == 'X' ? 1 : 2] = true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])    state[board[0][i] == 'O' ? 0 : board[0][i] == 'X' ? 1 : 2] = true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])    state[board[0][0] == 'O' ? 0 : board[0][0] == 'X' ? 1 : 2] = true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])    state[board[0][2] == 'O' ? 0 : board[0][2] == 'X' ? 1 : 2] = true;
    
    if(cnt[0] != cnt[1] && cnt[0] != cnt[1] + 1 || state[0] == true && state[1] == true
       || state[0] == true && cnt[0] == cnt[1] || state[1] == true && cnt[0] == cnt[1] + 1)     return false;
    
    return true;
}