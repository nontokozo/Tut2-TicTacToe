
#include "TicTacToe.h"
#include <iostream>
#include <cstdlib> // we need this header since we using srand to generate random numbers
#include <ctime>
#include <stdexcept>// for invalid_argument exception class
using namespace std;



TicTacToe  ::TicTacToe(void)
{
	//initializing the board array
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			board[i][j] = ' ';
		}// end inner for
	}// end outer for

	// initializing player1 array
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			player1[i][j] = -1;
		}// end inner for 
	}// end outer for


	// initializing player2 array
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			player2[i][j] = -1;
		}// end inner for 
	}// end outer for

	counterA = 0; //for player1 moves
	counterB = 0; //for player2 moves
	counterC = 0; //checking conditions 
	counterD = 0;
	counterE = 0;
	counterF = 0;
	player = 0;


}// end constructor

//function to start the game
void TicTacToe::start()
{
	srand(time(NULL));
	player = rand() % 2 + 1; // generate random numbers from 1 to 2
	display();// display any empty board
} // end function start game

void TicTacToe::move()
{
	int x, y;

	while (game = true)

	{
		cout << "player:" << player << "Enter x coordinate" << endl; //getting x coordinater from the player
		cin >> x; // store coordinate to x

		cout << "player:" << player << "Enter y coordinate" << endl; //getting y coordinater from the player
		cin >> y; // store coordinate to y

		check_store(x, y); // calling a function to check and store if the coordinates are within the range
		display();
	}

} // end function game

// checking whether the coordinate are within the range and store them to the appropriate array

void TicTacToe::check_store(int x, int y)
{
	if (0 <= x <= 2 && 0 <= y <= 2)
	{
		switch (player)

		{

		case 1: board[x][y] = 'x'; // placing character to the board array

			player1[0][counterA] = x;
			player1[1][counterA] = y;
			decide(player1);// calling a decide function to check whether the player won or not
			counterA++;
			player = 2; // turn for player2
			isfull();
			break;

		case 2: board[x][y] = 'o';// placing character to the board array

			player2[0][counterB] = x;
			player2[1][counterB] = y;
			decide(player2);// calling a decide function to check whether the player won or not
			counterB++;
			player = 1; // turn for player1
			isfull();
			break;

		}// end switch statement


	} // end if

	else
	{
		throw invalid_argument("coordinates out of range"); //invalid coordinate2
	}
}// end check and store function


// win function
void TicTacToe::won()
{
	display();// calling function display
	cout << "player" << player << "won!!!" << endl << "GAMER OVER" << endl;
	game = false;

}//end win function

// display function
void TicTacToe::display()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <3; j++)
		{
			cout << board[i][j] << "|"; // printing the board array
		}// end inner for

		cout << endl;
	}//end outer for loop

} // end display function

// decide function, tells you when the game is over and which player won the game

void TicTacToe::decide(int myarray[2][5])

{
	const int lefd[2][3] = { { 0, 1, 2 }, { 2, 1, 0 } };

	// checking for right diagonal

	for (int i = 0; i <= 4; i++)
	{
		if (myarray[0][i] >= 0 && myarray[1][i] >= 0)
			if ((myarray[0][i] == myarray[1][i]))
			{
				counterC++;
			}//end if
	}// end for loop

	if (counterC >= 3) // counter has to be 3 for the player to win the game
	{
		won();// calling win function
		return;
	} // end if 


	counterC = 0; // clear the counter
	// checking for rows(x coordinates)

	for (int i = 0; i < 4; i++)
	{
		if (myarray[0][i] >= 0 && myarray[1][i + 1] >= 0)
			if ((myarray[0][i] == myarray[1][i + 1]))
			{
				counterD++;
			}//end if
	}// end for loop

	if (counterD == 2) // counter has to be 3 for the player to win the game
	{
		won();// calling win function
		return;
	} // end if 



	counterD = 0; //clearing the counter if the condition is not met

	//checking for column(y coordinate)
	for (int i = 0; i < 4; i++)
	{
		if (myarray[1][i] >= 0 && myarray[1][i + 1] >= 0)

			if ((myarray[1][i] == myarray[1][i + 1]))
			{
				counterE++;
			}//end if
	}// end for loop

	if (counterE == 2) // counter has to be 3 for the player to win the game
	{
		won();// calling win function
		return;
	} // end if 


	counterE = 0;
	//checking for the left diagonal

	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 2; j++)
		{

			//if(myarray[0][i]>=0 && myarray[1][i]>=0)
			if (myarray[0][i] == lefd[0][j] && myarray[1][i] == lefd[1][j])

			{
				counterF++;
			}// end if
		}// end inner for loop
	}// end outer for
	if (counterF == 3)
	{
		won(); //calling win function
		return;
	}
	counterF = 0;
}// end function decide

// check if the array is full

void TicTacToe::isfull()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
				counterG++;
		}// end inner for
	}// end outer for

	cout << counterG << endl;
	if (counterG == 9)
	{
		cout << "Game over !! player1 and player2 are tied" << endl << endl;
		game = false;
		return;
	}
}
