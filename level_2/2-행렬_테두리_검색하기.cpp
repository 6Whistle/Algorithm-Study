#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> table(rows, vector<int>(columns));
    vector<int> answer;
    for(int i = 0; i < rows; i++)   generate(table[i].begin(), table[i].end(), [i = i * columns + 1]() mutable {  return i++; });
    for_each(queries.begin(), queries.end(), [&](vector<int> &query){
        for_each(query.begin(), query.end(), [](int &i){    i--;    });
        answer.push_back(table[query[0]][query[1]]);
        int temp = answer.back();
        for(int i = query[0]; i < query[2]; i++){    table[i][query[1]] = table[i + 1][query[1]];   answer.back() = min(answer.back(), table[i][query[1]]);    }
        for(int i = query[1]; i < query[3]; i++){    table[query[2]][i] = table[query[2]][i + 1];   answer.back() = min(answer.back(), table[query[2]][i]);    }
        for(int i = query[2]; i > query[0]; i--){    table[i][query[3]] = table[i - 1][query[3]];   answer.back() = min(answer.back(), table[i][query[3]]);    }
        for(int i = query[3]; i > query[1] + 1; i--){    table[query[0]][i] = table[query[0]][i - 1];   answer.back() = min(answer.back(), table[query[0]][i]);    }
        table[query[0]][query[1] + 1] = temp;
    });
    return answer;
}