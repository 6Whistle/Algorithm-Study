#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    stringstream ss;
    int num, min, max;
    ss.str(s);  ss >> num;
    min = num;  max = num;
    while(ss >> num){
        if(min > num)   min = num;
        if(max < num)   max = num;
    }
    
    return to_string(min) + " " + to_string(max);
}