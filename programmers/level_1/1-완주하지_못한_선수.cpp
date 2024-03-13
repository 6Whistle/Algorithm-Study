#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//Hash Solution
// string solution(vector<string> participant, vector<string> completion) {
//     unordered_multiset<string> s(participant.begin(), participant.end());
//     for_each(completion.begin(), completion.end(), [&](string com){ s.erase(s.find(com));   });
//     return *(s.begin());
// }

//XOR Solution
string solution(vector<string> participant, vector<string> completion){
    char s[21] = { 0 };
    for_each(participant.begin(), participant.end(), [&](string p){ for(int i = 0; i < p.size(); i++)   s[i] ^= p[i];   });
    for_each(completion.begin(), completion.end(), [&](string c){ for(int i = 0; i < c.size(); i++)   s[i] ^= c[i];   });
    return string(s);
}