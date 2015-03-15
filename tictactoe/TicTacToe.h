#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();
	void start();
	void move();
	void won();
	void display();
	void decide(int myarray[2][5]);
	void check_store(int, int);
	void isfull();



private:
	int counterA; //for player1 moves
	int counterB; //for player2 moves
	int counterC; //checking conditions 
	int counterD;
	int counterE;
	int counterF;
	int counterG;
	int player;
	bool game;
	char board[3][3]; //board array
	int player1[2][5];// player1 array
	int player2[2][5];// player2 array

};



#endif
