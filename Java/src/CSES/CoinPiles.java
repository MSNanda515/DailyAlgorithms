package CSES;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CoinPiles {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        long a, b;
        for (int i = 0; i < n; i++) {
            String temp[] = br.readLine().split(" ");
            a = Long.parseLong(temp[0]);
            b = Long.parseLong(temp[1]);
            deterCoinPile(writer, a, b);
        }
        writer.flush();
    }

    private static void deterCoinPile(PrintWriter writer, long a, long b) {
        if (a == b) {
            if (a % 3 == 0)
                writer.println("YES");
            else
                writer.println("NO");
            return;
        }
        if (a < b) {
            long temp = a;
            a = b;
            b = temp;
        }
        if (a == 2 * b) {
            writer.println("YES");
            return;
        }
        long n = a - b;
        if (n > b || (b - n) % 3 != 0) {
            writer.println("NO");
            return;
        }
        else
            writer.println("YES");
    }
}