import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String s = scan.next();
        String array[] = {"", "", "2", "3", "322", "5", "53", "7", "7222", "7332"};
        String ans = "";
        for (int i = 0; i < n; ++i) {
            ans += array[s.charAt(i) - '0'];
        }
        char [] a = ans.toCharArray();
        Arrays.sort(a);
        ans = "";
        for (int i = a.length - 1; i >= 0; --i) {
            ans += a[i];
        }
        System.out.println(ans);
    }
}