#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer({0, (int)sequence.size()});
    for(int i = 0, sum = 0, cnt = 0; i < sequence.size();){
        for(sum += sequence[i++], cnt++; sum > k; sum -= sequence[i - cnt--]);
        if(sum == k && answer[1] - answer[0] >= cnt){
            answer = vector<int>({i - cnt, i - 1});
            if(cnt == 1)    break;
        }
    };
    return answer;
}