#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow, sqrt_total = sqrt(total);
    for(int i = 3; i <= sqrt_total; i++)
        if(!(total % i) && !(yellow % (i - 2)) && (total / i - 2) == (yellow / (i - 2)))     return vector<int>({total / i, i});
    return vector<int>();
}