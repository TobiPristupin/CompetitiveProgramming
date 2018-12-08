import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.function.Consumer;

public class Shiritori {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.nextLine());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLine();
        }

        Set<String> set = new HashSet<>();
        set.add(arr[0]);
        int wrongMove = -1;
        for (int i = 1; i < arr.length; i++) {

            if (set.contains(arr[i])){
                wrongMove = i;
                break;
            }
            set.add(arr[i]);

            if (!arr[i-1].substring(arr[i-1].length() - 1).equals(arr[i].substring(0, 1))){
                wrongMove = i;
                break;
            }
        }

        if (wrongMove == -1){
            System.out.println("Fair Game");
        } else {
            String out = wrongMove % 2 == 1 ? "Player 2 lost" : "Player 1 lost";
            System.out.println(out);
        }
    }
}
