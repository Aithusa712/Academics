/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iterators1;

/**
 *
 * @author 20150534
 */
//Here is a complete example:


// File: Pet.java
// Simple container with Iterator.
// P S Dhillon

import java.util.*;

public class Pet {
    private int petNumber;
    public Pet(int i) { petNumber = i; }
    public void displayPetId() {
        System.out.println("Pet No " + petNumber);
  }

    // client test method
  public static void main(String[] args) {
      List myPets = new ArrayList();
       // create 10 pet objects in the container myPets
      for (int i = 1; i <= 10; i++)
          myPets.add(new Pet(i));

      // create an iterator to select list objects
      Iterator it = myPets.iterator();

      // get each list object, and display it
      while(it.hasNext())
          ( (Pet)it.next() ).displayPetId();

  } // end main
} // end of class Pet 
