package BasicProg;
import java.util.*;
class Factorial{
    private static long factorial(int no){
        if(no == 1) {
            return 1;
        }
        return no * factorial(no - 1);
    }
    public static void main(String [] args) {
        int no;
        long fact;
        Scanner sc = new Scanner(System.in);
        no = sc.nextInt();
        fact = factorial(no);
        System.out.println("The factorial of " + no + " is " + fact);
    }
}