import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        Map<String, Integer> count = new HashMap<>();
        Map<String, Map<String, Integer>> map = new HashMap<>();
        for(String friend : friends)    map.put(friend, new HashMap<>());

        for(String gift : gifts){
            String[] split = gift.split(" ");
            map.get(split[0]).put(split[1], map.get(split[0]).getOrDefault(split[1], 0) + 1);
            count.put(split[0], count.getOrDefault(split[0], 0) + 1);
            count.put(split[1], count.getOrDefault(split[1], 0) - 1);
        }

        return (int)Arrays.asList(friends).stream()
        .mapToLong(me -> Arrays.asList(friends).stream()
            .filter(friend -> 
                map.get(me).getOrDefault(friend, 0) > map.get(friend).getOrDefault(me, 0)
                ? true
                : map.get(me).getOrDefault(friend, 0) == map.get(friend).getOrDefault(me, 0) && count.getOrDefault(me, 0) > count.getOrDefault(friend, 0)
                ? true : false
            ).count()
        ).max().getAsLong();
    }
}