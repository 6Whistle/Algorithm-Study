#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0, temp;
    bool state;
    for(int i = 0; i < nums.size(); i++)
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] == nums[j])  continue;
            for(int k = j + 1; k < nums.size(); k++){
                if(nums[i] == nums[k] || nums[j] == nums[k])    continue;
                temp = nums[i] + nums[j] + nums[k];
                state = true;
                for(int l = 2; l * l <= temp; l++)
                    if(temp % l == 0){
                        state = false;
                        break;
                    }
                if(state)   answer++;
            }
        }
    
    return answer;
}