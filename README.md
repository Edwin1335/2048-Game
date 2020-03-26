# 2048_Game
This is a fully functioning 2048 game with no graphics (at least for the moment).
Created Februrary 01, 2020.
By: Edwin Campuzano.

Notes:
There is only one function that can be called, the runSimulation() function.
There are three different constructors:

  The default constructor will intialize the grid to a 4 by 4.
  
  Overloaded constructor with integer parameter: Enter the size of the grid you would like to play in.
    can only be between 4 and 10. Any bigger seems like cheating. may not be very visually attractive.
    
  Overloaded constuctor with string parameter: Enter the name of the file to intialize the grid. File must have 
    the size of the grid as well as an overall sketch of the positions of the tiles. 
    Example: 5
             0 0 0 0 0
             4 4 0 0 0
             2 2 2 2 2
             0 8 0 0 0
             0 0 0 0 0
  
  Finally we can call the runSimulation() funtion to begin playing the game.
