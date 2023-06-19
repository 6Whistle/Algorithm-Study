#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for_each(numbers.begin(), numbers.end(), [&answer](long long num){
        bitset<16> bs(num);
        int i = 0, j = -1;
        for(long long tmp = num; tmp != 0 && (tmp & 0x1); j = i++, tmp = tmp >> 1);
        bs.flip(i);
        if(j != -1) bs.flip(j);
        answer.push_back(bs.to_ullong());
    });
    return answer;
}