#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> v = {1, 1};
    for(int i = 1; i < n; i++)  v.push_back((v[i] + v[i - 1]) % 1234567);
    return v.back();
}