import java.time.LocalDate;
import java.time.Month;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy-M-dd");
        for (int i = 1; i <= t; i++) {
            String s = input.next();
            int days = input.nextInt();
            String[] ymd = s.split("-");
            String y = ymd[0];
            int m = Month.valueOf(ymd[1].toUpperCase()).getValue();
            String d = ymd[2];
            String tmp = y + "-" + m + "-" + d;
            LocalDate date = LocalDate.parse(tmp, format);
            date = date.plusDays(days);
            String month = date.getMonth().toString().toLowerCase();
            month = month.substring(0, 1).toUpperCase() + month.substring(1);
            String ans = date.getYear() + "-" + month + "-";
            if (date.getDayOfMonth() < 10) {
                ans += "0";
            }
            ans += date.getDayOfMonth();
            System.out.println("Case " + i + ": " + ans);
        }
    }
}
