/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RmiPack;

/**
 *
 * @author 20150534
 */
import java.rmi.Remote;
import java.rmi.RemoteException;
 
public interface Message extends Remote {
    void sayHello(String name) throws RemoteException;
}