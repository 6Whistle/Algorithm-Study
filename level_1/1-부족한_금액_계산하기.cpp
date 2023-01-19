using namespace std;

long long solution(int price, int money, int count)
{
    long long temp = count * (count + 1LL) / 2 * price;
    return  temp > money ? temp - money : 0;
}