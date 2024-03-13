#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> dic;
    for(int i = 0, sum = 0; i < elements.size(); dic.insert(sum), i++, sum = 0)
        for(int j = i; j < i + elements.size(); dic.insert(sum += elements[j % elements.size()]), j++);
    return dic.size();
}