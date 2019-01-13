import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class LuckyDivision122A {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.valueOf(scanner.nextLine());
        List<Integer> a = new ArrayList<>();
        a.add(4);
        a.add(7);

        List<Integer> luckyNumbers = new ArrayList<>();
        luckyNumbers.addAll(combinations(a, 1));
        luckyNumbers.addAll(combinations(a, 2));
        luckyNumbers.addAll(combinations(a, 3));

        for (Integer lucky : luckyNumbers){
            if (n % lucky == 0){
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }

    private static List<Integer> combinations(List<Integer> arr, int r){
        List<List<Integer>> combinations = new ArrayList<>();
        buildCombinations(arr, r, 0, combinations, null);
        List<Integer> combinationsFlattened = new ArrayList<>();
        for (List<Integer> l: combinations){
            combinationsFlattened.addAll(l);
        }

        return combinationsFlattened;
    }

    private static void buildCombinations(List<Integer> arr, int r, int n, List<List<Integer>> allCombs, List<Integer> currComb){
        if (currComb == null){
            currComb = new ArrayList<>(arr);
        }

        if (n == r - 1){
            allCombs.add(currComb);
            return;
        }

        for (int x : arr){
            List<Integer> mapped = currComb.stream().map(c -> Integer.valueOf(String.valueOf(c) + String.valueOf(x))).collect(Collectors.toList());
            buildCombinations(arr, r, n + 1, allCombs, mapped);
        }
    }


}
