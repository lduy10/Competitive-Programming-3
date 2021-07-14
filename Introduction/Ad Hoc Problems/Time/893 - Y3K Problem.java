import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner((System.in));
        while (true) {
            int nd = input.nextInt();
            int day = input.nextInt();
            int month = input.nextInt();
            int year = input.nextInt();
            if (nd == 0 && day == 0 && month == 0 && year == 0) {
                break;
            }
            String dmy = day + " " +  month + " " + year;
            LocalDate localDate = LocalDate.parse(dmy, DateTimeFormatter.ofPattern("d M y"));
            LocalDate date = localDate.plusDays(nd);
            System.out.println(date.getDayOfMonth() + " " + date.getMonthValue() + " " + date.getYear());
        }
    }
}
