import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ArbitrageFloydWarshall {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String input = scanner.nextLine();
        while (!input.equals("0")){
            if (hasArbitrage()){
                System.out.println("Arbitrage");
            } else {
                System.out.println("Ok");
            }
            input = scanner.nextLine();
        }
    }

    private static Double[][] buildAdjacencyMatrix(){
        String[] currencies = scanner.nextLine().split(" ");
        Map<String, Integer> currenciesIndex = new HashMap<>();
        for (int i = 0; i < currencies.length; i++){
            currenciesIndex.put(currencies[i], i);
        }

        Double[][] matrix = new Double[currencies.length][currencies.length];
        for (int r = 0; r < currencies.length; r++){
            for (int c = 0; c < currencies.length; c++){
                if (r == c){
                    matrix[r][c] = 0.0;
                    continue;
                }
                matrix[r][c] = Double.POSITIVE_INFINITY;
            }
        }

        int conversions = Integer.valueOf(scanner.nextLine());
        for (int i = 0; i < conversions; i++){
            String[] in = scanner.nextLine().split(" ");
            double numerator = Double.valueOf(in[2].split(":")[1]);
            double denominator = Double.valueOf(in[2].split(":")[0]);
            Double weight = - Math.log(numerator / denominator);
            matrix[currenciesIndex.get(in[0])][currenciesIndex.get(in[1])] = weight;
        }

        return matrix;
    }

    private static boolean hasArbitrage() {
        Double[][] matrix = buildAdjacencyMatrix();
        for (int k = 0; k < matrix.length; k++){
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        System.out.println(Arrays.deepToString(matrix));

        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][i] < 0){
                return true;
            }
        }
        return false;
    }
}
