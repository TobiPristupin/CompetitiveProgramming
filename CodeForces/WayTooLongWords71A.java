import java.util.Scanner;

public class WayTooLongWords71A {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String word = scanner.nextLine();
            if (word.length() > 10){
                System.out.println(word.substring(0, 1) + (word.length() - 2) + word.substring(word.length() - 1));
            } else {
                System.out.println(word);
            }
        }

    }
}
