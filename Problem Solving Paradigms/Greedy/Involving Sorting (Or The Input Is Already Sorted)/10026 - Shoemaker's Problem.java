import java.util.*;

public class Main {
    static class Pair {
        int index;
        double ratio;

        Pair(int index, double ratio) {
            this.index = index;
            this.ratio = ratio;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = input.nextInt();
            List<Pair> a = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                double T = input.nextDouble(), S = input.nextDouble();
                a.add(new Pair(i, T / S));
            }
            a.sort((o1, o2) -> {
                if (o1.ratio != o2.ratio) {
                    return Double.compare(o1.ratio, o2.ratio);
                }
                return o1.index - o2.index;
            });
            for (int i = 0; i < n; i++) {
                System.out.print(a.get(i).index);
                if (i < n - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
            if (tc < t) {
                System.out.println();
            }
        }

    }
}