#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> map;
    for(int i = 0; i < players.size(); i++)     map.insert({players[i], i});
    for_each(callings.begin(), callings.end(), [&](string s){
        int tmp = map[s];
        swap(players[tmp - 1], players[tmp]);
        swap(map[s], map[players[tmp]]);
    });
    
    return players;
}