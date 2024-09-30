import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int min = 1, max = 100000, avg = (min + max) / 2;
        for(;min != avg;){
            if(check_level(avg, diffs, times, limit))   max = avg;
            else min = avg;
            avg = (min + max) / 2;
        }
        return check_level(min, diffs, times, limit) ? min : max;
    }
    
    private boolean check_level(int level, int[] diffs, int[] times, long limit){
        long curTime = 0, totalTime = 0;
        for(int i = 0; i < diffs.length && totalTime <= limit; i++){
            curTime = times[i] + (level < diffs[i] ? (times[i-1] + times[i]) * (diffs[i] - level) : 0L);
            totalTime += curTime;
        }
        return totalTime <= limit;
    }
}