#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();
	void start();
	void move();
	void check_store(int, int);
	void won();
	void display();
	void decide(int myarray);


private:


};



#endif
