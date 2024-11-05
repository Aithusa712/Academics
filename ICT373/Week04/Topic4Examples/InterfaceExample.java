package interfaceexample;

class Rectangle implements Drawable{ 
    @Override
    public void draw(){
        System.out.println("drawing rectangle");
    }  
}  
class Circle implements Drawable{  
    @Override
    public void draw(){
        System.out.println("drawing circle");
    }  
}  
//Using interface: by third user  
public class InterfaceExample{  
    public static void main(String args[]){  
        Drawable d=new Circle();//In real scenario, object is provided by method e.g. getDrawable()  
        d.draw();  
    }
} 


