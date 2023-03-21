#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int find_same(vector<vector<int>> &picture, queue<pair<int, int>> &q, int m, int n){
    vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0, same = picture[q.front().first][q.front().second];
    picture[q.front().first][q.front().second] = 0;
    while(!q.empty()){
        for(pair<int, int> arr : direction){
            int x = min(max(q.front().first + arr.first, 0), m - 1);
            int y = min(max(q.front().second + arr.second, 0), n - 1);
            if(picture[x][y] == same){  picture[x][y] = 0;  q.push({x, y});}
        }
        count++;    q.pop();
    }
    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int area_count = 0;
    int max_size = 0;
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!picture[i][j]) continue;
            q.push({i, j});     area_count++;
            max_size = max(max_size, find_same(picture, q, m, n));
        }
    }

    return {area_count, max_size};
}