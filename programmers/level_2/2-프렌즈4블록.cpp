#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_table(int m, int n, vector<vector<short>> &table, int &count){
    int erase_count = 0;
    vector<vector<bool>> check(n, vector<bool>(m, false));
    for(int i = 0; i < m - 1; i++)
        for(int j = 0; j < n - 1; j++)
            if(table[j][i] != 0 && table[j][i] == table[j][i + 1] 
               && table[j][i] == table[j + 1][i] && table[j][i] == table[j + 1][i + 1]){
                erase_count += 4 - check[j][i] - check[j][i + 1] - check[j + 1][i];
                check[j][i] = check[j][i + 1] = check[j + 1][i] = check[j + 1][i + 1] = true;
            }
    count += erase_count;

    for(int i = m - 1; i > -1; i--)
        for(int j = n - 1; j > -1; j--)
            if(check[j][i]){    table[j].erase(table[j].begin() + i);   table[j].push_back(0);  }
    
    return erase_count;
}

int solution(int m, int n, vector<string> board) {
    int count = 0;
    vector<vector<short>> table(n, vector<short>(m, 0));
    for(int i = 0; i < m; i++)  for(int j = 0; j < n; j++)  table[j][i] = board[m - 1 - i][n - 1 - j];
    while(check_table(m, n, table, count));

    return count;
}
