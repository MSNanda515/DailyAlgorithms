package BasicProg;
import java.util.Scanner;
public class Amstrong {
    public static void main(String[] args) {
        int a;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        int a1 = a, sumCubes = 0;
        while (a1 > 0){
            int rem = a1 % 10;
            sumCubes = (int)Math.pow(rem, 3) + sumCubes;
            a1 /= 10;
        }
        if(sumCubes == a) {
            System.out.println("Amstrong No");
        }
        else
            System.out.println("Not an Amstrong No");
        sc.close();
    }        
}
