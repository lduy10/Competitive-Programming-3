import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n =  input.nextInt();
            String field = input.next();
            int idx = 0, ans = 0;
            while (idx < n) {
                while (idx < n) {
                    if (field.charAt(idx) != '#') break;
                    idx++;
                }
                if (idx == n) continue;
                for (int i = 0; i < 3; i++) {
                    idx++;
                }
                ans++;
            }
            System.out.println("Case " + tc + ": " + ans);
        }
    }
}
