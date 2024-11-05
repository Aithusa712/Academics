/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thisvssuper;
// B.java
// ICT373 Topic4 example

class A {
    private int number;
    A() {number = -1;}  	// usually initialised to 0
    A (int n) {number = n;}
    public int getNumber () {return number;}
} // end class A

public class thisvssuper extends A {
    private char initial;
    B() { }
    B (int n) { super(n); initial = '?';}
    B (int n, char c) {this(n); initial = c;}
  		// alternatively, use:         B (int n, char c) {super(n); initial = c;}
    public char getInitial(){
       return initial;
    }

    public static void main (String[] args){
   	B one = new B();
   	B two = new B(5);
   	B three = new B(7, 'a');
   	System.out.println(one.getNumber() + "  " 
            + one.getInitial());
   	System.out.println(two.getNumber() + "  " 
            + two.getInitial());
   	System.out.println(three.getNumber() + "  " 
            + three.getInitial());

  	 // Upcasting & Downcasting Example
   	A parent = new A();
   	parent = three;  // parent object now refers to a child // object - UPCASTING
   	
        // Alternatively,  A parent = new B(7, 'a');
        
   	System.out.println(parent.getNumber());

   	// Note: now calling parent.getInitial() will produce 
   	// compilation error, so we must DOWNCAST as below:
   	System.out.println( ((B)parent).getInitial() );

   } // end main

}// end class B

