#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n){
    long long temp = 1;
    for(int i = 2; i <= n; i++)  temp *= i;
    return temp;
}

vector<int> solution(int n, long long k) {
    vector<int> answer, li(n, 0);
    long long n_factorial = factorial(n - 1), cur_point = k - 1;
    generate(li.begin(), li.end(), [n = 1]() mutable {  return  n++;  });

    for(int i = n - 1; i > 0; cur_point %= n_factorial, n_factorial /= i, i--){
        answer.push_back(li[cur_point / n_factorial]);
        li.erase(li.begin() + cur_point / n_factorial);
    }
    answer.push_back(*li.begin());
    return answer;
    
}