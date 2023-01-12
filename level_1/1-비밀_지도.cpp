#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string());
    for(int i = 0; i < n; i++){
        int temp = arr1[i] | arr2[i];
        for(int j = n - 1; j >= 0; j--, temp = temp >> 1)
            answer[i][j] += temp & 1 ? '#' : ' ';
    }
    return answer;
}