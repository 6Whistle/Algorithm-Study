#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int answer[2] = { 0 }, discount[7];
    for(int i = 0x0; i < (0x1 << (emoticons.size() << 1)); i++){
        pair<int, int> sum(0, 0);
        for(int j = 0; j < emoticons.size(); discount[j++] = (1 + ((i >> (j << 1)) & 0x3)) * 10);
        for_each(users.begin(), users.end(), [&](vector<int> &user, int tmp = 0){
            for(int j = 0; j < emoticons.size() && tmp < user[1]; j++)  if(user[0] <= discount[j])    tmp += emoticons[j] / 100 * (100 - discount[j]);
            if(tmp >= user[1])  sum.first++;    else    sum.second += tmp;
        });
        if(answer[0] < sum.first || answer[0] == sum.first && answer[1] < sum.second){  answer[0] = sum.first;  answer[1] = sum.second; }       
    }
    return {{ answer[0], answer[1] }};
}