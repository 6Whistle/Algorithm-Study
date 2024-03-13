#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    for_each(s.begin(), s.end(), [&](char c){
        if(tolower(c) == 'p')   p++;
        else if(tolower(c) == 'y')  y++; });
    return p == y;
}