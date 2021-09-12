import java.util.*;

public class Main {
    static class Coordinate {
        double ss;
        double se;

        Coordinate(double ss, double se) {
            this.ss = ss;
            this.se = se;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int tc = 1;
        while (true) {
            int n = input.nextInt(), d = input.nextInt();
            if (n == 0 && d == 0) break;
            List<Coordinate> a = new ArrayList<>();
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                double x = input.nextDouble(), y = input.nextDouble();
                if (y > d) ok = false;
                double dist = Math.sqrt(d * d - y * y);
                a.add(new Coordinate(x - dist, x + dist));
            }
            System.out.print("Case " + tc++ + ": ");
            if (!ok) {
                System.out.println(-1);
                continue;
            }
            a.sort((o1, o2) -> (o1.se == o2.se) ?
                    Double.compare(o1.ss, o2.ss)
                    : Double.compare(o1.se, o2.se));
            int ans = 0, p = 0;
            while (p < n) {
                int i;
                for (i = p; i < n; i++) {
                    if (a.get(i).ss > a.get(p).se) {
                        break;
                    }
                }
                p = i;
                ans++;
            }
            System.out.println(ans);
        }
    }
}