#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > p_A;
    priority_queue<int> p_B;
    for(int i = 0; i < A.size(); i++){  p_A.push(A[i]); p_B.push(B[i]);  }
    while(!p_A.empty()){    answer += p_A.top() * p_B.top(); p_A.pop(); p_B.pop();  }
    return answer;
}