#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    regex re(",");
    pair<string, int> max_value("(None)", 0);
    
    for(int i = 0; i < m.size() - 1; i++)   if(m[i + 1] == '#') {   m.erase(i+1, 1);  m[i] += 8;    }

    for_each(musicinfos.begin(), musicinfos.end(), [&](string music){
        sregex_token_iterator it(music.begin(), music.end(), re, -1);
        vector<string> split_string(it, {});
        for(int i = 0; i < split_string[3].size() - 1; i++)   if(split_string[3][i + 1] == '#') {   split_string[3].erase(i+1, 1);  split_string[3][i] += 8;    }

        int time = (stoi(split_string[1].substr(0, 2)) - stoi(split_string[0].substr(0, 2))) * 60
                 + (stoi(split_string[1].substr(3, 2)) - stoi(split_string[0].substr(3, 2))) + 1;
        
        string c_str;
        while(c_str.size() < time) c_str += split_string[3].substr(0, time - c_str.size());
        
        for(int i = 0; i < split_string[3].size(); i++){
            if(c_str.size() - i < m.size()) return;
            if(!m.compare(c_str.substr(i, m.size())) && max_value.second < time){
                max_value = make_pair(split_string[2], time);
                return;
            }
        }
    });
    return max_value.first;
}