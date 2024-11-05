/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package order_super_subclass;

/**
 *
 * @author 20150534
 */
class A {
    A() {
    System.out.println("super Class constructor is called first");
    }  	// usually initialised to 0
    
    
} // end class A

public class Order_super_subClass extends A {
    Order_super_subClass () {
        System.out.println("sub Class constructor is called after");
    }
 
public static void main (String[] args){
   	Order_super_subClass one = new Order_super_subClass();  	     	

   } // end main

}// end class B

