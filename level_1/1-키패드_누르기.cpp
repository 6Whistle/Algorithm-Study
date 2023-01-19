#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left(3, 0), right(3, 2), cur(0, 0);
    int lmove, rmove;
    for_each(numbers.begin(), numbers.end(), [&](int temp){
        cur.first = temp == 0 ? 3 : (temp - 1) / 3;
        cur.second = temp == 0 ? 1 : (temp - 1) % 3;
        lmove = abs(cur.first - left.first) + abs(cur.second - left.second);
        rmove = abs(cur.first - right.first) + abs(cur.second - right.second);
        if(cur.second == 0 || (cur.second == 1 && (lmove < rmove || (lmove == rmove && hand.compare("left") == 0)))){
            left.first = cur.first; 
            left.second = cur.second;   
            answer += 'L';   
        }
        else{
            right.first = cur.first;
            right.second = cur.second;  
            answer += 'R';  
        }   
    });

    return answer;
}