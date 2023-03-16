#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<string>::iterator com[2];
    com[0] = cards1.begin();    com[1] = cards2.begin();
    for(string s : goal){
        if(com[0] != cards1.end() && com[0]->compare(s) == 0){ com[0]++;  continue; }
        if(com[1] != cards2.end() && com[1]->compare(s) == 0){ com[1]++;  continue; }
        return string("No");
    }
    return string("Yes");
}