#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void insert(set<int> &s, vector<int> &q, int i){    if((s.insert(i)).second)    q.push_back(i);    };

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> tree(n + 1, vector<int>());
    for_each(wires.begin(), wires.end(), [&](vector<int> &temp){    tree[temp[0]].push_back(temp[1]);    tree[temp[1]].push_back(temp[0]);  });
    for_each(wires.begin(), wires.end(), [&](vector<int> &except){
        set<int> s;
        vector<int> q;
        insert(s, q, wires[except[0] == wires[0][0] && except[1] == wires[0][1]][0]);
        while(!q.empty()){
            int i = q.back();    q.pop_back();
            for_each(tree[i].begin(), tree[i].end(), [&](int j){    if(min(i, j) != except[0] || max(i, j) != except[1])    insert(s, q, j);    });
        }
        answer = min(answer, abs(n - (int)(s.size() << 1)));
    });

    return answer;
}