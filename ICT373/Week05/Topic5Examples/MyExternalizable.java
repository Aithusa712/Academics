/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package externalizableexample;

import java.io.Externalizable;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

public class MyExternalizable implements Externalizable
{

private String userName;
private String passWord;
private Integer roll;

public MyExternalizable()
{

}

public MyExternalizable(String userName, String passWord, Integer roll)
{
    this.userName = userName;
    this.passWord = passWord;
    this.roll = roll;
}

@Override
public void writeExternal(ObjectOutput oo) throws IOException 
{
    oo.writeObject(userName);
    oo.writeObject(roll);
}

@Override
public void readExternal(ObjectInput oi) throws IOException, ClassNotFoundException 
{
    userName = (String)oi.readObject();
    roll = (Integer)oi.readObject();
}

public String toString()
{
    StringBuilder b = new StringBuilder();
    b.append("userName: ");
    b.append(userName);
    b.append("  passWord: ");
    b.append(passWord);
    b.append("  roll: ");
    b.append(roll);

    return b.toString();
}
public static void main(String[] args)
{
    try
    {
        MyExternalizable m  = new MyExternalizable("nikki", "student001", 20);
        System.out.println(m.toString());
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("temp1.txt"));
        oos.writeObject(m);
        oos.close();

        System.out.println("***********************************************************************");
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("temp1.txt"));
        MyExternalizable mm = (MyExternalizable)ois.readObject();
        mm.toString();
        System.out.println(mm.toString());
    } 
    catch (ClassNotFoundException | IOException ex)
    {
        Logger.getLogger(MyExternalizable.class.getName()).log(Level.SEVERE, null, ex);
    }
}

}