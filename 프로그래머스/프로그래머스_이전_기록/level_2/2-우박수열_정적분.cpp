#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> collatz(1, k);
    vector<double> graph, answer;
    for(int i = k; i != 1; collatz.push_back(i = (i & 1) ? (i * 3 + 1) : (i >> 1)));
    for(int i = 0; i < collatz.size() - 1; graph.push_back((collatz[i] + collatz[++i]) / 2.0));
    for_each(ranges.begin(), ranges.end(), [&](vector<int> &range){
        answer.push_back(range[0] > (int)graph.size() + range[1] ? -1 : accumulate(graph.begin() + range[0], graph.end() + range[1], 0.0));
    });
    return answer;
}