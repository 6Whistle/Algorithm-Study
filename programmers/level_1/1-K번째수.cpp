#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(auto i : commands){
        temp.resize(i[1] - i[0] + 1);
        copy(array.begin()+ i[0] - 1, array.begin()+i[1], temp.begin());
        sort(temp.begin(), temp.end());
        answer.push_back(temp[i[2] - 1]);
    }
    return answer;
}