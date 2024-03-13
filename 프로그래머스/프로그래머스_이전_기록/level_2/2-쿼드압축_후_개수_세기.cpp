#include <string>
#include <vector>

using namespace std;

pair<int, int> DFS(vector<vector<int>> &arr, int x, int y, int size){
    if(size == 1)   return {!arr[x][y], arr[x][y]};
    pair<int, int> sum = { 0, 0 };    size = size >> 1;
    for(int i = 0; i < 2; i++)  for(int j = 0; j < 2; j++){
        pair<int, int> temp = DFS(arr, x + i * size, y + j * size, size);
        sum.first += temp.first;    sum.second += temp.second;
    }
    return !sum.first ? make_pair(0, 1) : !sum.second ? make_pair(1, 0) : sum;
}

vector<int> solution(vector<vector<int>> arr) {
    pair<int, int> count = DFS(arr, 0, 0, arr.size());
    return {count.first, count.second};
}