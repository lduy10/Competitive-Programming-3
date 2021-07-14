import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t;
        t = input.nextInt();
        DateTimeFormatter inputFormat = DateTimeFormatter.ofPattern("MMddyyyy");
        DateTimeFormatter newFormat = DateTimeFormatter.ofPattern("MM/dd/yyyy");
        for (int i = 1; i <= t; i++) {
            String mdy = input.next();
            LocalDate localDate = LocalDate.parse(mdy, inputFormat);
            LocalDate newDate = localDate.plusWeeks(40);
            String ans = i + " " + newFormat.format(newDate) + " ";
            if (newDate.getMonthValue() == 1 && newDate.getDayOfMonth() >= 21
                    || newDate.getMonthValue() == 2 && newDate.getDayOfMonth() <= 19) {
                ans += "aquarius";
            } else if (newDate.getMonthValue() == 2
                    || newDate.getMonthValue() == 3 && newDate.getDayOfMonth() <= 20) {
                ans += "pisces";
            } else if (newDate.getMonthValue() == 3
                    || newDate.getMonthValue() == 4 && newDate.getDayOfMonth() <= 20) {
                ans += "aries";
            } else if (newDate.getMonthValue() == 4
                    || newDate.getMonthValue() == 5 && newDate.getDayOfMonth() <= 21) {
                ans += "taurus";
            } else if (newDate.getMonthValue() == 5
                    || newDate.getMonthValue() == 6 && newDate.getDayOfMonth() <= 21) {
                ans += "gemini";
            } else if (newDate.getMonthValue() == 6
                    || newDate.getMonthValue() == 7 && newDate.getDayOfMonth() <= 22) {
                ans += "cancer";
            } else if (newDate.getMonthValue() == 7
                    || newDate.getMonthValue() == 8 && newDate.getDayOfMonth() <= 21) {
                ans += "leo";
            } else if (newDate.getMonthValue() == 8
                    || newDate.getMonthValue() == 9 && newDate.getDayOfMonth() <= 23) {
                ans += "virgo";
            } else if (newDate.getMonthValue() == 9
                    || newDate.getMonthValue() == 10 && newDate.getDayOfMonth() <= 23) {
                ans += "libra";
            } else if (newDate.getMonthValue() == 10
                    || newDate.getMonthValue() == 11 && newDate.getDayOfMonth() <= 22) {
                ans += "scorpio";
            } else if (newDate.getMonthValue() == 11
                    || newDate.getMonthValue() == 12 && newDate.getDayOfMonth() <= 22) {
                ans += "sagittarius";
            } else {
                ans += "capricorn";
            }
            System.out.println(ans);
        }
    }
}
