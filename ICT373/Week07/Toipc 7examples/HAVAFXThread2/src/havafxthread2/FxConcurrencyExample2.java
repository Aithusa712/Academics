/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package havafxthread2;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author 20150534
 */

/*
The above program is your first, incorrect attempt to provide a solution. The ActionEvent handler for the Start Button calls the startTask() method, 
which creates a new thread and runs the runTask() method in the new thread.
Run the program and click the Start Button. A runtime exception is thrown.

statusLabel.setText(status); 
causes the problem.

The JavaFX runtime checks that a live scene must be accessed from the JavaFX Application Thread.
The runTask() method is run on a new thread, named Thread-4 as shown in the stack trace, which is not the JavaFX Application Thread.
The foregoing statement sets the text property for the Label, which is part of a live Scene Graph, from the thread other than the 
JavaFX Application Thread, which is not permissible.

*/
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
 
public class FxConcurrencyExample2  extends Application
{
    // Create the TextArea
    TextArea textArea = new TextArea();
     
    // Create the Label
    Label statusLabel = new Label("Not Started...");
 
    // Create the Buttons
    Button startButton = new Button("Start");
    Button exitButton = new Button("Exit");
     
    public static void main(String[] args) 
    {
        Application.launch(args);
    }
     
    @Override
    public void start(final Stage stage) 
    {
        // Create the Event-Handlers for the Buttons
        startButton.setOnAction(new EventHandler <ActionEvent>() 
        {
            public void handle(ActionEvent event) 
            {
                startTask();
            }
        });
 
        exitButton.setOnAction(new EventHandler <ActionEvent>() 
        {
            public void handle(ActionEvent event) 
            {
                stage.close();
            }
        });
         
        // Create the ButtonBox     
        HBox buttonBox = new HBox(5, startButton, exitButton);
         
        // Create the VBox
        VBox root = new VBox(10, statusLabel, buttonBox,textArea);
         
        // Set the Style-properties of the VBox
        root.setStyle("-fx-padding: 10;" +
                "-fx-border-style: solid inside;" +
                "-fx-border-width: 2;" +
                "-fx-border-insets: 5;" +
                "-fx-border-radius: 5;" +
                "-fx-border-color: blue;");
 
        // Create the Scene
        Scene scene = new Scene(root,400,300);
        // Add the scene to the Stage
        stage.setScene(scene);
        // Set the title of the Stage
        stage.setTitle("A simple Concurrency Example");
        // Display the Stage
        stage.show();               
    }
     
    public void startTask() 
    {
        // Create a Runnable
        Runnable task = new Runnable()
        {
            public void run()
            {
                runTask();
            }
        };
         
        // Run the task in a background thread
        Thread backgroundThread = new Thread(task);
        // Terminate the running thread if the application exits
        backgroundThread.setDaemon(true);
        // Start the thread
        backgroundThread.start();
    }
         
    public void runTask() 
    {
        for(int i = 1; i <= 10; i++) 
        {
            try
            {
                String status = "Processing " + i + " of " + 10;
                statusLabel.setText(status);
                textArea.appendText(status+"\n");
                Thread.sleep(1000);
            }
            catch (InterruptedException e) 
            {
                e.printStackTrace();
            }
        }
    }       
}