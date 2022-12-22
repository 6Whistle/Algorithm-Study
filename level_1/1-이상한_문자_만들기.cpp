#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    //initialize
    string answer = "";
    int count = 0;

    //Check all string elements
    for(auto i = s.begin(); i < s.end(); i++){
        if(count % 2 == 0 && islower(*i))    //lower case
            answer += (*i - 32);
        else if(count % 2 == 1 && isupper(*i))   //upper case
            answer += (*i + 32);
        else
            answer += *i;   //else

        if(*i == ' ')   //next word
            count = 0;
        else
            count++;
    }
    
    return answer;
}