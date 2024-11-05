/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iterators2;

/**
 *
 * @author 20150534
 */
// File: Pet1.java
// Simple container - does not need Iterator.
// uses generics and enhanced for loop of jdk1.5/1.6
// P S Dhillon

import java.util.*;

public class Pet1 {
    private int petNumber;
    public Pet1(int i) { petNumber = i; }
    public void displayPetId() {
        System.out.println("Pet No " + petNumber);
  }

    // client test method
  public static void main(String[] args) {

      List<Pet1> myPets = new ArrayList<Pet1>();
      // create 10 pet objects in the container myPet
      for (int i = 1; i <= 10; i++)
          myPets.add(new Pet1(i));

  // get each list object using enhanced for loop of jdk1.5  
    for (Pet1 p : myPets)
         p.displayPetId();

  } // end main
} // end of class Pet1
 
