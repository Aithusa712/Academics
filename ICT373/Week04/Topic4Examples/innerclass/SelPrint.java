/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication13;

/**
 *
 * @author 20150534
 */
//SelPrint.java

public class SelPrint {
    public static void selPrint(Selector s){
        while (!s.end()){
            System.out.println((String)s.current());
            s.next();
        }//end while
    }//end selPrint   
}//end of class SelPrint
