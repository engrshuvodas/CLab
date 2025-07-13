//1.1.7. Prime Numbers List

package q37389;
import java.util.Scanner;

public class PrimeNumbersList {
public static boolean isPrime(int n) {
if (n <= 1) return false;
for (int i = 2; i <= Math.sqrt(n); i++) {
if (n % i == 0)
return false;
}
return true;
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
int limit = scanner.nextInt();
boolean found = false;
for (int i = 2; i <= limit; i++) {
if (isPrime(i)) {
System.out.print(i + " ");
found = true;
}
}
if (!found) {
System.out.println("No prime numbers found");
}
scanner.close();
}
}
