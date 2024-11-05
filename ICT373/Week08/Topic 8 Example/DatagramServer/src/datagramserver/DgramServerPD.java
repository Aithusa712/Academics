/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datagramserver;

/**
 *
 * @author 20150534
 */
// File: DgramServerPD - Modified by P S Dhillon from Deitel & Deitel
// Connectionless Client/Server Interaction with Datagrams
// The server echos datagrams

import java.io.*;
import java.net.*;

public class DgramServerPD {

  static final int PORT = 2000;
  private DatagramPacket sendPacket, receivePacket;
  private DatagramSocket socket;

  public DgramServerPD() {

    try {
      // create DatagramSocket for sending and receiving packets
      socket = new DatagramSocket(PORT);
      System.out.println("SERVER STARTED:");

      // block until a datagram appears
      waitForPackets();
    } catch( SocketException e ) {
      System.out.println("Cannot open socket.");
      e.printStackTrace();
      System.exit(1);
    }
  } // end DgramServerPD constructor

  // wait for packets to arrive, display data and echo packet to client
  public void waitForPackets() {
    while ( true ) { // loop for ever
      try {
        // set up packet
        byte data[] = new byte[1000];
        receivePacket = new DatagramPacket(data,data.length);

         // wait for packet
         // method receive blocks until packet arrives
       socket.receive( receivePacket );

        // process packet
        String received =
            "\nPacket received:" +
            "\nFrom host: " + receivePacket.getAddress() +
            "\nHost port: " + receivePacket.getPort() +
            "\nMessage Length: " + 
		receivePacket.getLength() +
            "\nContaining:\n\t" +
            new String( receivePacket.getData(), 0,
                        receivePacket.getLength() ) ;

        System.out.println (received);

        // echo packet back to client
        System.out.println("\n\nEcho packet to client...");

        // create packet to send
        sendPacket = new DatagramPacket( 
			   receivePacket.getData(),
                         receivePacket.getLength(),
                         receivePacket.getAddress(),
                         receivePacket.getPort() );
        // send packet to client
        socket.send( sendPacket );
        System.out.println( "Packet sent\n" );

      } catch( IOException e ) {
        System.out.println("Communication error.");
        e.printStackTrace();
      }
    } // end while
  } // end waitForPackets


  public static void main( String args[] ) {
    new DgramServerPD();
  } // end main

} // end class DgramServerPD




