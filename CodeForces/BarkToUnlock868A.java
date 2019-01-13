import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BarkToUnlock868A {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String password = scanner.nextLine();
        int n = Integer.valueOf(scanner.nextLine());
        List<String> words = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            words.add(scanner.nextLine());
        }

        boolean hasFirst = false;
        boolean hasSecond = false;
        for(String word : words){
            if (word.substring(1).equals(password.substring(0, 1))){
                hasFirst = true;
            }

            if (word.substring(0, 1).equals(password.substring(1))){
                hasSecond = true;
            }

            if (hasFirst && hasSecond || word.equals(password)){
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }
}
