package BasicProg;
import java.util.*;
class Palindrome{
    public static void main(String [] args) {
        int no1, no2;
        Scanner sc = new Scanner(System.in);
        no1 = sc.nextInt();
        int rev = 0, rem;
        no2 = no1;
        while(no2 > 0){
            rem = no2 % 10;
            rev = rev * 10 + rem;
            no2 /= 10;
        }
        if (rev == no1) {
            System.out.println("Palindrome");
        }
        else
            System.out.println("Not a palindrome");
        sc.close();
    }
}