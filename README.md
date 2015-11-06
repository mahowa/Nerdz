Assignments 

These are the first few assignments, things are obviously still somewhat vague. As we start to figure more out we’ll update this and the readme section of the github. We are going to base our implementation on something called 40000chips, here’s the link. You should as least read through it. http://doc.qt.io/qt-5/qtwidgets-graphicsview-chip-example.html
You can also find this in the examples section in qt..

For the record a chip in the example is a tile (a single pixel)

If you don’t have the link to the github yet here it is:
https://github.com/mahowa/Nerdz.git

Refer to the attach

Matt H
•	qGraphicsItem grid

Matt W
•	Tile View, figure out how to implement and use it
•	Save / Load function
•	Help with implementation of remaining data structures.
•	Work with Matt to integrate the system together

Anne
•	Make a data structure to display all of the sprite scenes using ‘qGraphicsScene’ and display them on the actual GUI

Charlie
•	Make the .h files for all classes in the UML and fill in the attributes & functions – HIGH PRIORITY
•	Be ready to add to the .h files as needed 

Dan
•	Be able to take a ‘qGraphicsScene’ and display it. (for now build it with random scenes you make yourself, but eventually you’ll be given them… so we need an  add function to be able to add to the list to loop over)
o	To get you started build a class that has a list of scenes and loops over them to display them on a ‘qGraphicsView’
o	Hook up a slider to this so you can change the speed
o	Setting a ‘qGraphicsView’ is as easy as using setScene()

Brandon
•	Work on the toolbar gui, it needs to be able to all the required functions and create signals to connect to.
o	Example the paint color need to send a signal of a color to matt h’s sprite editor part
o	We’ll do the connecting later, we just need it to be able to fire a signal
o	Remember the 40000chips shows a good way to rotate things, move, etc….


![alt tag](https://cloud.githubusercontent.com/assets/10621646/10986702/9c5a3c96-83e9-11e5-88e4-2b83f47a0ff7.png)

![alt tag](https://cloud.githubusercontent.com/assets/10621646/10986708/a62c0178-83e9-11e5-82bd-e6b43c348bfa.jpg)



