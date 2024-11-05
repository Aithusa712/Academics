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
//Sequence.java

public class Sequence {
    private Object[] o;
    private int next=0;
    

    public Sequence(int size){
        o= new Object[size];
    }
	
    public void add(Object x){
        if (next < o.length){
            o[next]=x;
            next++;
        }//end if
    }//end add
 
	//inner class
    private class SSelector implements Selector {
        // provides the functionality of interface Selector
        int i=0;
        
        public boolean end(){
            return i == o.length; // an inner class has automatic access to             
        }	// members of the enclosing class.
        
	public Object current(){
            return o[i];
        }
	
        public void next(){
            if (i<o.length) i++;
        }
    }//end of class SSelector
	
	
    public Selector getSelector(){
        return new SSelector();
    }
	
    public static void main(String[] args){
        
        Sequence s = new Sequence(10);
        for (int i=0; i<10; i++)
            s.add(Integer.toString(i));
        SelPrint.selPrint(s.getSelector());
    }//end main
}//end class Sequence
