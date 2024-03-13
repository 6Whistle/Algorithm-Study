#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

void DFS(string &str_num, string &numbers, set<int> &dic, vector<bool> &visit, int count, const int &max){
    if(count == max){   dic.insert(stoi(str_num));  return;  }
    for(int i = 0; i < numbers.size(); i++)     if(!visit[i]){
        visit[i] = true;    str_num.push_back(numbers[i]);
        DFS(str_num, numbers, dic, visit, count + 1, max);
        visit[i] = false;   str_num.pop_back();
    }
}

int solution(string numbers) {
    set<int> dic;
    vector<bool> visit(numbers.size(), 0);  string temp;
    for(int i = 1; i <= numbers.size();  i++)    DFS(temp, numbers, dic, visit, 0, i);
    
    set<int>::iterator max_iter = dic.end();
    vector<bool> n_prime(*--max_iter + 1, 0);     n_prime[0] = n_prime[1] = true;
    for(int i = 2; i <= sqrt(n_prime.size() - 1); i++)   for(int j = i << 1; j < n_prime.size(); j += i)  n_prime[j] = true;

    int count = 0;
    for_each(dic.begin(), dic.end(), [&count, &n_prime](int i){ count += !n_prime[i];    });

    return count;
}
