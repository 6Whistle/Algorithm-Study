#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer({(int)wallpaper.size() - 1, (int)wallpaper.begin()->size() - 1, 0, 0});
    for(int i = 0; i < wallpaper.size(); i++)
        for(int j = 0; j < wallpaper[i].size(); j++)
            if(wallpaper[i][j] == '#'){   
                answer[0] = min(i, answer[0]);  answer[1] = min(j, answer[1]);
                answer[2] = max(i, answer[2]);  answer[3] = max(j, answer[3]);
            }
    answer[2]++;    answer[3]++;
    return answer;
}