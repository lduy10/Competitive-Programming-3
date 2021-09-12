import java.util.*;

public class Main {
    static class Quartet {
        int a, b, c, d;

        Quartet(int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int m = input.nextInt();
            List<Quartet> arr = new ArrayList<>();
            while (true) {
                int l = input.nextInt(), r = input.nextInt();
                if (l == 0 && r == 0) break;
                if (l > m || r < 0) continue;
                int a = Math.max(l, 0), b = Math.min(r, m);
                arr.add(new Quartet(a, b, l, r));
            }
            arr.sort((o1, o2) -> {
                if (o1.a != o2.a) {
                    return o1.a - o2.a;
                }
                return o2.b - o1.b;
            });
            int p = 0, d = 0;
            List<Quartet> ans = new ArrayList<>();
            while (p < arr.size()) {
                Quartet cur = arr.get(p);
                if (cur.a > d) {
                    break;
                }
                while (p < arr.size() - 1) {
                    if (arr.get(p + 1).b > cur.b) {
                        break;
                    }
                    p++;
                }
                if (p < arr.size() - 1) {
                    if (arr.get(p + 1).a > d) {
                        ans.add(cur);
                        d = Math.max(d, cur.b);
                    }
                } else {
                    ans.add(cur);
                    d = Math.max(d, cur.b);
                }
                p++;
            }
            if (d < m) {
                System.out.println(0);
            } else {
                System.out.println(ans.size());
                for (Quartet q : ans) {
                    System.out.println(q.c + " " + q.d);
                }
            }
            if (tc < t) {
                System.out.println();
            }
        }
    }
}