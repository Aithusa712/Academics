
## Client - Server Architecture:
![[Pasted image 20241121130900.png]]
#### Server :
- Central repository of information
- Centrally located so it can contain the latest info and can be changed easily
- Consists of
	- information
	- software to manage information
	- software to manage the distribution of information
	- central machines
#### Clients: each consist of:
- Software that:
	- communicates with the server
	- fetches the information
	- process the information 
	- display the information  for the user of the remote machine

#### Examples:
- Distribution of data (stock market, scientific, government)
- Taking online orders and credit-card transactions

#### Challenges:
- Congested/Overloaded servers
- Simultaneous transaction processing (ex. two transactions in a bank account)
- Supporting multiples types of client machines (hardware) and client operating systems (windows/Linux/Mac)
- Supporting software changes

#### Browsers and HTML
- Basic mode of operation![[Pasted image 20241121131558.png]]
- To make this work, client machines requires a standard language (protocol) for specifying the formatting information 
- The standard language used is HTML (Hyper Text Markup Language)
- ![[Pasted image 20241121131759.png]]
#### Multipurpose Internet Mail Extensions (MIME)
- is an Internet standard
- Extends the format of email to support 
	- Text om character sets other than ASCII
	- Non-text attachments (audio video, images, applications, programs)
	- Message bodies with multiple parts
	- Header information in non-ASCII character sets
	- image types
	- location of the picture

#### HTML: Links
- When a client's user clicks on the hypertext link text/image, the browser arranges for the specified file to be requested from the server, interpreted and displayed.
![[Pasted image 20241121132414.png]]


#### Uniform Resource Locators (URLs)
- Each page on the web is specified by a unique URL
- Allows user of a browser to find it and allows it to be linked to from other pages
- Ex. https://www.it.murdoch.edu.au/~psd/addr.html
- Comes in three parts:
	- a protocol (http/https)
	- a name of the host server (www.it.murdoch.edu.au)
	- the file specification (~psd/addr.html)
#### Interactivity
- There are several forms on a HTML page. If it allows sending of information, it would need to include:
	- a Method for communication
	- a destination URL(does not have to be on the host server)
	- a submit button
	- Example:![[Pasted image 20241121132932.png]]
##### HTTP Method
- *Get Method* - is only for getting web pages from a server but can be used in a tricky way to pass information to a program on a server
- *Post Method* - is a more common method. It's designed for adding info to a web page 


##### Server-side Programming and CGI (Common Gateway Interface)
- Common set up for receiving information is to use the Common Gateway Interface provided on all servers
	- Server gets request to apply a method  to a page in a directory called "cgi-bin", it interprets the file name as an executable program (or script) and starts up.
	- The body of the message is passed to the running program as its standard input
	- Program can do whatever it wants with the input (e.g. , interact with a local database)

##### Client-side programming
- Sending all data back to the server for all processing is not efficient therefore client-side programming exist.
- Gives the browser the ability to run programs and allowing the server to send programs along with HTML page.

##### Scripting Languages
- Interpreted client-side programming languages with source being sent as part of an HTML page.
- The interpreter runs the code as it displays the HTML page.
- The source is quick to get from the server and is quick to load.
- Scripting languages are quite simple to learn and understand.
- If you need to produce a web-based client-server system then it is a good idea to consider using a scripting language for the client side.

###### JavaScript
- can be used to validate form on the client's browser before it is sent to the server.
- Events happen to the objects on the page as the user interacts with it.
- JavaScript event handlers allow script to be executed in response to an event. Event Handlers include:
	- onClick - in response to a click on a button
	- onSubmit - in response to clicking on the submit button on a form
	- onMouseOver - in response to the cursor being over an object
	- onChange in response to the text being changed in a text area.
###### Functions
![[Pasted image 20241121151846.png]]
- to define a function we give it a name, formal parameters within script tags in the head of the HTML page
- to call a function we simple mention the function name with arguments.
- Functions can return values.


##### Batch validation
- Form is checked only when the user presses the submit button
- Example: ![[Pasted image 20241121152014.png]]
##### Real-time validation
- Form is checked real time
- Example: ![[Pasted image 20241121152109.png]]