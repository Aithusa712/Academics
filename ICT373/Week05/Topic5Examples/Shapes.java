/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication26;
import java.util.*;
 
interface Shape {
  void draw();
}
 
class Circle implements Shape {
    public void draw() {
    System.out.println("Circle.draw()");
  }
}
 
class Square implements Shape {
  public void draw() {
    System.out.println("Square.draw()");
  }
}

class Triangle implements Shape {
  public void draw() {
    System.out.println("Triangle.draw()");
  }
}
 
public class Shapes {
  public static void main(String[] args) {
    Vector s = new Vector();
  s.addElement(new Circle());
    s.addElement(new Square());
    s.addElement(new Triangle());
    Enumeration e = s.elements();
    while(e.hasMoreElements())
     ((Shape)e.nextElement()).draw();
  }
} 
