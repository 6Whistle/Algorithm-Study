#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), [](int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return stoi(sa + sb) > stoi(sb + sa);
     });
    for_each(numbers.begin(), numbers.end(), [&](int i){ answer += to_string(i); });
    if(numbers[0] == 0) answer = "0";
    return answer;
}