#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max[2] = {0};
    for_each(sizes.begin(), sizes.end(), [&](auto temp){
        if(temp[0] < temp[1])   swap(temp[0], temp[1]);
        for(int i = 0; i < 2; i++)  max[i] = max[i] < temp[i] ? temp[i] : max[i];
    });
    return max[0] * max[1];
}