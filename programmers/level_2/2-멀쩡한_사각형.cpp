#include <algorithm>

using namespace std;

int gcd(int w, int h){
    if(w < h)   swap(w, h);
    for(;h != 0; w %= h, swap(w, h));
    return w;
}

long long solution(int w,int h) {
    long long answer = (long long)w * h - (w + h) + gcd(w, h);
    return answer;
}