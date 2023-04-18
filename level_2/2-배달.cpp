#include <limits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//Solution using Dijkstra algorithm
int solution(int N, vector<vector<int>> road, int K) {
    const long INF = numeric_limits<int>::max();

    //Generate Graph
    vector<vector<int>> table(N, vector<int>(N, INF));
    for(int i = 0; i < N; i++)  table[i][i] = 0;
    for_each(road.begin(), road.end(), [&](vector<int> line){
        if(table[line[0] - 1][line[1] - 1] > line[2]){
            table[line[0] - 1][line[1] - 1] = line[2];
            table[line[1] - 1][line[0] - 1] = line[2];
        }
    });

    vector<int> dis(N, INF);    dis[0] = 0;
    priority_queue<int> pq;     pq.push(0);
    //Dijkstra
    while(!pq.empty()){
        int i = pq.top();    pq.pop();
        for(int j = 1; j < N; j++){
            if(table[i][j] != INF && dis[j] > dis[i] + table[i][j]){
                dis[j] = dis[i] + table[i][j];
                pq.push(j);
            }
        }
    }

    //Count LE then K
    int answer = 0;
    for(int i = 0; i < N; i++)  if(dis[i] <= K)    answer++;

    return answer;
}