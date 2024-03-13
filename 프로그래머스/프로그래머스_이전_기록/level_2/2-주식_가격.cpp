#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<vector<int>::iterator> st;
    for(auto i = prices.begin(); i < prices.end(); i++){
        while(!st.empty() && *(st.top()) > *i){
            answer[st.top() - prices.begin()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
            answer[st.top() - prices.begin()] = (prices.end() - 1) - st.top();
            st.pop();
        }
    return answer;
}