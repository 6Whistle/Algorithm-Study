#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return num & 1 ? string("Odd") : string("Even");
}