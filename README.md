# Chess Game

## How do I compile the game ?
__It is simple !__ 
- You just have to type the following command in a console located in the _Chess Game_ folder. 
```
make all
``` 
- It will create a binary file named "echecs", that you can launch with 
```
./echecs
```

## How can I access to the documentation of the project ?
__It is also very simple !__
- The "make all" command will also create a documentation in the `html` format, that you can launch on your default browser by typing the following command or by opening [./doc/html/index.html](./doc/html/index.html) with a web browser.
```
make open_doc
```

## What can this game do, and what can't it do ?
- According to [this page](https://moodle3.unistra.fr/pluginfile.php/226388/mod_resource/content/9/td-echecs.html#sec-2-1) ( _© Stéphane Génaud_ ), this project __almost__ reaches the __level 6__ : you can do a __'Castling'__ (see [here](https://en.wikipedia.org/wiki/Castling)) but you cannot do a __'en passant'__ (see [here](https://en.wikipedia.org/wiki/En_passant)).
- You can do any move you like : the program shows you a Chessboard with coordinates. To move a piece, you just have to write 'e2e4' : move the piece in e2 to the case e4. The pogram checks if the move that you try to do is legal or not.
- The 'Castling' ( _Big_ or _Small Roque_ ), you just have to type respectively 'O-O-O' or 'O-O'. The program checks the conditions by itself.

## How did I created this program ?
- I started by creating all the classes referenced in [this page](https://moodle3.unistra.fr/pluginfile.php/226388/mod_resource/content/9/td-echecs.html#sec-2-1) ( _© Stéphane Génaud_ ).
- As I did this, I wrote some usefull funtions and macros that I used later to make the code clearer.
- I created the constructor of the Chessboard class, then focused on the graphic interface. I thought that starting here would be a first step to appropriate myself the project, and I was right.
- Next, I wrote all the Pieces and the methods that come with them.
- I decided to get rid of the Square class as I did not use it in any of my methods. Afterwards, I could have saved it to access pieces to facilitate the writing of methods like to know if there is a check to the King or make a Roque.
- I admit that my code is not the cleanest but it seems to me that I can easily continue it, by implementing the Checkmate detection or the 'en passant' move.

--- 

Thank you for reading. I hope that you will enjoy the game, and that you will easily understand my code ! 