/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package staticdynamicbinding;

import java.util.Collection;
import java.util.HashSet;

/**
 *
 * @author 20150534
 */
public class StaticBindingTest {

  public static void main (String args[])  {
       Collection c = new HashSet ();
       StaticBindingTest et = new StaticBindingTest();
       et.sort (c);         
    }

    //overloaded method takes Collection argument
    public Collection sort(Collection c) {
        System.out.println ("Inside Collection sort method");
        return c;
    }     

   //another overloaded method which takes HashSet argument which is sub class
    public Collection sort (HashSet hs){
        System.out.println ("Inside HashSet sort method");
        return hs;
    }         
}
    

