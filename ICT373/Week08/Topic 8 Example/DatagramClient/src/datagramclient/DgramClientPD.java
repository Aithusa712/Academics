/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datagramclient;

/**
 *
 * @author 20150534
 */
// File: DgramClientPD - Modified by P S Dhillon from Deitel & Deitel
// Connectionless Client/Server Interaction with Datagrams
// Client that sends and receives packets to/from a server.

import java.io.*;
import java.net.*;

public class DgramClientPD {

  private DatagramPacket sendPacket, receivePacket;
  private DatagramSocket socket;

  public DgramClientPD() {

    try {
      // create DatagramSocket for sending and receiving packets
      socket = new DatagramSocket(null);
      System.out.println("CLIENT:");

      // send packet
      CreateAndSendDatagram();

    } catch( SocketException e ) {
      System.out.println("Cannot open socket.");
      e.printStackTrace();
      System.exit( 1 );
    }
  } // end DgramClient constructor


  public void CreateAndSendDatagram() {
    try {
      for (int i = 1; i <=5; i++) {
        String str = "Message " + i;
        System.out.println( 
			"\nSending packet containing: " + str );


        byte data[] = str.getBytes();

        // create packet
        sendPacket = new DatagramPacket(data, 
				data.length,  
				InetAddress.getLocalHost(), 2000);
        
	// send packet
        socket.send( sendPacket );
        System.out.println( "Packet sent\n" );

        // block until a datagram echoes back:
        waitForPackets();
      } // end for

    } catch ( IOException exception ) {
      System.out.println( exception.getMessage());
      exception.printStackTrace();
    }
  } // end CreateAndSendDatagram


  public void waitForPackets() {
        try {
          // set up packet
          byte data[] = new byte[1000];
          receivePacket = new DatagramPacket( data, 
						data.length );
          // wait for packet
          socket.receive( receivePacket );
          // process packet
          String received =
              "\nPacket received:" +
              "\nFrom host: " + receivePacket.getAddress() +
              "\nHost port: " + receivePacket.getPort() +
              "\n Message Length: " + 
		receivePacket.getLength() +
              "\nContaining:\n\t" +
              new String( receivePacket.getData(), 0,
                          receivePacket.getLength() );
                          System.out.println(received);
          } catch( IOException e ) {
            System.out.println (e.getMessage());
            e.printStackTrace();
        } // end of try block
  } // end waitForPackets
  
public static void main( String args[] ) {
   DgramClientPD thisClient = new DgramClientPD();
   thisClient.waitForPackets();
  } // end main
} // end class
 
