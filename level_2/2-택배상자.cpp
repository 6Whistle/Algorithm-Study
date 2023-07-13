#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int i = 0, j = 1;
    vector<bool> check(order.size() + 1, false);
    vector<int> belt;
    for(; i < order.size(); i++)
        if(check[order[i]])  if(belt.back() == order[i])    belt.pop_back();    else    break;
        else {  for(;j != order[i]; check[j] = true, belt.push_back(j++));  j++;    }
    return i;
}