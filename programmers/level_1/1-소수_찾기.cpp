#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> pri;
    for(int i = 2; i <= n; i++){
        bool state = true;
        if(pri.empty()){    pri.push_back(i);   continue;   }
        for(auto j = pri.begin(); (*j) * (*j) <= i; j++){
            if(i % *j == 0){
                state = false;
                break;
            }
        }
        if(state)   pri.push_back(i);
    }
    return pri.size();
}