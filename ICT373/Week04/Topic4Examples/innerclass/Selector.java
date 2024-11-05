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
/*We suppose that an interface called Selector is. A generally available 
Selector operates on some collection of objects, being able to deliver one at a 
time in some order.*/

interface Selector {
	boolean end();
	Object current();
	void next();
} 
//end of interface
