#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int mx[4] = { -1, 0, 1, 0}, my[4] = {0, -1, 0, 1}; 

pair<int, int> findR(vector<string> &board){ 
    for(int x = 0; x < board.size(); x++)    for(int y = 0; y < board[x].size(); y++)   
        if(board[x][y] == 'R')  return { x, y };  
}

pair<int, int> moveEnd(vector<string> &board, int x, int y, int k){
    for(int i, j; (i = x + mx[k]) >= 0 && i < board.size() && (j = y + my[k]) >= 0 && j < board.begin()->size() && board[i][j] != 'D'; x = i, y = j);
    return { x, y };
}

int BFS(vector<string> board, int x, int y){
    queue<tuple<int, int, int>> q;  q.push({x, y, 0});
    for(int i, j, cnt; !q.empty(); q.pop()){
        i = get<0>(q.front()), j = get<1>(q.front()), cnt = get<2>(q.front());
        if(board[i][j] == 'G')  return cnt; else    cnt++;
        if(board[i][j] == 'X')  continue;   else    board[i][j] = 'X';
        for(int k = 0; k < 4; k++){
            pair<int, int> tmp = moveEnd(board, i, j, k);
            if(tmp.first != i || tmp.second != j)   q.push({tmp.first, tmp.second, cnt});
        }
    }
    return -1;
}

int solution(vector<string> board) {
    pair<int, int> pnt = findR(board);
    return BFS(board, pnt.first, pnt.second);
}