import java.util.*;

public class Main {
    static class Pair {
        double a;
        double b;

        Pair(double a, double b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            double n = input.nextDouble(),
                    l = input.nextDouble(),
                    w = input.nextDouble();
            ArrayList<Pair> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                double p = input.nextDouble(),
                        r = input.nextDouble();
                if (r > w / 2) {
                    double d = Math.sqrt(Math.pow(r, 2) - Math.pow((w / 2), 2));
                    double a = Math.max(p - d, 0), b = Math.min(p + d, l);
                    arr.add(new Pair(a, b));
                }
            }
            arr.sort(new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    if (o1.a != o2.a) {
                        if (o1.a < o2.a) {
                            return -1;
                        } else {
                            return 1;
                        }
                    }
                    if (o1.b > o2.b) {
                        return -1;
                    } else if (o1.b < o2.b) {
                        return 1;
                    }
                    return 0;
                }
            });
            int ans = 1, p = 0;
            double max =  0;
            boolean ok = true;
            while (p < arr.size()) {
                if (arr.get(p).a > max) {
                    ok = false;
                    break;
                }
                double curb = arr.get(p).b;
                while (p < arr.size() - 1) {
                    if (curb < arr.get(p + 1).b) break;
                    p++;
                }
                if (p < arr.size() - 1) {
                    if (arr.get(p + 1).a > max) {
                        ans++;
                        max = Math.max(curb, max);
                    }
                } else {
                    max = Math.max(curb, max);
                }
                p++;
            }
            if (max < l) {
                ok = false;
            }
            if (ok) {
                System.out.println(ans);
            } else {
                System.out.println(-1);
            }
        }
    }
}
