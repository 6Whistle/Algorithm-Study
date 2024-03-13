#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    //while all charactor
    for(auto i : s){
        if(isupper(i)){    //upper case
            if(i + n > 'Z')    //out of range case
                answer += (i + n - 26);
            else
                answer += (i + n);
        }
        else if(islower(i)){   //lower case
            if(i + n > 'z')    //out of range
                answer += (i + n - 26);
            else
                answer += (i + n);
        }
        else
            answer += i;
    }
        
    return answer;
}