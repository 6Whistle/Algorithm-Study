using namespace std;

int solution(int n, int a, int b)
{
    int i = 0;
    for(a--, b--; a != b; i++, a = a >> 1, b = b >> 1);
    return i;
}