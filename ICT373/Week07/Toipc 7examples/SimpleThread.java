/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package threadexample;

/**
 *
 * @author 20150534
 */
// SimpleThread.java
// Very simple Threading example from Eckel

public class SimpleThread extends Thread {
    private int countDown = 5;
    private int threadNumber;
    private static int threadCount = 0;

    public SimpleThread() { // constructor
        threadNumber = ++threadCount;
        System.out.println("Making " + threadNumber);
    }

    @Override
    public void run() { // overrides Thread’s run method
        while (true) {
            System.out.println("Thread " +
                    threadNumber + "(" + countDown + ")");
            if (--countDown == 0)
                return;
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++)
            new SimpleThread().start();
        System.out.println("All Threads Started");
    }
}
