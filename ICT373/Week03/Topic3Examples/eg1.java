
/**
 *
 * @author 20150534
 */

class Fraction {
    int numerator, denominator;

    Fraction(int a, int b) {
	numerator=a;
	denominator=b;
    }

    void print(){
    	System.out.println( numerator + " / " + 
			denominator );
    }
}

public class eg1 {
    public static void main(String[] args) {
		
        Fraction f = new Fraction(2,3);
	f.print();
    }
}

 
