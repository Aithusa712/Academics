/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package abstractclass;

/**
 *
 * @author 20150534
 */
abstract class Shape{
    abstract void draw();
}
//In real scenario, implementation is provided by others i.e. unknown by end user
class Rectangle extends Shape{
    @Override
    void draw(){System.out.println("drawing rectangle");}
}

class Circle1 extends Shape{
    @Override
    void draw(){System.out.println("drawing circle");}
}

//In real scenario, method is called by programmer or user
class AbstractClass{
    public static void main(String args[]){
        Shape s=new Circle1();//In real scenario, object is provided through method e.g. getShape() method
        s.draw();
    }
}
