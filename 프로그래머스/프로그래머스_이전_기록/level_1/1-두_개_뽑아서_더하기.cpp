#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> sum;
    for(auto i = numbers.begin(); i < numbers.end(); i++){
        for_each(i + 1, numbers.end(), [&](int j){sum.insert(*i + j);});
    }
    answer.assign(sum.begin(), sum.end());

    return answer;
}