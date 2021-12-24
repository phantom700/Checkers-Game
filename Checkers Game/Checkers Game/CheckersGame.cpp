#include"CheckersGame.h"
#include"movements.h"

CheckersGame::CheckersGame()
{
	symbolTurn = " ";

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = " ";
		}
	}

}

CheckersGame::~CheckersGame()
{
	delete player1;
	delete player2;
}


void CheckersGame::placementOfPieces(string board[][8], string p1char, string p2char, int rows/* = 8*/)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// p1 placement
			if ((i == 0 && j == 1) || (i == 0 && j == 3) || (i == 0 && j == 5) || (i == 0 && j == 7) ||
				(i == 1 && j == 0) || (i == 1 && j == 2) || (i == 1 && j == 4) || (i == 1 && j == 6) ||
				(i == 2 && j == 1) || (i == 2 && j == 3) || (i == 2 && j == 5) || (i == 2 && j == 7))
			{
				board[i][j] = p1char;
			}
			// p2 placement
			if ((i == 5 && j == 0) || (i == 5 && j == 2) || (i == 5 && j == 4) || (i == 5 && j == 6) ||
				(i == 6 && j == 1) || (i == 6 && j == 3) || (i == 6 && j == 5) || (i == 6 && j == 7) ||
				(i == 7 && j == 0) || (i == 7 && j == 2) || (i == 7 && j == 4) || (i == 7 && j == 6))
			{
				board[i][j] = p2char;
			}
		}
	}
}


void CheckersGame::game_menu()   // main menu function. simple cout statements.
{
	cout << "------------------ " << endl;
	cout << "  Checkers Lite" << endl;
	cout << "------------------" << endl;
	cout << endl;
	cout << "MENU:" << endl;
	cout << "1.  Start Game." << endl;
	cout << "2.  Credits." << endl;
	cout << "3.  Rules." << endl;
	cout << "4.  Score." << endl;
	cout << "5.  Exit." << endl;
	cout << endl;
	cout << "* Select Your Choice: ";
}


void CheckersGame::printBoard()
{
	cout << " Row" << endl;
	cout << endl;

	for (int i = 0; i <= 7; i++)
	{
		cout << "  " << i << "     ";

		for (int j = 0; j <= 7; j++)
		{
			cout << " |  " << board[i][j] << " ";
		}
		cout << endl;
		cout << "         _______________________________________________" << endl;
		cout << endl;
	}

	cout << endl;
	cout << "Column" << "  ";
	for (int k = 0; k <= 7; k++)
	{
		cout << "    " << k << " ";
	}
	cout << endl;
}

void CheckersGame::gameRun(CheckersGame& gameObj)
{
	int row = NULL;
	int col = NULL;

	gameObj.sideInfo(gameObj.player1->nameGetter(), gameObj.player2->nameGetter(), gameObj.player1->pSymbol, gameObj.player2->pSymbol);  // display names with their Scores.
	gameObj.placementOfPieces(gameObj.board, gameObj.player1->pSymbol, gameObj.player2->pSymbol);  // setting the board.

	bool terminator = false;

	while (!terminator)
	{
		//------------------------------- P2 Turn -------------------------------------------
		symbolTurn = gameObj.player1->pSymbol;

		gameObj.sideInfo(gameObj.player1->nameGetter(), gameObj.player2->nameGetter(), gameObj.player1->pSymbol, gameObj.player2->pSymbol, gameObj.player1->pScoreGetter(), gameObj.player2->pScoreGetter());  // display names with their Updated.
		gameObj.printBoard();
		cout << "\n\n";

		cout << " (" << gameObj.player1->pSymbol << ")" << " " << gameObj.player1->nameGetter() << "'s Turn.." << endl << endl;
		cout << "Input Row Index of Piece: ";  cin >> row;
		cout << "Input Col Index of Piece: ";  cin >> col;
		cout << endl;

		gameObj.p1Turn(gameObj, row, col, terminator);

		if (terminator == true)
			continue;


		system("cls");  
		
		// --------------------------------P2 Turn-------------------------------------------

		symbolTurn = gameObj.player2->pSymbol;

		gameObj.sideInfo(gameObj.player1->nameGetter(), gameObj.player2->nameGetter(), gameObj.player1->pSymbol, gameObj.player2->pSymbol, gameObj.player1->pScoreGetter(), gameObj.player2->pScoreGetter());  // display names with their Updated Scores.
		gameObj.printBoard();
		cout << "\n\n";

		cout << " (" << gameObj.player2->pSymbol << ")" << " " << gameObj.player2->nameGetter() << "'s Turn.." << endl << endl;
		cout << "* Input Row Index of Piece: ";  cin >> row;
		cout << "* Input Col Index of Piece: ";  cin >> col;
		cout << endl;

		gameObj.p2Turn(gameObj, row, col, terminator);

		system("cls");
	}
}

void CheckersGame::credits()  // who made the game.
{
	cout << "\t\t\t\t|               --------------              |" << endl;
	cout << "\t\t\t\t|                 CREATED BY                |" << endl;
	cout << "\t\t\t\t|               --------------              |" << endl;
	cout << "\t\t\t\t|     Ahmad Ali\t\t Wajeeha khalid     |" << endl;
	cout << "\t\t\t\t|___________________________________________|" << endl << endl;
	cout << "\t\t\t\t|               ---------------             |" << endl;
	cout << "\t\t\t\t|                 ROLL NUMBERS              |" << endl;
	cout << "\t\t\t\t|               ---------------             |" << endl;
	cout << "\t\t\t\t|        20F-0366\t   20F-1096         |" << endl;
	cout << "\t\t\t\t|___________________________________________|" << endl << endl;
	cout << "\t\t\t\t|    -------------------------------------  |" << endl;
	cout << "\t\t\t\t|     CLASS:      BS Software Engineering   |" << endl;
	cout << "\t\t\t\t|     SECTION:    SE-3A                     |" << endl;
	cout << "\t\t\t\t|    -------------------------------------  |" << endl;
	cout << "\t\t\t\t|___________________________________________|" << endl << endl << endl << endl;
}


void CheckersGame::file_read()  // file read function.
{
	string abc;
	ifstream in("Text.txt");
	if (in.is_open())
	{
		while (getline(in, abc))
		{
			cout << abc << endl;
		}
		in.close();
	}
	else
		cout << "* File is closed" << endl;
}

void CheckersGame::rules()  // Rules function.
{
	cout << "\t\t\t\t\t|-----------|" << endl;
	cout << "\t\t\t\t\t|   RULES   |" << endl;
	cout << "\t\t\t\t\t|-----------|" << endl << endl << endl;
	cout << "1. If a player has lost all his pieces he loses." << endl << endl;
	cout << "2. If a player can't move at all, all his pieces are blocked, he loses." << endl << endl;
	cout << "3. The exact same board state has come up three times without any men\ncaptured in between. The game ends in a draw. This is to avoid situation with\ntwo pieces left just moving around never being able to capture each other." << endl << endl;
	cout << "4. There have been 100 moves (50 for each player) with no piece captured. The game ends in a draw." << endl << endl;
}


void CheckersGame::gotoxy(int x, int y)  // This function moves the cursor according to the values given.
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}


void CheckersGame::sideInfo(string p1Name, string p2Name, string p1Chr, string  p2chr, int p1Scores/* = 0*/, int p2Scores/* = 0*/)   // simple cout function with gotoxy function.
{
	gotoxy(70, 5); cout << "------------------ " << endl;
	gotoxy(70, 6); cout << "  Checkers Lite" << endl;
	gotoxy(70, 7); cout << "------------------" << endl;
	gotoxy(70, 9); cout << "(" << p1Chr << ")" << " " << p1Name << " Points: " << p1Scores << endl;
	gotoxy(70, 10); cout << "(" << p2chr << ")" << " " << p2Name << " Points: " << p2Scores << endl;
	gotoxy(0, 0); // returning back the cursor to its initial position.
}



void CheckersGame::WinScreen(CheckersGame obj)
{
	system("cls");

	if (obj.player1->pPiecesGetter() == 0)
	{
		cout << "\n\n\n*** Congratulations.. " << obj.player2->nameGetter() << " has Won the Game ***" << endl;
		Sleep(7000);
	}
	else if (obj.player2->pPiecesGetter() == 0)
	{
		cout << "\n\n\n*** Congratulations.. " << obj.player1->nameGetter() << " has Won the Game ***" << endl;
		Sleep(7000);
	}
}

void CheckersGame::p1Turn(CheckersGame &gameObj, int row, int col,bool &terminator)
{

	if (gameObj.board[row][col] == gameObj.player1->pKing)    // if it is King.
	{
		cout << "* Where do you want to move Up or Down? (press Up or Down Arrow key): ";
		
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			cout << endl;

			if (ch == 72)                          // up 
			{
				cout << "* Top Left or Top Right?: ";

				int chr = _getch();
				if (chr == 224)
				{
					chr = _getch();
					cout << endl;
					switch (chr)
					{

					case 77:                                     //Right key
						movements::moveTopRight(gameObj.board, row, col, gameObj, terminator);
						break;
					case 75:                                     // left key
						movements::moveTopLeft(gameObj.board, row, col, gameObj, terminator);
						break;

					default:
						cout << "* Error: You Entered the Wrong Key..!" << endl;
						Sleep(3000);
						break;
					}

				}
			}
			else if (ch == 80) // down
			{
				cout << "* Bottom Left or Bottom Right?: ";

				int chr = _getch();
				if (chr == 224)
				{
					chr = _getch();
					switch (chr)
					{
					case 77:                                     //Right key
						movements::moveBottomRight(gameObj.board, row, col, gameObj, terminator);

						break;

					case 75:                                     // left key
						movements::moveBottomLeft(gameObj.board, row, col, gameObj, terminator);
						
						break;

					default:        // innet switch Default Case.
						cout << "* Error: You Entered the Wrong Key..!" << endl;
						Sleep(3000);

						break;
					}
				}

			}
			else
			{
				cout << "* Error: You Entered the Wrong Key..!" << endl;
				Sleep(3000);
			}
		}

	}
	else if(gameObj.board[row][col] != gameObj.player1->pKing)                                      //if other than King
	{

		cout << "* Move Bottom Left or Right? Input Via left or Right Arrow keys: " << endl;
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case 77: // right Key
				movements::moveBottomRight(gameObj.board, row, col, gameObj,terminator);

				break;

			case 75: // left Key
				movements::moveBottomLeft(gameObj.board, row, col, gameObj, terminator);

				break;

			default:         // outer switch Defalut Case.
				cout << "* Error: You Entered the Wrong Key..!" << endl;
				Sleep(3000);

				break;
			}
		}
	}
}

void CheckersGame::p2Turn(CheckersGame &gameObj, int row, int col, bool &terminator)
{

	if (gameObj.board[row][col] == gameObj.player2->pKing)    // if it is King.
	{

		cout << "* Where do you want to move Up or Down? (press Up or Down Arrow key): ";

		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			if (ch == 72)     //Up
			{
				cout << endl;
				cout << "* Top Left or Top Right?: ";
				int chr = _getch();
				if (chr == 224)
				{
					chr = _getch();
					cout << endl;

					if (chr == 77)    // rigth 
					{
						movements::moveTopRight(gameObj.board, row, col, gameObj, terminator);

					}
					else if (chr == 75)   // left
					{
						movements::moveTopLeft(gameObj.board, row, col, gameObj, terminator);

					}
					else
					{
						cout << "* Error: You Entered the Wrong Key..!" << endl;
						Sleep(3000);
					}
				}
			}
			else if (ch == 80)   // down
			{

				cout << "* Bottom Left or Bottom Right?: ";
				int chr = _getch();
				if (chr == 224)
				{
					chr = _getch();
					if (chr == 77)    // right 
					{
						movements::moveBottomRight(gameObj.board, row, col, gameObj, terminator);

					}
					else if (chr == 75)    // left 
					{
						movements::moveBottomLeft(gameObj.board, row, col, gameObj, terminator);

					}
					else
					{
						cout << "* Error: You Entered the Wrong Key..!" << endl;
						Sleep(3000);
					}
				}
			}
			else
			{
				cout << "* Error: You Entered the Wrong Key..!" << endl;
				Sleep(3000);
			}
		}
	}
	else if(gameObj.board[row][col] != gameObj.player2->pKing)
	{
		cout << "* Move Top Left or Right? Input Via left or Right Arrow keys: " << endl;
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case 77: // right Key
				movements::moveTopRight(gameObj.board, row, col, gameObj, terminator);

				break;
			case 75: // left Key
				movements::moveTopLeft(gameObj.board, row, col, gameObj, terminator);

				break;

			default:
				cout << "* Error: You Entered the Wrong Key..!" << endl;
				Sleep(3000);

				break;
			}
		}
		system("cls");
	}

}

void CheckersGame::right()
{





}