#include <string>
#include <cstdlib>

using namespace std;

int solution(string dartResult) {
    int result[3] = { 0 };
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == '*'){   result[1] *= 2; result[2] *= 2; }
        else if(dartResult[i] == '#')   result[2] *= -1;
        else{
            result[0] = result[1];    result[1] = result[2];
            result[2] = dartResult[i++] - '0';
            if(result[2] == 1 && dartResult[i] == '0')  {   result[2] = 10;   i++; }
            result[2] *= dartResult[i] == 'S' ? 1 : (dartResult[i] == 'D' ? result[2] : result[2] * result[2]); 
        }
    }
    return result[0] + result[1] + result[2];
}