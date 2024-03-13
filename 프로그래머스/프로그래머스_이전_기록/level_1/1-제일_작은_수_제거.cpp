#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int temp = 0;
    for(int i = 1; i < arr.size(); i++) if(arr[temp] > arr[i])  temp = i;
    arr.erase(arr.begin() + temp, arr.begin() + temp + 1);
    if(arr.empty()) arr.push_back(-1);
    return arr;
}