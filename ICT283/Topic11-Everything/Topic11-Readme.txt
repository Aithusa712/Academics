Complete all work from previous topics.


Step 1:
Go through any of Bucky's C++ tutorials that you didn't complete
https://www.youtube.com/playlist?list=PLAE85DE8440AA6B83

Use Codeblocks and do the tutorials instead of just watching the video.

In a number of cases, you are being asked to view and do the tutorial 
more than once. If you have already understood, you can skip the 
particular video tutorial.


Step 2:
Go through the Content PowerPoint files. 

Pay attention to how Hashing works. Computer Science majors need to know a bunch of data structures and processing, including Hash functions. Studies in IT Security tend to look at certain aspects of Computer Science. Hashing is one of those aspects, and IT security studies do go into a lot of depth because of applications in Cryptography. 

To extend your knowledge:
A basic primer is 
https://www.tutorialspoint.com/cryptography/cryptography_hash_functions.htm. 

The best starting reference for all of this is the reference book for this unit - Introduction to Algorithms, chapter on Hash Tables, with subsection on Hash Functions.

Graphs are a very important data structure as they are able to model a lot of activities that goes on in the real world. You will need a decent understanding of how graphs work.

Go through the textbook chapter on Graphs.


Step 3:
In the assignment, you would normally be asked to provide a rational for your data structures. In this video (from an MIT unit on Introduction to Algorithms) for BST justification one particular example is used. 
https://www.youtube.com/watch?v=9Jry5-82I68&index=5&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb. 

In the video, the tree algorithm is modified to cater for a new requirement. This approach is not good – see Open Closed Principle. Think of a better solution. Other than that, the video explains the BST and its use very **well**.

This is the last topic and the practical component involves finishing of all past labs, particularly lab 10.

BSTs have an invariant property that the left child's data is less than the parent's data and right child's data is greater than the parent's data. When inserting into (also deleting from) the tree, you may consider having a temporary debugging routine that is called after each insert. This debugging routine just checks the invariant property. Once you are sure that the insert routine works, you take the debugging routine out. This a good approach to use whenever you are developing data structures that have invariant properties. So after each data structure insert/update, invariance is checked during the development stage. It can save you a lot of problems later on.

We should be able to build and run your assignment in the form that you have submitted without tinkering with it.

Make sure you keep to the specifications. Your program gets tested using our own test data. If your program does not work with our test data, your program would be deemed as not working. So test carefully and do not hard code any unnecessary assumptions. If you are unsure, check the specs and the QandA file. If you question is not addressed, ask during the workshop/clinic.

**
The lab is assessed in person during the normal lab time during the last week of semester/trimester. 

As before, lab assessment is done in person for internal and external students. You will need a test plan with the expected results that have been calculated manually.
**

If you have not understood something, make note of it to discuss with your tutor.