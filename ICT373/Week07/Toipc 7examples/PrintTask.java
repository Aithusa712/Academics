/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package printtask;

/**
 *
 * @author 20150534
 */
// Fig. 26.3: PrintTask.java from Deitel 9th Ed
// PrintTask class sleeps for a random time from 0 to 5 
// seconds
import java.util.Random;

public class PrintTask implements Runnable {
   private int sleepTime; // random sleep time for thread
   private String threadName; // name of thread
   private static Random generator = new Random();

   // constructor - assign name to thread
   public PrintTask(String name) {
      threadName = name; // set thread name

      // pick random sleep time between 0 and 5 seconds
      sleepTime = generator.nextInt(5000); // milliseconds
   } // end PrintTask constructor

   // method run contains the code a thread will execute
   @Override
   public void run() {
      try // put thread to sleep for sleepTime millisecs
      {
         System.out.printf("%s going to sleep for %d milliseconds.\n",
               threadName, sleepTime);

         Thread.sleep(sleepTime); // put thread to sleep
      } // end try
        // if thread interrupted while sleeping, print stack trace
      catch (InterruptedException exception) {
         exception.printStackTrace();// "%s %s\n", threadName, "terminated prematurely due to interruption" );
         Thread.currentThread().interrupt();
      } // end catch

      // print thread name
      System.out.printf("%s done sleeping\n", threadName);
   } // end method run
} // end class PrintTask
