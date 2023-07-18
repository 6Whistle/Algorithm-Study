#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_gcd(int a, int b){     for(; a; a %= b)     if(a < b)       swap(a, b);        return b;   }
bool check_div(int a, vector<int> &arr){    for(int i = 0; i < arr.size(); i++)     if(!(arr[i] % a))   return false;    return true;   }

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcd[2] = { arrayA[0], arrayB[0] }, answer = 0;
    vector<int> gcd_common[2];
    for_each(arrayA.begin() + 1, arrayA.end(), [&](int i){   gcd[0] = find_gcd(gcd[0], i);   });
    for_each(arrayB.begin() + 1, arrayB.end(), [&](int i){   gcd[1] = find_gcd(gcd[1], i);   });
    for(int i = gcd[0]; i > 0; i--)    if(!(gcd[0] % i) && check_div(i, arrayB)){   answer = i;     break;  }
    for(int i = gcd[1]; i > 0; i--)    if(!(gcd[1] % i) && check_div(i, arrayA)){   answer = max(answer, i);     break;  }
    
    return answer;
}