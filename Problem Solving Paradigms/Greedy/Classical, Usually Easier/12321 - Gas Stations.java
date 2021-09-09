import java.util.*;

public class Main {
    static class Pair {
        int a;
        int b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int l, g;
        while (true) {
            l = input.nextInt();
            g = input.nextInt();
            if (l == 0 && g == 0) {
                break;
            }
            List<Pair> v = new ArrayList<>();
            for (int i = 0; i < g; i++) {
                int x, r, s, e;
                x = input.nextInt();
                r = input.nextInt();
                s = Math.max(x - r, 0);
                e = Math.min(x + r, l);
                v.add(new Pair(s, e));
            }
            v.sort((o1, o2) -> {
                if (o1.a == o2.a) {
                    return o2.b - o1.b;
                }
                return o1.a - o2.a;
            });
            int cnt = 1, max = 0, p = 0;
            boolean ok = true;
            while (p < v.size()) {
                if (v.get(p).a > max) {
                    ok = false;
                    break;
                }
                int bcur = v.get(p).b;
                while (p < v.size() - 1) {
                    if (bcur < v.get(p + 1).b) {
                        break;
                    }
                    p++;
                }
                if (p < v.size() - 1) {
                    if (v.get(p + 1).a > max) {
                        cnt++;
                        max = Math.max(max, bcur);
                    }
                } else {
                    max = Math.max(max, bcur);
                }
                p++;
            }
            if (max < l) ok = false;
            if (ok) {
                System.out.println(g - cnt);
            } else {
                System.out.println(-1);
            }
        }
    }
}
