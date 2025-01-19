# Stream 
- is an object that delivers data to its destination (Screen, file, etc.) or takes data from a source (keyboard, file, etc.) and delivers it to your program.
- Input stream - a stream that provides input to a program, e.g. System.in
- Output stream - a stream that accepts output from a program, e.g. System.out


## java.io package
- Two class hierarchies of stream classes: 
	1. Byte streams - read and write binary data
	2. Character streams - to read and write textual info
- Byte-based super classes:
	- InputStream - read raw bytes of data from a stream
	- OutputStream - sends raw bytes of data to a target such as the console or a network server
- Character-based classes:
	- Reader - read character-based input
	- Writer - writes out character-based output


# Persistence
- The ability to store a state of an object and later retrieve it.
## Serialization 
- Process of reading and writing objects is called *object serialization*

##### To serialize an object:
1. Declare the class of the object implements Serializable
```java
import java.io.*;
public class MyClass implements Serializable{

}
```
2. Take the desire OutputStream and decorate it to an ObjectOutputStream to get X 
```java
FileOutputStream file = new FileOutputStream("myObjectFile.dat")
ObjectOutputStream out = new ObjectOutStream(file);
```
3. call writeObject
```java
MyClass oldObject = new MyClasss();
out.writeObject(oldObject);
```

##### To de-serialize:
1. Initialize an ObjectInputStream and decorate it with an inputStream
```java
FileInputStream file = new FileInputStream ("myObjectFile.dat")
ObjectInputStream in = new ObjectInputStream(file)
```
2. Call readObject()
```java
Myclass newObject = (MyClass)in.readObject();
```

## Controlling/Customizing Serialization
- If a class implements Serialization, parts of the object can be declared *transient* which will not be stored when serialized.


## RTTI (Run-Time Type Identification)
- Finding out more specific information about the type of an object as the program runs.
- Two ways to get a reference to a class object: 
	1. call a method from the Class "Class" which is 'forName()' (Requires a string param)
	2. or use "Class x = y.class;"
	- Example:
	```java
	    Employee e1 = new FullTimeEmployee();
        e1.test();
        Class c1 = Class.forName("Employee");
        Class c2 = FullTimeEmployee.class;
        System.out.print("Class represented by c1: "
                + c1.toString());
        System.out.print("\nClass represented by c2: "
                + c2.toString());
	```
-  To perform RTTI for classes there are two ways to do this in java
	1. using the keyword *instanceof* to return a Boolean answer
		- Example: if(Employee *instanceof* FullTimeEmployee){ .............}
	2. using the *isInstance* method to return a Boolean answer
		- Example: Employee.class.*isInstance*(e1);
- Purpose of this test is to check the exact type of a class which you are not sure of before downcasting it.

## Reflection
- is a java mechanism to overcome RTTI limitation.
- Reflection is supported in Java by 
	1. methods in the 'Class' class
	2. in a specific library java.lang.reflect
		- you can use Method class from the library. Example:
			- Method[] m = c2.getMethods();

## Passing, Cloning, Returning Objects
#### Passing
- In java, everything is passed by value depending on the type of argument being passed.
- If it is a primitive type (int, char, double, the changes to the parameter does not affect the original variable
- Objects are passed by reference, the parameter is a reference to the object making it a reference type.
- If it is a Reference type (Objects, Array, Strings), methods can change the fields or state of an object

#### Cloning
- is a method for object duplication
- This can be done two ways:
	1. Making your own copy constructor
	2. Using built-in cloning facilities
		1. Declare class implements the Cloneable interface
		2. override the clone() method
		3. call super.clone() method inside your clone() method
		- Example: 
		```java
		@Override public Person clone() throws CloneNotSupportedException {            return (Person) super.clone(); 
		```

#### Shallow Copy
- two or more reference variables of the same type points to the same object.
- ![[Pasted image 20241122163615.png]]
#### Deep Copy
- Each reference variable of the same time point to it's own object
- ![[Pasted image 20241122163723.png]]