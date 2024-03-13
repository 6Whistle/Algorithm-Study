#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curHealth = health;
    for(int i = 0, time = 0; curHealth > 0 && i < attacks.size(); time = attacks[i++][0]){
        int tmp = attacks[i][0] - time - 1;
        curHealth += tmp * bandage[1] + tmp / bandage[0] * bandage[2];
        curHealth = (curHealth > health ? health : curHealth) - attacks[i][1];
    }
    return curHealth > 0 ? curHealth : -1;
}