/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxthread;

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

It is repeated to emphasize that all UI event handlers in JavaFX run on a single thread, which is the JavaFX Application Thread.
When the Start Button is clicked, the runTask() method is executed in the JavaFX Application Thread.
When the Exit Button is clicked while the task is running, an ActionEvent event for the Exit Button is generated and queued on 
the JavaFX Application Thread. The ActionEvent handler for the Exit Button is run on the same thread after the thread is done
running the runTask() method as part of the ActionEvent handler for the Start Button.
A pulse event is generated when the Scene Graph is updated. The pulse event handler is also run on the JavaFX Application Thread. 
Inside the loop, the text property of the Label was updated ten times, which generated the pulse events. 
However, the Scene Graph was not refreshed to show the latest text for the Label, as the JavaFX Application Thread was busy 
running the task and it did not run the pulse event handlers.
Both problems arise because there is only one thread to process all UI event handlers and you ran a long-running task in 
the ActionEvent handler for the Start button.
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
 
public class FxConcurrencyExample1  extends Application
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
                runTask();
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
        VBox root = new VBox(10, statusLabel, buttonBox, textArea);
         
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