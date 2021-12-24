#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>  // for sleep() and gotoxy().
#include <conio.h>  // for _getch.(Arrow key inputs)

#include"players.h"

using namespace std;

class CheckersGame
{
public:
	string board[8][8];
	string symbolTurn;

	//PlayerClass player1, player2;


	PlayerClass* player1 = new PlayerClass;
	PlayerClass* player2 = new PlayerClass;

	//Player2Class player2;

	CheckersGame();            // Constructor

	//------------------------------------------General Functions---------------------------------------------------------

	void placementOfPieces(string board[][8], string p1char, string p2char, int rows = 8);

	void game_menu();   // main menu function. simple cout statements.


	void printBoard();

	void gameRun(CheckersGame& gameObj);

	void credits();  // who made the game function.

	void file_read();  // file read function.


	void rules();  // Rules function.

	void gotoxy(int x, int y);  // This function moves the cursor according to the values given.


	void sideInfo(string p1Name, string p2Name, string p1Chr, string  p2chr, int p1Scores = 0, int p2Scores = 0);   // simple cout function with gotoxy function.


	void WinScreen(CheckersGame obj);

	void p1Turn(CheckersGame &gameObj, int row, int col, bool &terminator);

	void p2Turn(CheckersGame &gameObj, int row, int col, bool &terminator);

	void right();

	~CheckersGame();

};