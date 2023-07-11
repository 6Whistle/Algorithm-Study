#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    vector<int> com;
    vector<bool> visit(cards.size(), false);
    for(int i = 1, cnt = 0; i <= visit.size(); i++, cnt = 0){
        for(int j = i; !visit[j - 1]; visit[j - 1] = true, j = cards[j - 1], cnt++);
        if(cnt)     com.push_back(cnt);
    }
    sort(com.begin(), com.end());
    return com.size() == 1 ? 0 : com[0] * com[1];
}