import java.awt.Color;

import javax.swing.ButtonGroup;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.scene.text.*;
import javafx.geometry.Pos;

public class javafxtest extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		Button View = new Button("View");
		Button View1 = new Button("buzz");
		Button Create = new Button("Create");
		Button Edit = new Button("Edit");
		Text sampleText = new Text("test");
		HBox ButtonMenu = new HBox(View, Create, Edit);

		GridPane gridLayout = new GridPane();
		GridPane informationLayout = new GridPane();
		gridLayout.setVgap(5);
		gridLayout.setHgap(5);
		ButtonMenu.setAlignment(Pos.CENTER);
		informationLayout.setAlignment(Pos.CENTER);
		// gridLayout.setAlignment(Pos.CENTER);
		informationLayout.add(sampleText, 0, 0);
		informationLayout.add(View1, 0, 1);
		informationLayout.setStyle("-fx-background-color: blue;");
		gridLayout.setStyle("-fx-background-color: red;");

		informationLayout.setMinSize(200, 400);
		gridLayout.setMinSize(200, 500);
		gridLayout.add(ButtonMenu, 0, 0);

		gridLayout.add(informationLayout, 0, 1);

		Scene testScene = new Scene(gridLayout);
		primaryStage.setTitle("TEST");
		primaryStage.setScene(testScene);
		primaryStage.show();
	}

	public static void main(String args[]) {
		launch(args);
	}
}
