/** File name: Local.java
*   Purpose: to demonstrate a local inner class
*   References: ICT373 Topic4.doc
*/
/* created by P Dhillon; revised by F Sohel*/
public class Local {
    final double INTEREST_RATE = 0.08;
    final String s1 = "Good investment";
    final String s2 = "Bad investiment";

    public void print() {
        if (INTEREST_RATE > 0.07) {

            // an inner class is nested inside the scope of an if statement

            class HighInterestRate {
                /* str is a data member.
                 * The inner class can access to final local variables
                 * (ie. constants) (e.g. s1 below) of the outer class.
                 */
                private String str = new String(s1);

                // a method
                public void print() {
                    System.out.println(str);
                }
            } // end of class HighInterestRate

            HighInterestRate hir = new HighInterestRate();
            hir.print();

        } // end of if statement
    } // end of print()


    public static void main(String[] args) {
        Local loc = new Local();
        loc.print();
    }
}

/* Note that there are two print() methods in the code above:
 * the first print() method is inside the inner class
 * HighInterestRate; the second print() method is inside the
 * outer class Local.
 *
 * The inner class HighInterestRate is nested inside the scope
 * of an if statement which is a statement inside the print()
 * method of the class Local.
 */


