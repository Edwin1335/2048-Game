#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
#include <list>
#include <time.h>
#include <vector>
/*
	Edwin Campuzano 
	1342920

	This program will simulate the game 2048. Where we are given a matrix with values and we must find the fastest way to 
	combine all the numbers using the vertical and horizontal shifts.
*/

class Game
{
private:

	/****************************************************************************************************************
		The class decleration a struct "Node". 	The struct Node is a tile on a grid with a number corresponding to 
		that specific location and a hasMerged boolean fucntion to be checked after each movements to prevent double 
		mergin after every iteration.
	*****************************************************************************************************************/
	struct Node
	{
		bool hasMerged = false;
		int number = 0;
	};

	/***************************************************************************************************************
	    Attributes needed for the "Game" class 
		  - Node** matrix will be initialized to anull pointer. The double pointyer will be used to dynamically 
			creat a grid based on the information given to use by the user. 
	      - The matrixSize integer varaible will 
			be used to store the size of the matrix and at the momment it is intiallized to the number 0. The sixe of 
			the matrix will never be less than 4 or grater than 10.
		  - The hasShifted fucntion will check wether the grid has shifted at least once during a move up/down
		    left/right movement. This important because we dont want to spawn a new item if the grid did not shift.
	***************************************************************************************************************/
	Node** matrix = nullptr;
	int matrixSize = 0;
	bool hasShifted = true;
	std::ifstream input;

	/*************************************************************************************************************
		The final check for completion will be used in each iteration of a while loop to check wether
		the user has completed the game. completing the game tipically means you have reached to the highest
		number possible(2048). The second thing the fucntion must check for is, if there are no more posssible 
		movements for the player to make, then the game must quit and display a game over message.
	**************************************************************************************************************/
	bool checkCompletion();

	/*************************************************************************************************************
	    The move up funtion will be called when the user presses the 'w' key and will shift all of the tiles 
		towards the top of the grid. The funciton will iterate from the second row to the last row as well as 
		iterate from the first column to the last column. When iteration from left ot right it will check the the 
		number that is on top. If the number is the same number as itself, not including 0, merge and set that
		indexe's boealen funtion to "has Merged". The has merged boolean variable will prevent another number from
		meging to that. If the top number is zero, move that number to the top until there are no more zeros.
	**************************************************************************************************************/
	void moveUp();

	/*************************************************************************************************************
	    The move down fuction is similar to the move up funciton, except all the tiles will move towards the 
		bottom. the loop will check all of the tiles except for the last row(every tile must check for its bottom
		neightbor, so we cant chekc the bottom's cottom neighbor). The iteration will loop from the left side of 
		grid to the right side of the grid starting from the second to last column. If the number is the same number 
		as itself, not including 0, merge and set that indexe's boealen funtion to "has Merged". The has merged 
		boolean variable will prevent another number from meging to that. If the bottom number is zero, move that 
		current number to the bottom until there are no more zeros.
	**************************************************************************************************************/
	void moveDown();
	
	/*************************************************************************************************************
	    The move left function is somewhat different from the other previous move funtions becasue in this case, 
		we are not looping through each column , but we are looping through each row. Since our move left function 
		shift all of our tiles to the left we will need to check all fo the tiles to the left of the current 
		Node that we are in, therefore we will loop from top to bottom starting from the second columb. If the
		number is the same number as itself, not including 0, merge and set that indexe's boealen funtion to 
		"has Merged". The has merged boolean variable will prevent another number from merging to that. 
		If the left number is zero, move that current number to the left until there are no more zeros.
	**************************************************************************************************************/
	void moveLeft();

	/*************************************************************************************************************
	    Last but no least, the move right funtion will shift all of our nodes to the right. We will not shift the
		ones that have the number 0 in them. Since our "Move Right" function will shift all of the nodes to the 
		right we need to iterate all the nodes in the columb from top to bottom and check their right hand 
		neighbor to see what number thay have. We will iterate all the volumbs except for the fr right one. We 
		dont check for that one becasue it is already in the far right. If the number is the same number 
		as itself, not including 0, merge and set that indexe's boealen funtion to "has Merged". The has merged 
		boolean variable will prevent another number from merging to that. If the right number is zero, move that 
		current number to the right until there are no more zeros.  
	**************************************************************************************************************/
	void moveRight();

	/*************************************************************************************************************
	    A simple print function to print the matrix but with alittle more style. The numbers will have borders 
		and appropriate spaces to accomodate the user.
	**************************************************************************************************************/
	void printMatrix();

	/**************************************************************************************************************
		When shifting vertical or horizontally we cannot have more than one merge of the same number.
		We must account for that by having a boolean function that checks to see if the index of that number 
		has already merged or not. This function print out an outline of the boolean vaules for each index.
		Wll not be used in the simualtion, only there for debugging.
	**************************************************************************************************************/
	void printMerged();
	
	/**************************************************************************************************************
	    After the user has moved/shifted the nodes to the desire direction, during the shift, the nodes that have
		merged will have its boolean value changed to true. Since we are going to move/shift the node more than 
		once we need to reset all the boolean functions back to false.
	***************************************************************************************************************/
	void resetBool();
	
	/***************************************************************************************************************
	    The populate the Matrix funtion will be called right after we find(or are given) the matrix size. It will
		loop through all the indexes in the matrix and populate them with the number 0, as in empty. Since the 
		original game begins with three different tiles at random locations that is what the next step in our 
		function will do. Find three random locations in the grid and randomly populate them wiht a number 2 or 4.
	****************************************************************************************************************/
	void populateMatrix();
	
	/**************************************************************************************************************	
		The Spawn New Tile function will spawin a new tile in a random location. This function will
		be called after every new move the user makes. Only requirments is that there must be a location in the 
		grid to spawn a new number.The number spawn can only be the number 2 or 4. 
	***************************************************************************************************************/
	void spawinInNewTile();

public:
	/*************************************************************************************************************
	    The given constructor is a overlaoded constructor that will dynamically create a grid based on the size
		passed on by the parameter. 
	**************************************************************************************************************/
	Game(int);

	/*************************************************************************************************************
	    An overloaded constructor trhat will take in the name of a file that the user will want to use. The file 
		will need to begin with the size of the matrix and continue by drwing its own matrix on the text file. 
		This will be used mailny for me to test different scenerios to make the game as error free as possible.
	 *************************************************************************************************************/
	Game(std::string);
	/*************************************************************************************************************
	    A simple default constructor that will intialize the defualt size of the matrix to 4. Then it will 
		create the grid based on this size and populated by calling the "populateMatrix()" function.
	**************************************************************************************************************/
	Game();

	/*************************************************************************************************************
	    Deconstructor to delete all the memory space that was craeted in this program, Not important in this 
		scenerio, but its good practice.
	**************************************************************************************************************/
	~Game();

	/*************************************************************************************************************
	    The only callable funtion in the main that will assemble the entire game and simulate the game by calling
		all the appropriate fucntions.
	**************************************************************************************************************/
	void runSimulation();
};

Game::Game()
{
	matrixSize = 4;
	matrix = new Node* [matrixSize];
	for (int i = 0; i < matrixSize; ++i)
		matrix[i] = new Node[matrixSize];

	populateMatrix();
}

Game::Game(int SIZE)
{
	bool correctInput = false;
	// Begin to get the size of the array based on user input.
	while (!correctInput)
	{
		// Make sure is between 4 and 10
		if (SIZE < 3 || SIZE > 11)
		{
			std::cout << "Please enter a number between 4 and 10" << std::endl;
		}
		else
		{
			correctInput = true;
		}
	}

	// Create the array based on the user's information.
	matrixSize = SIZE;
	matrix = new Node* [matrixSize];
	for (int i = 0; i < matrixSize; ++i)
		matrix[i] = new Node[matrixSize];

	populateMatrix();
}

Game::Game(std::string fileName)
{
	input.open(fileName);

	// Begin to get the size of the array based on the what si in the file.
	if (input >> matrixSize)
	{
		// Dynamically create the two dimensional matrix
		matrix = new Node* [matrixSize];
		for (int i = 0; i < matrixSize; ++i)
			matrix[i] = new Node[matrixSize];

		// Begin to populate the matrix 
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
				input >> matrix[i][j].number;
		}
	}
	else
		std::cout << "ERROR: File is empty." << std::endl;
}

void Game::populateMatrix()
{
	// Intialize all the index to 0, siginfying they are empty.
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			matrix[i][j].number = 0;
		}
	}

	/********************************************************************************************
		We must populate the matrix with at least three numbers when the game begins.
		There is a 90 percent chance that the number that will be populated wiht is a 2 and an 10 
		percent chance its will be a 4.
	*********************************************************************************************/
	srand(time(NULL));
	int locationIndex1ver;
	int locationIndex1hor;
	int locationIndex2Ver;
	int locationIndex2hor;
	int locationIndex3Ver;
	int locationIndex3Hor;

	// First two location can be enywhere in the matrix.
	locationIndex1ver = rand() % matrixSize;
	locationIndex1hor = rand() % matrixSize;

/*----------------Finding the Fist inde location for the first number --------------------------*/
	// Print ot whre the locations were created
	//std::cout << "Fist index picked: " << locationIndex1ver << std::endl;
	//std::cout << "Second index paickede is " << locationIndex1hor << std::endl;



/*----------------Finding the second index location for the second number-----------------------*/
	// Seconds location for the vertical can also be anywhere as long 
	// the second location for horizontal is no the same as the first location horizontal.
	locationIndex2Ver = rand() % matrixSize;
	//std::cout << "Second location vertical is " << locationIndex2Ver << std::endl;	

	// Loop until both(location 1 and location 2) are not in the same place.
	bool differentLocation = false;
	while(differentLocation == false)
	{
		locationIndex2hor = rand() % matrixSize;
		if(locationIndex1ver != locationIndex2Ver || locationIndex2hor != locationIndex1hor)
		{
			differentLocation = true;
		}
	}
	// Print out the second horizontal location for the second number.
	//std::cout << "Second Location horizaontal is " << locationIndex2hor << std::endl;


/*----------------Finding the thrid index location for the third number------------------------------*/
	// Third index location for the vertical position for the third number.
	locationIndex3Ver = rand() % matrixSize;
	//std::cout << "Third Location vertical " << locationIndex3Ver << std::endl;

	differentLocation = false;
	while(differentLocation == false)
	{
		locationIndex3Hor = rand() % matrixSize;
		if(locationIndex3Hor == locationIndex2hor && locationIndex2Ver == locationIndex3Ver)
		{
			std::cout << "INCORRECT" << std::endl;
			differentLocation = false;
		}
		else if(locationIndex3Hor == locationIndex1hor && locationIndex3Ver == locationIndex1ver)
		{
			std::cout << "INCORRECT" << std::endl;
			differentLocation = false;
		}
		else
		{
			differentLocation = true;
		}
	}
	// Printing the horizotla location for the third number.
	//std::cout << "Third Location for horizontal " << locationIndex3Hor << std::endl;


/*--------------Spawn in number 2 or 4 on given index------------------------------------------------------*/

	/*
		We must now find the probability of a number 2 or a number 4 being added to the matrix 
		at the beggining of the simualtion. There is a 10 percent chance of spawining in a 4
		and a 90 percent chance of spawning in a 2.
	*/
	/*-------------------Number for location one is-----------------------*/
	int randomNumber = rand() % 10;
	//std:: cout << "First Random number generated: " << randomNumber << std::endl;
	if(randomNumber == 9)
		matrix[locationIndex1ver][locationIndex1hor].number = 4;
	else 
		matrix[locationIndex1ver][locationIndex1hor].number = 2;

	/*-------------------Number for location two is-----------------------*/
	randomNumber = rand() % 10;
	//std:: cout << "Second Random number generated: " << randomNumber << std::endl;
		if(randomNumber == 9)
		matrix[locationIndex2Ver][locationIndex2hor].number = 4;
	else 
		matrix[locationIndex2Ver][locationIndex2hor].number = 2;
		

	/*-------------------Number for location three is-----------------------*/
	randomNumber = rand() % 10;
		//std:: cout << "Second Random number generated: " << randomNumber << std::endl;
		if(randomNumber == 9)
		matrix[locationIndex3Ver][locationIndex3Hor].number = 4;
	else 
		matrix[locationIndex3Ver][locationIndex3Hor].number = 2;
	//std:: cout << "Third Random number generated: " << randomNumber << std::endl;

}

void Game::spawinInNewTile()
{
	//Need to spawn in a random location therefore the following function is needed.
	srand(time(NULL));

	// We will need to save the all the available positions on a list or vector.
	std::list<Node*> availableNodes;

	// Count how many available spaces there are
	int counter = 0;

	// We need to check where the available tiles are located.
	for(int i =0; i < matrixSize; i++)
	{
		for(int j =0; j < matrixSize; j++)
		{
			if(matrix[i][j].number == 0)
			{
				availableNodes.push_back(&matrix[i][j]);
				counter++;
			}
		}
	}

	// These print must be the same.
	//std::cout << "Available spaces are: " << counter << std::endl;
	//std::cout << "Size of the list is: " << availableNodes.size() << std::endl;

	// Now we must randomly select an available position to insert a new number.
	int selectedNode = rand() % counter;
	int currentNode = 0;
	//std::cout << "Selected node Location is " << (selectedNode + 1) << std::endl;

	// Random number of 2-(90 % chance) or 4-(10% chance) to be spawned.
	int numbertoReplaceEmpty;
	int percentage = rand() % 10;

	if(percentage == 9)
		numbertoReplaceEmpty = 4;
	else 
		numbertoReplaceEmpty = 2;
	//std::cout << "Number choose to replace: "  << numbertoReplaceEmpty << std::endl;

	// Instantciate an list iterator
	std::list<Node*>::iterator iter;

	// Find the randomly selected node
	for(iter = availableNodes.begin(); iter != availableNodes.end(); iter++)
	{
		if(currentNode == selectedNode)
		{
			(*iter)->number = numbertoReplaceEmpty;
		}
		currentNode++;
	}
}

void Game::printMatrix()
{
	// This loop will print out the first border of the top taken into account 
	// the size of the matrix
	for (int i = 0; i < matrixSize; i++)
	{
		std::cout << "_" << std::setfill('_') << std::setw(8) << "_";
	}
	std::cout << "_" << std::setfill(' ') << std::endl;

	// Print the actual matrix with side borers and correct spaces.
	// Along with a bottom border for each iteration. Account for 4 spaces between because
	// The only number that will be the buggets number(2014) only has 4 numbers in its name.
	for (int i = 0; i < matrixSize; i++)
	{
		// Print an extra line that has no values with borders to make more vertical space
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << "|" << std::setw(4) << " " << std::setw(4) << " ";
		}
		std::cout << "|" << std::setw(4) << " " << std::setw(4) << " " << std::endl;

		// Print the values in the middle or at least with spaces and borders in between.
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << "|" << std::setw(4) << matrix[i][j].number << std::setw(4) << " ";
		}
		std::cout << "|" << std::setw(4) << " " << std::setw(4) << " " << std::endl;

		// Print another line with spaces and borers just like the first loop.
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << "|" << std::setfill('_') << std::setw(4) << "_" << std::setw(4) << "_" << std::setfill(' ');
		}
		std::cout << "|" << std::setw(4) << " " << std::setw(4) << " " << std::endl;
	}

}

void Game::printMerged()
{
	// Loop through all the indexes and print out there hasMerged values.
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[i][j].hasMerged)
				std::cout << "Y" << " ";
			else
				std::cout << "n" << " ";
		}
		std::cout << std::endl;
	}
}

void Game::resetBool()
{
	// Loop through all the indexes and set the boolean "Has merged" to false. 
	// to be reused again for the next move function.
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[i][j].hasMerged)
			{
				matrix[i][j].hasMerged = false;
			}
		}
	}
}

bool Game::checkCompletion()
{
	int counter = 0;

	// Check the grid to see if the number 2048 exist, if so exit the game and print "You Won"
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			/*
				Loop through all the indexes and if the number 
				2048 has been found, print out the victory message and 
				return true - as in is is true that the number appears as one of the tiles.
			*/
			if (matrix[i][j].number == 2048)
			{
				std::cout << "You Won you've reached 2048!!!!!" << std::endl;
				return true;
			}
		}
	}
	
	// If there is a 0, that means there is an available space.
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if(matrix[i][j].number == 0)
			{
				return false;
			}
		}
	}

	// Even thought he name is wrong , has shifted will prevent the program to create a new tile 
	// if all of the tiles are full
	hasShifted = false;
	// Check surrounding tiles as well to see if any can merge.
	for (int i = 0; i < matrixSize-1; i++)
	{
		for (int j = 0; j < matrixSize-1; j++)
		{
			// if the space next to it is real then check to see if its the same number.
			if(matrix[i][j].number == matrix[i][j+1].number || matrix[i][j].number == matrix[i+1][j].number)
			{
				return false;
			}
		}
	}

	this->printMatrix();
	std::cout << "GAME OVER!!" << std::endl;
	return true;
}

void Game::moveUp()
{
	/*
		Since we are moving up we need to account only for the values in the bottom of the first row.
		the values will check the top row to see what numerical value they have and make the moves based of of that.
	*/
	for (int i = 1; i < matrixSize; i++)
	{
		/*
			loop throughtall the values that are next to each other.
		*/
		for (int j = 0; j < matrixSize; j++)
		{
			/*
				Make sure that the value exist.
				If the value is equal to 0 or 2048 dont move them. Better time complexity.
			*/
			if (matrix[i][j].number && matrix[i][j].number != 0)
			{
				/*
					If the top values is equal to the bottom value during our move up funtion, then they should merge.
					The noly restriction is that, that index has merged already.
				*/
				if (matrix[i - 1][j].number == matrix[i][j].number && !matrix[i-1][j].hasMerged)
				{
					matrix[i - 1][j].number += matrix[i][j].number;
					matrix[i][j].number = 0;
					matrix[i - 1][j].hasMerged = true;
					hasShifted = true;
				}
				else if (matrix[i - 1][j].number == 0)
				{
					/*
						We must save the row index, no need for the column one. We will traverse the value upwards in 
						our move up funtion if the top value is a 0. 
					*/
					int row = i;
					int column = j;
					while ((row - 1) > 0 && matrix[row-1][column].number == 0)
					{
						matrix[row - 1][column].number = matrix[row][column].number;
						matrix[row][column].number = 0;
						row--;
					}
					if (matrix[row - 1][column].number == 0)
					{
						// If the top row is 0. Merge one more time.
						matrix[row - 1][j].number += matrix[row][column].number;
						matrix[row][column].number = 0;
					}
					else if (matrix[row - 1][column].number == matrix[row][column].number && !matrix[row - 1][column].hasMerged)
					{
						// If the top value is the same values, merge and set that index to "has merged".
						matrix[row - 1][j].number += matrix[row][column].number;
						matrix[row][column].number = 0;
						matrix[row -1][column].hasMerged = true;
					}
					hasShifted = true;
				}
			}
		}
	}
	resetBool();
}

void Game::moveDown()
{
	/*
		For looping theough the array, sice we are moing down, we want ot chek the values above the bottmo row.
		Therefore we must loop throught the valuse from botom to top where the bottom index is one less than matrisSize -1;
	*/
	for (int i = matrixSize - 2; i > -1; i--)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			/*
				Make sure that the value exist.
				If the value is equal to 0 or 2048 dont move them. Better time complexity.
			*/
			if (matrix[i][j].number && matrix[i][j].number != 0)
			{
				/*
					If the bottom values is equal to the top value during our move dwon funtion, then they should merge.
					The noly restriction is that, that index has merged already.
				*/
				if (matrix[i + 1][j].number == matrix[i][j].number && !matrix[i + 1][j].hasMerged)
				{
					matrix[i + 1][j].number += matrix[i][j].number;
					matrix[i][j].number = 0;
					matrix[i + 1][j].hasMerged = true;
					hasShifted = true;

				}
				else if (matrix[i + 1][j].number == 0)
				{
					/*
						We must save the row index, no need for the column one. We will traverse the value dwonwards in
						our move down funtion if the bottom value is a 0.
					*/
					int row = i;
					int column = j;
					while ((row + 1) <= (matrixSize-2) && matrix[row + 1][column].number == 0)
					{
						matrix[row + 1][column].number = matrix[row][column].number;
						matrix[row][column].number = 0;
						row++;
					}
					if (matrix[row + 1][column].number == 0)
					{
						// If the bottom row is 0. Merge one more time.
						matrix[row + 1][j].number += matrix[row][column].number;
						matrix[row][column].number = 0;
					}
					else if (matrix[row + 1][column].number == matrix[row][column].number && !matrix[row + 1][column].hasMerged)
					{
						// If the bottom value is the same values, merge and set that index to "has merged".
						matrix[row + 1][j].number += matrix[row][column].number;
						matrix[row][column].number = 0;
						matrix[row + 1][column].hasMerged = true;
					}
					hasShifted = true;
				}
			}
		}
	}
	this->resetBool();
}

void Game::moveLeft()
{
	/*
		Loop through the entire row and manipulaate the funtions to the left of the columns. Wwe must check what value is 
		to the left of the index that we are pointing at to mainupate the data accordingly. Since we are checking the left value
		we loop from the second columb and beyond, that is why we have "J", the columb row to 1.
	*/
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 1; j < matrixSize; j++)
		{				
			/*
				Make sure that the value exist.
				If the value is equal to 0 or 2048 dont move them. Better time complexity.
			*/
			if (matrix[i][j].number && matrix[i][j].number != 0)
			{
				if (matrix[i][j - 1].number == matrix[i][j].number && matrix[i][j-1].hasMerged == false)
				{
					matrix[i][j - 1].number += matrix[i][j].number;
					matrix[i][j].number = 0;
					matrix[i][j - 1].hasMerged = true;
					hasShifted = true;
				}
				else if (matrix[i][j - 1].number == 0)
				{
					/*
						We must save the column index, no need for the row one. We will traverse the value left in
						our move left funtion if the left value is a 0.
					*/
					int column = j;			
					while (column > 1 && matrix[i][column - 1].number == 0)
					{
						matrix[i][column - 1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
						column--;
					}
					if (matrix[i][column-1].number == 0)
					{
						// If or left value is 0, move one more time and update the previous value
						matrix[i][column-1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
					}
					else if (matrix[i][column-1].number == matrix[i][column].number && !matrix[i][column-1].hasMerged)
					{
						// If our left values is equal to our right valuse merge, update and set that index
						// to "has Merged".
						matrix[i][column-1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
						matrix[i][column-1].hasMerged = true;
					}
					hasShifted = true;
				}
			}
		}
	}
	this->resetBool();
}

void Game::moveRight()
{
	/*
		Loop through the entire row and manipulaate the funtions to the left of the columns. Wwe must check what value is
		to the left of the index that we are pointing at to mainupate the data accordingly. Since we are checking the left value
		we loop from the second columb and beyond, that is why we have "J", the columb row to 1.
	*/
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = matrixSize-2; j >= 0; j--)
		{
			/*
				Make sure that the value exist.
				If the value is equal to 0 or 2048 dont move them. Better time complexity.
			*/
			if (matrix[i][j].number  && matrix[i][j].number != 0)
			{
				if (matrix[i][j].number == matrix[i][j+1].number && matrix[i][j + 1].hasMerged == false)
				{
					matrix[i][j + 1].number += matrix[i][j].number;
					matrix[i][j].number = 0;
					matrix[i][j + 1].hasMerged = true;
					hasShifted = true;
				}
				else if (matrix[i][j + 1].number == 0)
				{
					/*
						We must save the column index, no need for the row one. We will traverse the value left in
						our move left funtion if the left value is a 0.
					*/
					int column = j;
					/*
						Check all the numbers to the right of the index.
						If they are zero, shift the number right.
						Important: Does merge to the last row if there is a zero.
					*/
					while (column < matrixSize-2 && matrix[i][column + 1].number == 0)
					{
						matrix[i][column + 1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
						column++;
					}
					if (matrix[i][column+1].number == 0)
					{
						// If or right value is 0, move one more time and update the previous value
						matrix[i][column + 1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
					}
					else if (matrix[i][column + 1].number == matrix[i][column].number && !matrix[i][column+1].hasMerged)
					{
						// If our right values is equal to our left valuse merge, update and set that index
						// to "has Merged".
						matrix[i][column+1].number += matrix[i][column].number;
						matrix[i][column].number = 0;
						matrix[i][column+1].hasMerged = true;
					}
					hasShifted = true;
				}
			}
		}
	}
	this->resetBool();
}

void Game::runSimulation()
{

    std::cout << "___________________________" << std::endl;
    std::cout << "|                         |" << std::endl;
    std::cout << "|    Welcome to 2048 !    |" << std::endl;
    std::cout << "|                         |" << std::endl;
    std::cout << "|_________________________|" << std::endl;
    // Control is a command that will be used to constrol the move movements.
	char control = '-';
	
	// Run until you have merged to 2048 game.
	while (!checkCompletion())
	{
		// Make sure that during the previous move the tiles shifted
		if(hasShifted == true)
		{
			this->spawinInNewTile();
		}

		// Print the matrix 
		printMatrix();

		// Reset the boolean
		hasShifted = false;

		// Ask user for direction
		std::cout << "Enter: " << std::endl;
		std::cin >> control;
		if (control == 'w' || control == 'W')
			moveUp();
		else if (control == 'd' || control == 'D')
			moveRight();
		else if (control == 's' || control == 'S')
			moveDown();
		else if (control == 'a' || control == 'A')
			moveLeft();
		system("CLS"); //Used in Visual Studio
	}
}

Game::~Game()
{
	delete matrix;
}