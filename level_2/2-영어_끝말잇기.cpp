#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> dic{words[0]};
    for(int i = 1; i < words.size(); i++)
        if(!dic.insert(words[i]).second && words[i - 1].back() != words[i][0])   return vector<int>{i % n + 1, i / n + 1};
    return vector<int>{0, 0};
}