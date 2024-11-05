/** File name: House.java
*
*   Purpose: to demonstrate static inner class
*   References: ICT373 Topic4.doc, 
*/
/* created by P Dhillon; revised by F Sohel*/
public class House {

  static String houseType;

  /** constructor */
  public House(String t) {
    houseType = t;
  }

  /** a static inner class */
  public static class BedRoom {
    private static double width = 4;
    public static double length = 6;

    public static void print() {
      System.out.println("The bed room size is " +
                         width + " x " + length);
    } // end print

    /** the inner static class BedRoom can have its own
     *  static inner class.  Try putting a class inside
     *  the class BedRoom
     */

  } // end of class BedRoom

  public void print() {
    System.out.println("House type is: " + houseType);

    // call the print() method in the inner class
    BedRoom.print();

    // access to data members of an inner class
    double size = BedRoom.width; // okay
  } // end outer class method print

  /* Note that there are two print() methods in the code above:
   * one is inside the outer class House; another is inside the
   * inner class BedRoom.
   */

  public static void main(String[] args) {
    House myHouse = new House("mansion");

    myHouse.print();

    System.out.println();
    System.out.println("Create a House.BedRoom object");
    House.BedRoom myBedRoom = new House.BedRoom();
    myBedRoom.print();
  } // end main

}// end of class House

/* OUTPUT
House type is: mansion
The bed room size is 4.0 x 6.0

Create a House.BedRoom object
The bed room size is 4.0 x 6.0
*/

