## Threads
- A process is a self-contained running program
- Multitasking  operating system is capable of running more than one process at a time
- A thread is a separate independently running subtask within a process.

## Threads in java
- Class Thread (in java.lang package) allows us to multithread.
- Class Thread implements a generic thread that does nothing.
- There are two ways of creating a thread of execution:
	1. Declare a class to be a subclass of Thread, to override the class Thread's run() method
	2. Provide a class that implements the Runnable interface
- The method of run()  (needs to be overridden) inside your extended or implemented class will contain the code you want to run
- When you call the start() method, the code in the run() will execute inside the current existing process.

## Runnable interface vs Thread
- The difference between the two is that:
	- When you extend the thread class, you can't extend to any other class you require.
	- When you implement Runnable, you can extend a class to one now or in the future

## Thread states and life cycle 
- New state - object has been created but not started
- Ready state - thread moves into ready state when the thread method start is invoked. It can do something now if the scheduler gives it a turn
- Running State - thread is assigned to a processor.
- Waiting state - running thread can transition to the waiting state while it waits for another thread to perform a task.
- Timed waiting state - a running thread can enter the timed waiting state for a specified interval of time.
- Blocked state - when it attempts to perform a task that cannot be completed immediately
- Terminated state- when it successfully complete it's task

Java