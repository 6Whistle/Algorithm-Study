#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = citations.size() - 1; i >= 0; i--)
        if(citations[i] > i)    return i;
    return 0;
}