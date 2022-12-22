#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    for(auto i = s.begin(); i < s.end(); i++)
        if((*i) < '0' || (*i) > '9')   return false;
    return (s.length() == 4) || (s.length() == 6);
}