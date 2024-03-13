#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int min_change = 0, min_move = name.size() - 1;
    for_each(name.begin(), name.end(), [&](char c){min_change += min(c - 'A', 'Z' - c + 1);});
    string temp = name.substr(1, name.size() - 1) + name;
    for(int i = 0, j = i, middle = name.size() - 1; i < middle; i++, j = i){
        for(; temp[j] == 'A' && j < middle; j++);
        min_move = min(min_move, middle + i - j + min(middle - j, i));
    }
    return min_change + min_move;
}