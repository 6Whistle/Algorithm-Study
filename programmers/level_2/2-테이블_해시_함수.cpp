#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;  col--;
    auto cmp = [&col](vector<int> a, vector<int> b){  return a[col] == b[col] ? a[0] > b[0] : a[col] < b[col];  };
    sort(data.begin(), data.end(), cmp);
    for(int i = row_begin; i < row_end; i++)    answer ^= accumulate(data[i - 1].begin(), data[i - 1].end(), 0, [&i](int a, int b){    return a + (b % i); });
    
    return answer;
}