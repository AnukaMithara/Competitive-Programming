import java.util.*;

class Main {
  public static void main(String[] args) throws java.lang.Exception {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();

    int gcd = gcd(a, b);
    System.out.println(gcd);
  }

  private static int gcd(int a, int b) {
    if (b == 0) {
      return a;
    } else {
      return gcd(b, a % b);
    }
  }
}


/* 
import java.util.*;
class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int min = Math.min(a,b);		
		for(int i=min;i>=1;i--){
		    if(a%i==0 && b%i==0){
		        System.out.println(i);
		        break;
		    }
		}
	}
}

*/