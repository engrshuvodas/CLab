//1.1.9. Java program to sort a list of names in ascending order.

package q67112;
import java.util.*;
import java.io.*;
import java.lang.*;

class SortNames {
public static void main(String args[]) {
Scanner scanner = new Scanner(System.in);
int n = Integer.parseInt(scanner.nextLine());
String[] names = new String[n];
for (int i = 0; i < n; i++) {
names[i] = scanner.nextLine();
}
Arrays.sort(names);
for (int i = 0; i < n; i++) {
System.out.print(names[i]);
if (i != n - 1) {
System.out.print(" ");
}
}
scanner.close();
}
}
