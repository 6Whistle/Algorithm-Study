#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check_prime(long long num){
    for(long i = 2; i <= sqrt(num); i++) if(!(num % i))  return false;
    return num != 1;
}

int solution(int n, int k) {
    int answer = 0, start = 0, end = 0;
    string num;
    do{ num.push_back(n % k + '0');   n /= k;    } while (n > 0);
    reverse(num.begin(), num.end());
    while(start < num.size()){
        if(num[start] == '0'){    start++;    continue;   }
        for(end = start + 1; end <= num.size() && num[end] != '0'; end++);
        answer += check_prime(stoll(num.substr(start, end - start)));
        start = end;
    }
    return answer;
}