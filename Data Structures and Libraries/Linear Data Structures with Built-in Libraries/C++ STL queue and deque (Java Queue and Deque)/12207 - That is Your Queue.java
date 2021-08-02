import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int p, c, tc = 1;
        while (true) {
            p = input.nextInt();
            c = input.nextInt();
            if (p == 0 && c == 0) {
                break;
            }
            Deque<Integer> q = new LinkedList<>();
            for (int i = 1; i <= p && i <= 1000; i++) {
                q.addLast(i);
            }
            System.out.println("Case " + tc++ + ":");
            while (c > 0) {
                String command = input.next();
                if (command.compareTo("N") == 0) {
                    int front = q.getFirst();
                    System.out.println(front);
                    q.pop();
                    q.addLast(front);
                } else {
                    int x = input.nextInt();
                    q.remove(x);
                    q.addFirst(x);
                }
                c--;
            }
        }
    }
}
