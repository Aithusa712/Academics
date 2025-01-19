
## Important elements in OOSE
- Abstraction - dealing with the essential features of something while ignoring the detail
	- ex. defining a class instead of dealing with a bunch of separate objects.
- Encapsulation - providing things with protected member variables which can only access via public methods.
- Information-hiding - hiding or encapsulating the details
- Localization - allow changes inside a class/object to be made while the public interface is unaffected
- Name-management - prevent confusion and clashes with identifier names
- Reuse - using existing classes without changing their code
	- Two ways to accomplish reuse
	1. Composition - create objects of your existing class inside the new class, meaning that the new class is composed of objects of existing classes. Reusing the functionality of the code
	2. Inheritance - create new class as a type of an existing class, making it possible to use the methods/functions of the parent class.

## Libraries and Packages
- A package is a collection of related classes that have been grouped together 
- To make a package available we need to use the import keyword, e.g. import java.util.*

## General Access Modifiers
- Public means that this class can be used by any other class. 
- These stop clients from using things/ or methods that could risk making the program incorrectly
	![[Pasted image 20241121170100.png]]
	
## Inheritance
-   In java we use the following syntax:
```  java
class ObjectChild extends  ObjectParent{
	method and variable declarations
		}
```

## Overriding vs Overloading
- Overriding is calling a method with the same name as the Parent Class and overrides the method in the Parent Class 
- Overloading is using the same name with a different parameter. Overloading can happen between and inside classes.

## Static vs Dynamic Binding
- Static binding in java occurs during Compile time while Dynamic binding occurs during Runtime
- Private, final, and static methods and variables uses static binding and bonded by the compiler while virtual methods are bonded during runtime upon runtime object.
- ![[Pasted image 20241121171557.png]]
## Polymorphism
- Occurs when we have many classes that are inherited to each other by inheritance.
- A subclass can be upcasted to superclass

## Downcasting
- Upcasting a child class to a parent class can always be done. However, if we want to call a method from the parent class to child class we would need to downcast it first. 
- Downcasting involves a risk of a runtime error.

## Abstract Classes 
- Are intended to be used only as superclasses. They can not be used to instantiate objects.
- An abstract class normally contains one or more abstract methods.
- Example.
``` java
// Abstract class
abstract class Sunstar {
    abstract void printInfo();
}

// Abstraction performed using extends
class Employee extends Sunstar {
    void printInfo()
    {
        String name = "avinash";
        int age = 21;
        float salary = 222.2F;

        System.out.println(name);
        System.out.println(age);
        System.out.println(salary);
    }
}

// Base class
class Base {
    public static void main(String args[])
    {
        Sunstar s = new Employee();
        s.printInfo();
    }
}
```

## Concrete Class
- used to instantiate objects.
- provides implementations for every method they declare.
- can be used to override methods in a abstract class

## Final Methods and Classes
- Opposite of abstract is final
- A method declared final in a class cannot be overridden
- A class declared final will not be allowed to be inherited from ( cannot be a superclass )

## Interfaces 
- is just a form of inheritance
- an interface in java is like a complete abstract class. All of it's methods are abstract.
- To define an interface use
- No modifiers should be use because they are redundant
- Interface can extend one or more other interfaces
- Classes can implement interfaces
- The class has to override all of the methods of the interface or has to be declared abstract
- Example. 
```java
// Interface
interface Animal {
  public void animalSound(); // interface method (does not have a body)
  public void sleep(); // interface method (does not have a body)
}

// Pig "implements" the Animal interface
class Pig implements Animal {
  public void animalSound() {
    // The body of animalSound() is provided here
    System.out.println("The pig says: wee wee");
  }
  public void sleep() {
    // The body of sleep() is provided here
    System.out.println("Zzz");
  }
}

class Main {
  public static void main(String[] args) {
    Pig myPig = new Pig();  // Create a Pig object
    myPig.animalSound();
    myPig.sleep();
  }
}
```


## Interface vs Abstract Class
- Interface is used when all classes has same structure but totally have different functionality.
- Abstract class is used when all classes has the same structure but some have different functionality.

## Inner Classes
- a class declared inside another class

## Callback functions
- Another use for inner classes
- With  a callback, other object is given a piece of information that allows it to callback into the originating object at some later point
- When an event or method is called and finished they will receive a callback reference to another object or method.
- This allows programs to execute task independently and the result will be handled later.

## Java collection Framework
- framework is a set of classes that form the basis for building advanced functionality
- The JCF (Java Collections Framework) is a hierarchy of classes, abstract classes, interfaces that implement commonly usable collection data structures.
	- There are two fundamental interfaces for JCF
		- Collection - define value for each item in the data structure
		- Map - define a pair of items, key value, for each element/node in the data structure.
- java.util.Collection - is the root interface, it contains the interfaces such as List, Queue, and set. It also contains methods for those interfaces such as add(), remove(), toArray(), contains() for a collection
- java.util.List - interface is an ordered collection that can contain duplicate elements, interface list is implemented by several classes including ArrayList, LinkedList, vector
- java.util.Queue interface - is a First in First out (FIFO) collection that models a waiting line
- java.util.Set interface - is a collection that does not contain any duplicates
- java.util.Map - a interface that associate keys to values and cannot contain duplicate keys the Interface Map is implemented by classes  HashMap, TreeMap and LinkedHashMap
- All collections have an iterator that goes through all of the elements in the collection.

## Collection classes
- The following provides routine implementation of the interface methods:
	- AbstractCollection
	- AbstractList
	- AbstractSequentialList
	- AbstractSet
	- AbstractQueue
	- AbstractMap
- The following are concrete classes provided by the Java library:
	- ArrayList
	- LinkedList
	- ArrayQueue
	- PriorityQueue
	- HashSet
	- TreeSet
	- HashMap
	- TreeMap
- The following are Legacy container classes available before there was a collection framwork:
	- Vector
	- Stack
	- Hashtable
	- Properties


## Exception
- Exception is a java hierarchy that handles errors
- Exception allows unusual situations to be handles without disrupting the normal code.
- The syntax for Exception handling is :
```java

public class ExceptionExample {
    public static void main(String[] args) {
        try {
            int result = divide(10, 0);
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero");
        } catch (IOException e) {
            System.out.println("Error: IO Exception");
        } finally {
            System.out.println("This will always execute.");
        }
    }

    public static int divide(int a, int b) throws IOException {
        if (b == 0) {
            throw new ArithmeticException("Division by zero");
        }
        return a / b;
    }
}
```

- try block - execute the code
- catch block - catches any exception and will execute that block if a exception were to happen
- finally block - will always execute 
- throwing an exception  can be built in  or user defined