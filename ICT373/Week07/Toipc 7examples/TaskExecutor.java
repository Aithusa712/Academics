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
// Fig. 26.4: TaskExecutor.java from Deitel 9th Ed
// Multiple threads printing at different intervals.
// Using an Executor Service to execute Runnables.
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class TaskExecutor {
	public static void main(String[] args) {
		// create and name each runnable
		PrintTask task1 = new PrintTask("thread1");
		PrintTask task2 = new PrintTask("thread2");
		PrintTask task3 = new PrintTask("thread3");

		System.out.println("Starting Executor");

		// create ExecutorService to manage threads
		ExecutorService threadExecutor = Executors.newCachedThreadPool();

		// start threads and place in runnable state
		threadExecutor.execute(task1); // start task1
		threadExecutor.execute(task2); // start task2
		threadExecutor.execute(task3); // start task3

		// shutdown worker threads when their tasks complete
		threadExecutor.shutdown();

		System.out.println("Threads started, main ends\n");
	} // end main
} // end class TaskExecutor
