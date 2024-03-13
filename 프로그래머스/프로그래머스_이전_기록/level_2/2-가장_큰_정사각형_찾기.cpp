#include <vector>
#include <algorithm>
using namespace std;

// int check_square(vector<vector<int>> &board, int x, int y, int length){
//     if(x + length > board.size() || y + length > board.begin()->size())   return length - 1;
//     for(int i = 0; i < length; i++) if(!(board[x + i][y + length - 1] && board[x + length - 1][y + i]))     return length - 1;
//     return check_square(board, x, y, length + 1);
// }

// int solution(vector<vector<int>> board)
// {
//     int max_size = 0;
//     for(int i = 0; i + max_size < board.size(); i++)
//         for(int j = 0; j + max_size < board.begin()->size(); j++)
//             max_size = max(max_size, check_square(board, i, j, 1));
//     return max_size * max_size;
// }

int solution(vector<vector<int>> board)
{
    int max_size = 0;
    if(board.size() == 1 || board.begin()->size() == 1){
        for(vector<int> &row : board)   for(int &i : row)   if(i)   return i;
        return 0;
    }

    for(int i = 1; i < board.size(); i++)
        for(int j = 1; j < board.begin()->size(); j++){
            if(board[i][j]) board[i][j] = min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
            max_size = max(max_size, board[i][j]);
        }
        
    return max_size * max_size;
}