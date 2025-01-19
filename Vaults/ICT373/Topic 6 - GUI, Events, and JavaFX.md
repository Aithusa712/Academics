## GUI
- Graphical User Interface
	- a user friendly mechanism for interacting with an application
- A good GUI Design is:
	- nice looking components arranged nicely on the screen
	- correct, predictable and reasonable behavior
	- separate the GUI implementation from real computations underneath (Business Logic) 

#### State
- Represents a situation during the operation of a system in which it satisfies some condition, perform and action, or wait for some event to occur. States are given names

#### Transition
- Represents the relationship between two states indicating that a system (or an Object) will perform an action to transfer from one state to another.


## FSM 
- Finite State machine 
- Produce an overall system or component design
- Can check, mechanically, for correctness of a System/Component's behavior.
- In UML:
	![[Pasted image 20241122165106.png]]
## STD
- State Transition Diagram
- A diagrammatic representation of states and transitions
- In UML:
	- The Solid arrows are the transition 
	- The circle is the states
		![[Pasted image 20241122165313.png]]
## JavaFX
- is a Graphical User Interface (GUI)
- is a software platform for creating and delivering desktop applications
- A JavaFX application have three major components: Stage, Scene and Node
	- Stage - contains all the objects of a JavaFX application
		- The created stage object is passed as an argument to the start() method of the Application class
		- Stage class is from the package javafx.stage
		- A stage can have two parameters determining it's Width and height
		- Call show() method to display the content of a stage
		- A stage object must be passed as an argument in the start() method of the application class
	- Scene - represents the physical contents of a JavaFX application
		- Scene class is from the package javafx.scene
		- A scene can be created by instatiating the Scene
	- Scene Graph and Nodes - a scene graph is a tree-like data structure representing the contents of a scene
		- a node is a visual/graphical object of a scene graph
		- the Node class is from the package javafx.scene
		- a node may include:
			- Geometrical Objects
			- UI Controls
			- Containers
			- Media elements
		- Root Node - the first scene graph 
		- Leaf Node - a node without child nodes

## Steps to create a JavaFX Application
1. Instantiate the Application class to your class
		
	```java
	public class MyApp extends Application
	```
2. Create a start() method (an abstract method from Application class), override it, and pass a Stage argument inside it.
	```java
	@Override
	public void start(Stage stage) throws Exception{
	}
	```
3. Inside the start() method you need to prepare a scene graph, scene , and stage to add the scene.
	```java 
		VBox vbox = new VBox();
	    vbox.setAlignment(Pos.CENTER);
        Label stopLabel = new Label("Press the button to Stop");
        Button stopBtn = new Button("Stop");
        vbox.getChildren().addAll(stopLabel, stopBtn);
        Scene scene = new Scene(vbox, 400, 400);
        stage.setScene(scene);
        stage.show();
	```
4. inside main class call the launch() method with a string inside the parameter
	```java
	public static void main(String[] args){
		launch(args);
	}
	```
5. Compile and run.

## JavaFX Lifecycle
- There are three lifecycle methods:
	1. start() - entry point where the graphic code is to be written
	2. stop() - empty method that can be overridden, you can write the logic to stop application
	3. init() - empty method that can be overridden, you cannot create a stage or scene in this method.

## Overview of GUI components
- UI elements - core visual elements which the user can see and interact with.
- Layouts - how elements are organized on the screen
- Behavior - events which occur when user interacts with UI elements also known as Event Handlers


## Commonly used GUI controls
- Label
- Button
- CheckBox
- RadioButton
- ListView
- TextField
- Scrollbar
- FileChooser

## Layout Panes (Containers)
- Hbox - horizontal
- Vbox - vertical
- BorderPane - top, left right, bottom, center positions\
- StackPane - stack nodes on top of another
- FlowPane - wraps all nodes in a flow
- GridPane - arranges nodes as a grid of rows and columns


## Event Handling
- Whenever a user interacts with the application (nodes), event is occured.
- Two types of events:
	- Foreground Event:
		- direct interaction of a user
		- generated consequence of a person interacting with the GUI components
	- Background events:
		- events require the interaction of end user 

## Events in JavaFX
- Event Class from the javafx.event package is the base class
- the mechanism that control events and decide what should happen if an event occurs
- 
#### JavaFx Event Handling Example: 
```java
		stopBtn.setOnMouseClicked((new EventHandler<MouseEvent>() {
            public void handle(MouseEvent event) {
                stopLabel.setText("You pressed it wow");
            }
        }));
        // Lambda Expression
        resetBtn.setOnMouseClicked(event -> {
            stopLabel.setText("Press the button to Stop");
        });
```
