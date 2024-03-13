#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//LRU Algorithm(Hit : 1, Miss : 5)
int solution(int cacheSize, vector<string> cities) {
    int size = 0, answer = 0;
    vector<string> cache;
    
    for_each(cities.begin(), cities.end(), [&](string city){
        for(int i = 0; i < city.size(); i++)    city[i] = tolower(city[i]);
        vector<string>::iterator iter = find(cache.begin(), cache.end(), city);
        if(iter != cache.end()){    answer++;   size--; cache.erase(iter);  }
        else    answer += 5;
        cache.push_back(city);  size++;
        if(cacheSize == size){  cache.erase(cache.begin());  size--; }
    });

    return answer;
}