#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check_skill(string &skill, string &skill_tree){
    int before = -1;
    for(auto i : skill_tree){ 
        auto cur = skill.find(i);
        if(cur == string::npos) continue;
        if(cur != before + 1) return false;
        before++;
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for_each(skill_trees.begin(), skill_trees.end(), [&](string s){if(check_skill(skill, s)) answer++; });
    return answer;
}