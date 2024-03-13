#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1, i, tmp;
    sort(dungeons.begin(), dungeons.end());
    do {
        for(i = 0, tmp = k; i < dungeons.size() && tmp >= dungeons[i][0]; tmp -= dungeons[i++][1]);
        answer = max(answer, i);
    } while(next_permutation(dungeons.begin(), dungeons.end()) && answer < dungeons.size());
    return answer;
}