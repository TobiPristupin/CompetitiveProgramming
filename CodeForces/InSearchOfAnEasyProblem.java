import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class InSearchOfAnEasyProblem {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        List<String> arr = Arrays.stream(scanner.nextLine().split(" ")).collect(Collectors.toList());
        if (arr.contains("1")){
            System.out.println("HARD");
        } else {
            System.out.println("EASY");
        }
    }
}
