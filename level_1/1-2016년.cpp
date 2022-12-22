#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int day = 0;
    for(int i = 0; i < a - 1; i++)  day += month[i];
    day += b - 1;
    
    return week[day % 7];
}