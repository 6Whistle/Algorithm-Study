#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++)
        q.push((100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] > 0));
    for(int time = 0; !q.empty(); q.pop()){
        if(time < q.front()){ time = q.front();     answer.push_back(1);    } 
        else    answer.back()++;
    }
    return answer;
}