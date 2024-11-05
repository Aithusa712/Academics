/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deepcopycnstructor;

/**
 *
 * @author 20150534
 */
public class Car {
     private int year;
     private String make;
     private Wheel wheel;

     /*Simple Constructor*/
     Car(int year, String make,Wheel wheel){
      this.year = year;
      this.make = make;
      this.wheel = wheel;
   
     }
   
     /*Copy Constructor.Note argument is also of type Car.*/
     Car(Car otherCar){
         this.year=otherCar.getYear();
         this.make=otherCar.getMake();
   
       /*Copying wheel object using Deep Copy*/
        Wheel wheel = new Wheel(otherCar.getWheel().getCompany());
        this.wheel=wheel;
     }
   
     public void setYear(int year){
         this.year =  year;
     }

     public int getYear(){
         return year;
     }
     public void setMake(String make){
         this.make=make;
     }

     public String getMake(){
         return make;
     }

    public void setWheel(Wheel wheel){
         this.wheel=wheel;
     }

     public Wheel getWheel(){
         return wheel;
     }
   
 public static void main(String args[]){

    Wheel wheel = new Wheel("Ceat");
    Wheel wheel1 = new Wheel("Ford");
    
    Car car1 = new Car(2011,"Toyota",wheel);

    System.out.println("Car1 description:");
    System.out.println("    Year:"+car1.getYear());
    System.out.println("    Make:"+car1.getMake());
    System.out.println("    Wheel Description:");
    System.out.println("        Company:"+car1.getWheel().getCompany());

    /*Invoking copy constructor.Creating copy of car1.*/
     Car car2 = new Car(car1);

    System.out.println("Car2 description(Copy of car1):");
    System.out.println("    Year:"+car2.getYear());
    System.out.println("    Make:"+car2.getMake());
    System.out.println("    Wheel Description:");
    System.out.println("        Company:"+car2.getWheel().getCompany());
    
   // DEEP Copyt check
   
        System.out.println("Car2 description(Copy of car1) proof:");

   car1.setWheel(wheel1);
  // car1.setWheel.setCompany("a");
    System.out.println("    Car 1 new wheel Company:"+car1.getWheel().getCompany());
    System.out.println("    Car 2 wheel Company:"+car2.getWheel().getCompany());


   }
 }

 class Wheel{
     private String company;
     Wheel(String company){
         this.company = company;
     }
     
 public void setCompany(String company){
         this.company=company;
     }

     public String getCompany(){
         return company;
     }

 }

