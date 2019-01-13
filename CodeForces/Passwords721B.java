import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Passwords721B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] nk = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::valueOf).toArray();
        int n = nk[0];
        int k = nk[1];
        String[] passwords = new String[n];
        for (int i = 0; i < n; i++) {
            passwords[i] = scanner.nextLine();
        }
        String correctPassword = scanner.nextLine();

        Arrays.sort(passwords, Comparator.comparingInt(String::length));

        int bestTime = 0;
        int c = 0;
        for (String pass : passwords){
            if (pass.length() < correctPassword.length()){
                c += 1;
                bestTime += 1;
            } else {
                bestTime += 1;
                break;
            }

            if (c == k){
                c = 0;
                bestTime += 5;
            }
        }

        c = 0;
        int worstTime = 0;
        for (String pass : passwords){
            if (c == k && pass.length() <= correctPassword.length()){
                c = 0;
                worstTime += 5;
            }

            if (pass.length() <= correctPassword.length()) {
                c += 1;
                worstTime += 1;
            } else {
                break;
            }
        }



        System.out.println(bestTime + " " + worstTime);
    }
}
