#include <string>
#include <vector>

using namespace std;

int DFS(int storey, int answer = 0){
    for(int div = storey / 10, left; storey > 0; storey = div, div /= 10)
        if((left = storey % 10) > 5){   answer += 10 - left;    div++;    }
        else if(left == 5)  return min(DFS(div + 1, answer + left), DFS(div, answer + left));
        else    answer += left;
    return answer;
}

int solution(int storey) {      return DFS(storey);     }