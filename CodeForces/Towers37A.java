import java.util.*;
import java.util.stream.Collectors;

public class Towers37A {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.nextLine());
        int[] towers = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::valueOf).toArray();
        Map<Integer, Integer> seen = new HashMap<>();
        int largest = 0;
        for (Integer tower : towers){
            if (seen.containsKey(tower)){
                int size = seen.get(tower) + 1;
                seen.put(tower, size);
                largest = Math.max(size, largest);
            } else {
                seen.put(tower, 1);
                largest = Math.max(1, largest);
            }
        }

        System.out.println(largest + " " + seen.size());
    }
}
