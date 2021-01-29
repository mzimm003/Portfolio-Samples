# Portfolio-Samples
These projects aim to demonstrate implementation of coding concepts
learned in class or otherwise.

| Project | Language | Concepts Explored |
|---------|----------|---------|
| [Inheritance v. Polymorphism](#Inheritance-v.-Polymorphism) | C++ | Class Hierarchy |
| [Recursion Example](#Recursion-Example) | C++ | Recursion; Search and Sort Efficiency |
| [STL Example](#STL-Example) | C++ | Relying on Standards |
| [Conway's Game of Life](#Conways-Game-of-Life) | Java | Swing GUI |

### Inheritance v. Polymorphism
This project is taken in two parts, an exploration into inheritance and an exploration
into polymorphism.

#### Inheritance Example
To example the inheritance of a parent class' members, this program provides a 
base class more generally representing a person, the attributes for which all applying
to the derived class, a college undergrad (more specific person). The program allows for
rolodex entry, then returning all entries input in grid form prior to terminating. In the
utilization of the program we are able provide input relevant to any person while also
allowed an opportunity to more specifically deem an individual a student and provide
additional information therefor.

![](./Readme%20Contents/Media/Inheritance%20Example.png?raw=true "Temporary Rolodex Input and Output")

#### Polymorphism Example
Here an abstract base class representative generally of members of the work force 
(job holders), is completed with derived classes representing specific occupations. To
example the many shapes (polymorphisms) a parent class may take in the form of derived
classes, this simple program has an array of base class pointers contain several instances
of specific job classes allowing for efficient processing of the information contained in
each class object within the array. In this case, that processing is simply a return of
salary and occupation description to the console.

![](./Readme%20Contents/Media/Polymorphism%20Example.png?raw=true)

### Recursion Example
This project makes use of recursion to excess. In fact, any repeated step is necessarily
written recursively, simply to explore recursion for recursion's sake. That being so, also
implemented are more resource conscious algorithms like quick sort and binary search to
ensure the stack remains as small as possible in the recursive function calls. The program
itself takes a dictionary provided by a file 'words.txt', asks for a word, and returns all the
combination variations of the user provided word, matched to the dictionary.

For this program I have provided an
[installer](./Readme%20Contents/Installers/Recursion%20Example%20Installer.msi)
which will also include a sample dictionary file.

Below the program is demonstrated with the seven-letter word triangle.

![](./Readme%20Contents/Media/Recursion%20Example.png)

### STL Example
This project makes use of common algorithms and data structures, emphasizing understanding
and utilizing concepts without necessarily developing them anew. The program aims to cover 
part of the responsibility of a compiler, specifically ensuring balanced syntax for certain
character sets including parentheses, brackets, and braces, for example. Upon being provided
a file for measuring, the program will return the contents of the file to the console, followed
by each character pair measured, and, if applicable, the first row found containing an unpaired
character.

For this program I have provided an
[installer](./Readme%20Contents/Installers/STL%20Example%20Installer.msi)
which will also include two sample code files
(one which will compile, and one which will not based on a missing brace).

Below a check has been performed on a 'Hello World' program with a missing end brace.

![](./Readme%20Contents/Media/STL%20Example.png)

### Conway's Game of Life
This project is a demonstration of GUI, specifically utilizing the swing package. In building
the GUI, NetBeans IDE GUI builder provided assistance with basic structure, from which the
remainder of the program was extrapolated. The program itself is a classic and personal favorite
as complex systems can be created from very simple rules. [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
is a 0 player game (the game is initialized, then runs automatically without user input) where
a grid of pixels contains live and dead pixels determined each cycle based on the living pixels
of the previous cycle. The rules are as follows:
1. Any live pixel with two or three live neighbors survives.
2. Any dead pixel with three live neighbors becomes a live pixel.
3. All other live pixels die in the next generation. Similarly, all other dead pixels stay dead.

For this program I have provided an
[installer](./Readme%20Contents/Installers/Conway%27s%20Game%20of%20Life%20Installer.msi) for
your own enjoyment, but my favorite instance of the game is shown below, a spaceship boldly
venturing into a pulsar.

![](./Readme%20Contents/Media/Conway's%20Game%20of%20Life.gif)

