#include <string>
#include <vector>

using namespace std;
int arrow[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    auto in_boundary = [&board](int a, int b, int size){ return a + b >= 0 && a + b < size; };
    for(int i = 0; i < 4; i++)
        answer += (in_boundary(h, arrow[i][0], board.size()) && in_boundary(w, arrow[i][1], board.begin()->size()) ?
        (board[h][w] == board[h + arrow[i][0]][w + arrow[i][1]]) : 0);
    return answer;
}