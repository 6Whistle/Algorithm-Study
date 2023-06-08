#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


long long solution(string expression) {
    long long answer = 0;
    map<int, long long> nums;
    vector<char> opers;
    for(int i = 0, j; i < expression.size(); i = j + 1){
        for(j = i; isdigit(expression[j]) && j < expression.size(); j++);
        nums.insert({opers.size(), stoi(expression.substr(i, j - i))});
        if(j != expression.size())  opers.push_back(expression[j]);
    }

    vector<short> prio({1, 2, 3});
    do{
        map<int, long long> nums_tmp = nums;
        vector<char> opers_tmp = opers;
        auto cmp = [&prio, &opers_tmp](int &a, int &b){ 
            int oper_a = opers_tmp[a] - '*', oper_b = opers_tmp[b] - '*';
            if(oper_a == 3) oper_a--;           if(oper_b == 3) oper_b--;
            return oper_a == oper_b ? a > b : prio[oper_a] > prio[oper_b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> order(cmp);
        for(int i = 0; i < opers.size(); i++)   order.push(i);
        for(; !order.empty(); order.pop()){
            map<int, long long>::iterator a, b;
            for(auto i = nums_tmp.begin(); i != nums_tmp.end(); i++){
                if(i->first <= order.top()) a = i;
                if(i->first <= order.top() + 1) b = i;
                else    break;
            }
            auto op = opers_tmp[order.top()];
            a->second = op == '*' ? a->second * b->second : op == '+' ? a->second + b->second : a->second - b->second;
            nums_tmp.erase(b);
        }
        answer = max(answer, abs(nums_tmp.begin()->second));
    } while(next_permutation(prio.begin(), prio.end()));
    return answer;
}