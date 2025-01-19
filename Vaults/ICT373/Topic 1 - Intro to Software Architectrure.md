
## Design in Software Development
- For a consumer product there are **three** important stages:
	1. *Concept Formation* - The need for the product and its *function are defined*.
	2. **Design** - Methods of *achieving the required functions* are invented.
	3. *Manufacture* - The design *turned into a physical product*.

#### Factors in Design
- **Organization** - *structure* and organization of data
- **Function** - *Activities* to occur
- **Control** - Order of *functions*
- **Packaging** - how functions *fit* into the structure
- **Data** - *data structure, files, databases, ....*

#### Constraints in Design
- **Timing/Prerequisites** - activities may have to complete within a certain time.
- **Capacity** - amount of data, data transfer, storage mechanism.

#### Software Architecture
- The organization of sub-systems
- An architecture is foremost an abstraction of a system that suppresses those details of components that do not affect the use, the relations and interactions of components.
- Architecture determines how components interact, not how they are implemented.

> [!NOTE]
> - The software architecture of a program or computing is the structure or structures of the system, which comprise software elements, externally visible properties of those elements, an the relationship among them.

## Complexity of Software Systems
- Software systems are some of the most complex systems
- complexity is inherent because of the combination of its elements which are individually complex:
	1. problem domain
	2. development process
	3. flexibility possible in using software
	4. characterizing behavior

#### Managing Complexity
- Decomposition - breaking a system into a set of smaller, relatively independent part that are hopefully easier to understand.
	- This process can be repeated until the component are small enough to understand completely

##### Decomposition
- This is the classical approach to software decomposition is top-down structured design.
- An alternative is the object-oriented approach.

##### Object-oriented approach
- Identify important abstractions of the problem and model them as objects.

##### Abstraction 
- involves ignoring everything that is not absolutely essential to the problem. Art is in choosing  the best abstractions to use and what details have to be kept and modelled.
##### Hierarchy
- organize abstractions into hierarchies that impose a certain logical structure which simplifies the problem.


#### Models

##### Predictive models
- Process-oriented
- The scope of the software project can be clearly articulated and the schedule and cost can be predicted.
- input -> Project design & development -> Evaluation -> Project delivery.


##### Adaptive models 
- People Oriented
- When requirements cannot be expressed early in the lifecycle
- Developed using an iterative approach, and development risk is risk-driven and change tolerant
- Project brainstorming & development -> Production -> Delivery of component -> Feedback -> Project brainstorming & development -> .....


## Role of Design in Software Design Lifecycle (SDLC)
- Process of design is an important state of the SDLC the phases are:
	- **Requirements Analysis**: Determine what is needed from the system
	- **Specification**: Precise detailed statement of what the system should do
	- **Design**: Describe how the system will do it
	- **Implementation**: Code the design
	- **Testing**: Show that it works as required
	- **Installation** (including user training)
	- **Maintenance**
## Software Architectures Examples:
- Pipes and filters
- Data Abstraction and O-O organization
- Client-Server Architectures


## Pipe and Filter Architecture
![[Pasted image 20241121025126.png]]

#### Filter:
- stream(s) of data in
- stream(s) of data out
- usually local transformation of input(s)
- incremental computation: output commences before input is consumed
- All data do not need to be processed for next filter to start working.

#### Pipe:
- Connector of filters
- Transfers output of one filter to inputs of another (without change)
- May be bounded in capacity
- May be type restricted


