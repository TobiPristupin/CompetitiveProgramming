import java.util.Arrays;
import java.util.Scanner;

public class Tenkindsofpeople {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] rc = scanner.nextLine().split(" ");
        int r = Integer.valueOf(rc[0]);
        int c = Integer.valueOf(rc[1]);
        int[][] map = new int[r][c];
        for (int i = 0; i < r; i++) {
            map[i] = Arrays.stream(scanner.nextLine().split("")).mapToInt(Integer::parseInt).toArray();
        }

        int[][] groups = copy2d(map);
        buildGroups(groups);

        int n = Integer.valueOf(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            int[] cords = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            if (groups[cords[0] - 1][cords[1] - 1] == groups[cords[2] - 1][cords[3] - 1]){
                System.out.println(map[cords[0] - 1][cords[1] - 1] == 1 ? "decimal" : "binary");
            } else {
                System.out.println("neither");
            }
        }
    }

    private static void buildGroups(int[][] map){
        int id = 2;
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (map[i][j] == 0 || map[i][j] == 1){
                    int type = map[i][j];
                    floodfill(i, j, id, type, map);
                    id++;
                }
            }
        }
    }

    private static void floodfill(int r, int c, int id, int type, int[][] map){
        if (map[r][c] != type){
            return;
        }

        map[r][c] = id;

        int[][] neighbors = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
        for (int[] n : neighbors){
            if (inBounds(map, n[0], n[1])){
                floodfill(n[0], n[1], id, type, map);
            }
        }

    }

    private static boolean inBounds(int[][] arr, int r, int c){
        return r >= 0 && r < arr.length && c >= 0 && c < arr[0].length;
    }

    private static int[][] copy2d(int[][] source){
        int[][] dest = new int[source.length][source[0].length];
        for (int i = 0; i < source.length; i++) {
            dest[i] = Arrays.copyOf(source[i], source[i].length);
        }

        return dest;
    }
}
