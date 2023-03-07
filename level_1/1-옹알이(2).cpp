#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> word({string("aya"), string("ye"), string("woo"), string("ma"), string(" ")});
    for_each(babbling.begin(), babbling.end(), [&](string bab){

        int i = 0, before = 5;
        while(i < bab.size()){
            bool state = true;
            for(int j = 0; j < 4; j++){
                if(bab.substr(i, word[j].size()).compare(word[j]) == 0){
                    if(before == j) return;
                    i += word[j].size();
                    before = j;
                    state = false;
                    break;
                }
            }
            if(state)  return;
        }
        answer++;
    });
    return answer;
}