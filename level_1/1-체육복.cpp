#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> student(n, 1);  //clothe num vector
    for_each(reserve.begin(), reserve.end(), [&](int i){student[i-1]++;});  //reserve add
    for_each(lost.begin(), lost.end(), [&](int i){student[i-1]--;});    //lost sub
    for(int i = 0; i < n; i++){
        if(student[i] == 0 && student[i - 1] != 2){    //lost case
            //check can borrow
            if(student[i + 1] == 2){   //if i+1 has 2 clothe
                student[i + 1]--;
                continue;
            }
			answer--;
        }
    }
    return answer;
}