/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package javafxsimpleapp;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class SimpleApp extends Application {
   private TextField tfCount, textt;
   private Button btnCount;
   private int count = 0;

   @Override
   public void start(Stage primaryStage) {
      // Allocate controls
      tfCount = new TextField("0");
      tfCount.setEditable(false);

      // textt=new TextField();

      btnCount = new Button("Press & Count");
      // Register event handler using Lambda Expression (JDK 8)
      btnCount.setOnAction((ActionEvent evt) -> {
         tfCount.setText(++count + "");
      });

      // Create a scene graph of node rooted at a FlowPane
      FlowPane flow = new FlowPane();
      flow.setPadding(new Insets(15, 12, 15, 12)); // top, right, bottom, left
      flow.setVgap(10); // Vertical gap between nodes in pixels
      flow.setHgap(10); // Horizontal gap between nodes in pixels
      flow.setAlignment(Pos.CENTER); // Alignment

      flow.getChildren().addAll(new Label("Counts: "), tfCount, btnCount);

      // Setup scene and stage
      primaryStage.setScene(new Scene(flow, 400, 80));
      primaryStage.setTitle("JavaFX SimpleApp");
      primaryStage.show();

   }

   public static void main(String[] args) {
      launch(args);
   }
}
