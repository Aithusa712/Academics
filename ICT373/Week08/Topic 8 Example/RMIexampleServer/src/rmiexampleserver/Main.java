/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rmiexampleserver;

/**
 *
 * @author https://edwin.baculsoft.com/2012/01/a-simple-java-rmi-tutorial/
 * 20150534
 */
//import com.edw.rmi.MessageImpl;
//import RmiPack.MessageImpl;
import RmiPack.MessageImpl;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
 
public class Main {
     
    private void startServer(){
        try {
            // create on port 1099
            Registry registry = LocateRegistry.createRegistry(1099);
             
            // create a new service named myMessage
            registry.rebind("myMessage", new MessageImpl());
        } catch (Exception e) {
            e.printStackTrace();
        }      
        System.out.println("system is ready");
    }
     
    public static void main(String[] args) {
        Main main = new Main();
        main.startServer();
    }
}