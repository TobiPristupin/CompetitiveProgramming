import java.util.*;

public class WeightOfWords {

    private static List<String> alphabet = new ArrayList<>(Arrays.asList("abcdefghijklmnopqrstuvwxyz".split("")));

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ");
        int l = Integer.valueOf(line[0]);
        int w = Integer.valueOf(line[1]);

        if (w / (double) l > 26 || w < l){
            System.out.println("impossible");
            return;
        }

        String s = "";
        for (int i = 0; i < l; i++) {
            s += "a";
        }
        int sum = l;

        while (sum < w){
            for (int i = 0; i < l; i++) {
                if (!s.substring(i, i + 1).equals("z")){
                    int prevWeight = alphabet.indexOf(s.substring(i, i + 1));
                    int newWeight = Math.min(prevWeight + w - sum , 25);
                    sum += newWeight - prevWeight;
                    s = s.substring(0, i) + alphabet.get(newWeight) + s.substring(i + 1);
                    break;
                }
            }
        }

        System.out.println(s);
    }
}
