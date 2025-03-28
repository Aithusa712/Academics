/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jabberserver;

/**
 *
 * @author 20150534
 */

//: JabberServer.java from Eckel

// Very simple server that just
// echoes whatever the client sends.

import java.io.*;
import java.net.*;

public class JabberServer { 
    
    // Choose a port outside of the range 1-1024:
    public static final int PORT = 8080;
    public static void main(String[] args) 
                    throws IOException {

    ServerSocket s = new ServerSocket(PORT);
    System.out.println("Started: " + s);
    try {
        // Blocks until a connection occurs:
        Socket socket = s.accept();
        try {
            System.out.println("Connection accepted: "+ socket);
            BufferedReader in =new BufferedReader(new InputStreamReader(
                    socket.getInputStream()));
            // Output is automatically flushed 
            // by PrintWriter:
            PrintWriter out = new PrintWriter(new BufferedWriter(
                    new OutputStreamWriter(socket.getOutputStream())),true);
            while (true) { 
                String str = in.readLine();
                if (str.equals("END")) break;
                System.out.println("Echoing: " + str);
                out.println(str);
            } // end while
            
            // Always close the two sockets...
        }
        finally {
            System.out.println("Server closing...");
            socket.close();
        } // end inner try block
    } 
    finally{
        s.close();
    } // end outer try block
    } // end main method
    
} // end class JabberServer

 
