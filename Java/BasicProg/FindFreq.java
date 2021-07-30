package BasicProg;
import java.util.*;

public class FindFreq {
    public static void main(String[] args) {
        Hashtable<Integer, Integer> m1 = new Hashtable<Integer, Integer> ();
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = sc.nextInt();
            if(m1.containsKey(ar[i])){
                // Increase the frequency by 1
                m1.put(ar[i], m1.get(ar[i])+1);                
            }
            else {
                m1.put(ar[i], 1);
            }
        }
        for (Map.Entry<Integer, Integer> e : m1.entrySet()) {
            System.out.println(e.getKey() + " : " + e.getValue());
        }
        System.out.println(m1);
        sc.close();
    }
}
