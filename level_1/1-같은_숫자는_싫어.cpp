#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for_each(arr.begin(), arr.end(), [&](int a){    if(answer.empty() || answer.back() != a)    answer.push_back(a);    });
    return answer;
}