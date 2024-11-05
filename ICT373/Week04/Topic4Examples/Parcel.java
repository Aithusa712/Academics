/** File name: Parcel.java
*   Purpose: to demonstrate inner classes
*   References: ICT373 Topic4.doc
*/
/* created by P Dhillon; revised by F Sohel*/

public class Parcel {

   String senderName;
   String receiverName;
   Contents contents;

   /** constructor for Parcel
   */
   public Parcel(String sn, String rn) {
      senderName = sn;
      receiverName = rn;

      String[] itemList = {
         "lecture notes", "assignments", "practicals"
      };

      contents = new Contents(itemList);
   }


   /* --- Contents is an inner class within the class Parcel --- */

   class Contents {
      private String[] items; // items: an array of String

      Contents(String[] items) {
         this.items = items;
      } // end constructor

      public void printItems() {
         for (int i=0; i < items.length; i++)
            System.out.println("item "  +  i  +  " is "  +  items[i]);
      }
   }// end of class Contents


   class AnotherInnerClass {
      // data members ...
      // methods ...
   }// end of AnotherInnerClass


   public void printParcel() {
      System.out.println("Sender's name is " + senderName);
      System.out.println("Receiver's name is " + receiverName);

      System.out.println("contents are: ");
      contents.printItems();
   }

   public static void main(String[] args) {
      Parcel parcel = new Parcel("Ferdous Sohel", "A N Other");
      parcel.printParcel();
   }// end main

}// end of class Parcel

/* OUTPUT
  Sender's name is Ferdous Sohel
  Receiver's name is A N Other
  contents are:
  item 0 is lecture notes
  item 1 is assignments
  item 2 is practicals
*/


