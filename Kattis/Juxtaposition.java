package Kattis;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Juxtaposition {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new InputStreamReader(System.in));

        int a, b, c;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        System.out.println(a * b * c);
    }
}
