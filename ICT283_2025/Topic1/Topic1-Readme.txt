Please go through the unit guide particularly the requirements for passing.

As a quick start to programming in C++, view Bucky's C++ videos:
https://www.youtube.com/watch?v=tvC1WCdV1XU&list=PLAE85DE8440AA6B83

When going through the video tutorial, do the programming that is shown in the tutorial - type in, build and run the code yourself.

Step 0: (revision of prerequisite material) Complete the revision exercise 1 in Topic01/LabExcTopic01.doc

Step 1: 
Read Lec-01.ppt in Topic01/Content/slides first.
You must go through the readings listed in this PowerPoint  Lec-01.ppt as it informs the approach taken when doing anything in the unit, or in any software development task in later units or when you have graduated.

For Topic 1, go through tutorials 1 to 7 of Bucky's tutorial. Download codeblocks, install it and follow the tutorials instead of just watching the video.

Step 2:
Read the textbook chapters -
Chapters 1, 2, 3 and chapters on Classes and Data Abstraction, and, Inheritance and Composition. Most concepts in the early chapters are revision of prerequisite units but using the C++ language. Chapter 3 is a little different.

Step 3:
Complete Exercises 1 to 7 from LabExcTopic01 in the Practical Folder.
Complete the exercises in the order listed. Be mindful of the advice given in the lab document.

Some of the questions that you need to answer are available from the Library’s My Unit Readings for this unit. (https://murdoch.rl.talis.com/search.html?q=ict283) . View this year’s version of the unit and look for “C++ programming: program design including data structures. Pages 106-107, 110-113, 160-165, 224-229, 296-299, 650-655, 1513-1519, 1524-1529”. *Your textbook page numbers and exercise numbers would be different.*

Step 4:
Complete the readings for Topic 1 from "Essential Reading List by Topics"

When viewing the slides, see the folder "slide examples". Slides and slide examples are found in the Content folder.

=============================================================

For drawing UML, use staruml. The version in the folder "software" is sufficient for this unit. 

Doxygen (along with graphviz) is used for code documentation. It is similar to javadocs but more powerful. Doxygen comments are placed in .h files.

Doxygen is also used to extract code structure from large codebases.

You can also install doxygen on your machine. Install graphviz first before installing doxygen.

External documentation in HTML format using Doxygen must be provided for your assignment and project. Some of the assessed labs require doxygen comments.

Use Doxywizard once you have installed it or have access to it. The wizard provides context sensitive help using the right mouse button.

Make sure that all of the following are enabled for the dot program 
(see dot tab in Doxygen’s expert mode): Class_Diagrams, Class_Graph, 
Collaboration_Graph, Group_Graphs, Template_Relations, Include_Graph, 
Included_by_Graph, Call_Graph, Caller_Graph, Graphical_Hierarchy, 
Directory_Graph. Dot_Image_Format is png. You can select additional 
ones if you like. Experiment to find out. There are 2 pdf files in the folder Practical/DoxyExample that show what you have to do pictorially. There pdf files are numbered 1 and 2. Do 1, followed by 2.

On the Source Browser tab, tick everything except Use_Htags. Make sure
that the HTML output has graphical relations displayed. Do not select
Latex, RTF or Man output in their respective tabs.

You will find that the doxygen tool not only helps with documenting 
the code but also helps you to find errors in your design or 
implementation.

After you have learned how to use the doxygen tool, learn how to 
comment your source code using doxygen style comments. Explanation 
with examples are provided doxygen manual. A version of this manual 
is available doxygen at the unit site. You can read all of it or 
start at the chapter on "Documenting the code".

starumldemo2C++.zip contains an example mentioned in the lecture to demonstrate how to use the tool StarUML. The tool can generate C++ code from the design and you might want to try it out. You are advised not to rely on it for being totally correct. If you make changes to the source code and you recreate the source again from the UML diagram, the changes you made will be lost as the files get over written.

In the folder software, StarUML.pdf is a quick introduction on how to use StarUML. You need to explore StarUML to find out how it works. We are concerned with the Design Model and StarUML can do a lot more but is not needed for our purposes. In the Model Explorer window you will see Design Model. Open this up and as you build your classes, examine what happens there.

Lec-03-CD-V02.zip contains the source files from the lecture notes.

Lec-03-CD-UML-V01.uml is the StarUML design for the source files.
The source files given is for only part of the design. Examine the design. Can you find some issues with it.
