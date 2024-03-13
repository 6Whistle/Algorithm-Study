#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> solver(3, vector<int>());
    vector<int> answer, temp(3, 0);

    solver[0].assign({1, 2, 3, 4, 5});
    solver[1].assign({2, 1, 2, 3, 2, 4, 2, 5});
    solver[2].assign({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});

    for(int i = 0; i < answers.size(); i++)
        for(int j = 0; j < solver.size(); j++)
            if(answers[i] == solver[j][i % solver[j].size()])   temp[j]++;

    auto p = max_element(temp.begin(), temp.end());
    for(int i = 0; i < 3; i++)    if(temp[i] == *p)  answer.push_back(i + 1);

    return answer;
}