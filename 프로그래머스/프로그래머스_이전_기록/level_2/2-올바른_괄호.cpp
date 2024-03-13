#include <string>

using namespace std;

bool solution(string s){
    int l = 0;
    for(auto i : s){
        if(i == '(')    l++;
        else if(i == ')'){
            if(l == 0)  return false;
            l--;
        }
    }
    return l == 0;
}