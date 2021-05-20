package BasicProg;
import java.util.*;
class FibSeries{
    public static void main(String [] args) {
        int a = 0, b = 1;
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        System.out.print(a + " " + b + " ");
        for (int i = 2; i < n; i++ ){
            System.out.print(a + b + " ");
            int temp = a;
            a = b;
            b = b + temp;
        }
        System.out.println();
        scan.close();

    }
}