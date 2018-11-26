import java.util.*;

class ErdosNumber {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Set<String>> map = new HashMap<>();
        List<String> authors = new ArrayList<>();

        while (scanner.hasNext()){
            String[] line = scanner.nextLine().split(" ");
            authors.add(line[0]);
            if (!map.containsKey(line[0])){
                map.put(line[0], new HashSet<>());
            }
            for (int i = 0; i < line.length; i++){
                if (!map.containsKey(line[i])){
                    map.put(line[i], new HashSet<>());
                }
                map.get(line[0]).add(line[i]);
                map.get(line[i]).add(line[0]);

            }
        }

        Map<String, Integer> distances = bfs(map);
        for (String author : authors){
            System.out.println(author + " " + (distances.containsKey(author) ? distances.get(author) : "no-connection"));
        }
    }

    private static Map<String, Integer> bfs(Map<String, Set<String>> map){
        Queue<String> queue = new LinkedList<>();
        Map<String, Integer> pathLength = new HashMap<>();

        queue.add("PAUL_ERDOS");
        pathLength.put("PAUL_ERDOS", 0);
        while (!queue.isEmpty()){
            String node = queue.poll();

            for (String adjacent : map.get(node)){
                if (!pathLength.containsKey(adjacent)){
                    queue.add(adjacent);
                    pathLength.put(adjacent, pathLength.get(node) + 1);
                }
            }
        }
        return pathLength;
    }
}
