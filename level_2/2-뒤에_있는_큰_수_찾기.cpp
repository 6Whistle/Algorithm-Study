#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1), st;
    for(int i = 0; i < numbers.size(); st.push_back(i++))   for(;!st.empty() && numbers[st.back()] < numbers[i]; answer[st.back()] = numbers[i], st.pop_back());
    return answer;
}