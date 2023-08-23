#include <string>
#include <vector>
#include <numeric>

using namespace std;

int DFS(vector<int> picks, vector<string> &minerals, int pnt){
    int cnt[3] = { 0 }, end = min(5 + pnt, (int)minerals.size()), ret = numeric_limits<int>::max();
    if(!picks[0] && !picks[1] && !picks[2] || pnt >= minerals.size()) return 0;
    for(int i = pnt; i < end; i++){
        if(picks[0])   cnt[0]++;
        if(picks[1])   cnt[1] += minerals[i] == "diamond" ? 5 : 1;
        if(picks[2])   cnt[2] += minerals[i] == "diamond" ? 25 : minerals[i] == "iron" ? 5 : 1;
    }
    for(int i = 0; i < 3; i++)  if(picks[i]){   picks[i]--;   ret = min(ret, cnt[i] + DFS(picks, minerals, end));  picks[i]++;   }
    return ret;
}

int solution(vector<int> picks, vector<string> minerals) {  return DFS(picks, minerals, 0); }