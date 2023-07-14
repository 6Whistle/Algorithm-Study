#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> a, b;
    for_each(topping.begin(), topping.end(), [&](int i){    a[i]++;    });
    for(int i = 0; i < topping.size() && a.size() >= b.size(); i++){
        auto iter = a.find(topping[i]);
        if(iter->second-- == 1)   a.erase(iter);
        b[topping[i]]++;
        answer += a.size() == b.size();
    }
    return answer;
}