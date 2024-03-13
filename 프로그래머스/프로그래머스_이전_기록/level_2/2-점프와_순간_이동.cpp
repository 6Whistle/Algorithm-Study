using namespace std;

int solution(int n)
{
    int ans = 0;
    for(;n > 1; n = n >> 1) ans += n & 1;
    return ans + 1;
}