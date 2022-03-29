package Kattis;

import java.io.*;
import java.util.Scanner;

class Autori {
    private static String sol(String query) {
        String ans = "";
        for (int i = 0; i < query.length(); i++) {
            if (i == 0)
                ans += query.charAt(i);
            else if (query.charAt(i-1) == '-') {
                ans += query.charAt(i);
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        String query;
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        query = sc.nextLine();
        String ans = sol(query);
        System.out.println(ans);
    }
}