#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(vector<string>& data, string arr){
    int a, b, dis;
    for(string s : data){
        dis = s[4] - '0' + 1;
        if((a = arr.find(s[0])) > arr.size() || (b = arr.find(s[2])) > arr.size())    continue;
        if(s[3] == '=' && abs(a - b) == dis)     continue;
        else if(s[3] == '<' && abs(a - b) < dis)   continue;
        else if(s[3] == '>' && abs(a - b) > dis)    continue;
        return false;
    }
    return true;
}

void DFS(vector<string> &data, string &people, string &arr, int &count){
    if(people.empty()){     count++;    return;     }
    for(int i = 0; i < people.size(); i++){
        string temp_people = people, temp_arr = arr;
        temp_arr += people[i];
        if(Check(data, temp_arr)){  temp_people.erase(temp_people.begin() + i);   DFS(data, temp_people, temp_arr, count);    }
    }
    return;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string people{"ACFJMNRT"}, arr("");
    // 순열의 조합을 이용한 풀이(성능 lower)
    // do{  answer += Check(data, people);  }while(next_permutation(people.begin(), people.end()));
    
    //DFS를 이용한 풀이
    DFS(data, people, arr, answer);
    return answer;
}

