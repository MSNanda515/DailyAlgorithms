package BasicProg;
import java.util.*;
class PrimeNoCheck{
    public static void main(String [] args) {
        int a, c = 0;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        for (int i = 2; i < Math.sqrt(a); i++) {
            if(a % i == 0) {
                System.out.println("Composite");
                c = 1;
                break;
            }
        }
        if ( c == 0) {
            System.out.println("Prime");
        }
        sc.close();
    }
}