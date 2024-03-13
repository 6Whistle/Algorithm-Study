#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <tuple>

using namespace std;

#define SIZE 5

int solution(string dirs) {
    int cur_x = 0, cur_y = 0;
    set<tuple<int, int, int, int> > root;
    map<char, pair<int, int> > d_xy = {{'U', make_pair(0, 1)}, {'D', make_pair(0, -1)}, {'L', make_pair(-1, 0)}, {'R', make_pair(1, 0)}};
    for(char c : dirs){
        int moved_x = cur_x + d_xy[c].first, moved_y = cur_y + d_xy[c].second;
        if(max(moved_x, moved_y) > SIZE || min(moved_x, moved_y) < - SIZE)  continue;
        root.insert(make_tuple(cur_x, moved_x, cur_y, moved_y));
        root.insert(make_tuple(moved_x, cur_x, moved_y, cur_y));
        cur_x = moved_x, cur_y = moved_y;

    }
    
    return root.size() / 2;
}