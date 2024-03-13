#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long avg = 0, sum1 = 0, sum2 = 0, tmp;
    for(int i = 0; i < queue1.size(); i++){ sum1 += queue1[i];   sum2 += queue2[i]; }
    if((avg = sum1 + sum2) & 1)     return -1;      else    avg = avg >> 1;
    for(int i = 0, j; i < queue2.size(); queue1.push_back(queue2[i]), sum1 += queue2[i++]){
        for(tmp = 0, j = 0; j < queue1.size() && sum1 - tmp > avg; tmp += queue1[j++]);
        if(sum1 - tmp == avg)  return i + j;
    }
    return -1;
}