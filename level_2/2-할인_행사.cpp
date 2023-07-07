#include <string>
#include <vector>
#include <map>

using namespace std;

bool check(map<string, int> &dic){
    for(auto i = dic.begin(); i != dic.end(); i++)  if(i->second > 0)   return false;
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int i = 0, cnt = 0;
    map<string, int> dic;
    map<string, int>::iterator iter;
    for(; i < want.size(); i++)    dic[want[i]] = number[i];
    for(i = 0; i < 10; i++)     if((iter = dic.find(discount[i])) != dic.end())     iter->second--;
    for(i = 0, cnt = check(dic); i < discount.size(); i++, cnt += check(dic)){
        if((iter = dic.find(discount[i])) != dic.end())         iter->second++;
        if(i + 10 < discount.size() && (iter = dic.find(discount[i + 10])) != dic.end())  iter->second--;
    }
    return cnt;
}