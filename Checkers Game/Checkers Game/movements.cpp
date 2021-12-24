#include"movements.h"

void movements::moveBottomRight(string board[][8], int selectedRow, int selectedCol, CheckersGame & gameObj, bool& terminator)
{
	if (board[selectedRow][selectedCol] == " ")
	{
		cout << "* Error: Empty Space.." << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] != gameObj.symbolTurn && board[selectedRow][selectedCol] != "K" + gameObj.symbolTurn)
	{
		cout << "* Error: Can't move Opponent's Pieces.." << endl;
		Sleep(3000);
	}
	else if ((selectedCol + 1) > 7 || (selectedRow + 1) > 7)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] == board[selectedRow + 1][selectedCol + 1])   // if same piece  // can't jump over.
	{
		cout << "* Error: Can't Jump Over your Own Piece..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow + 1][selectedCol + 1] == " ")  // Dot // Move One Step.
	{
		board[selectedRow + 1][selectedCol + 1] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = " ";
		
		if (selectedRow + 1 == 7)
		{
			board[selectedRow + 1][selectedCol + 1] = "K" + gameObj.symbolTurn;
		}
	}

	else if ((selectedCol + 2) > 7 || (selectedRow + 2) > 7)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	
	else if ((board[selectedRow][selectedCol] == gameObj.player1->pKing || board[selectedRow][selectedCol] == gameObj.player2->pKing) && (board[selectedRow][selectedCol] == "K" + gameObj.symbolTurn) && (board[selectedRow + 2][selectedCol + 2] == " ") && (board[selectedRow + 2][selectedCol + 2] != gameObj.player1->pKing || board[selectedRow + 2][selectedCol + 2] != gameObj.player2->pKing))     //kING mOVEMENT
	{
		board[selectedRow + 2][selectedCol + 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow + 1][selectedCol + 1] = " ";

		if (board[selectedRow][selectedCol] == gameObj.player1->pKing)
		{
			++gameObj.player1->pScores;
			--gameObj.player2->pPieces;
		}
		else if (board[selectedRow][selectedCol] == gameObj.player2->pKing)
		{
			++gameObj.player2->pScores;
			--gameObj.player1->pPieces;
		}

	}
	else if ((board[selectedRow + 2][selectedCol + 2] == " ") && (board[selectedRow + 2][selectedCol + 2] != board[selectedRow][selectedCol])) // opponent piece // Can Jump & Capture.
	{



		board[selectedRow + 2][selectedCol + 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow + 1][selectedCol + 1] = " ";
		++gameObj.player1->pScores;
		--gameObj.player2->pPieces;

		if (selectedRow + 2 == 7)           //Promot to King.
		{
			board[selectedRow + 2][selectedCol + 2] = gameObj.player1->pKing;
		}
	}
	else
	{
		cout << "* Error: Can't Jump there..!" << endl;
		Sleep(3000);
	}


	if (gameObj.player1->pPiecesGetter() == 0 || gameObj.player2->pPiecesGetter() == 0)
	{
		gameObj.WinScreen(gameObj);
		terminator = true;
	}

}

void movements::moveBottomLeft(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator)
{

	if (board[selectedRow][selectedCol] == " ")
	{
		cout << "* Error: Empty Space.." << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] != gameObj.symbolTurn && board[selectedRow][selectedCol] != "K" + gameObj.symbolTurn)
	{
		cout << "* Error: Can't move Opponent's Pieces.." << endl;
		Sleep(3000);
	}
	else if ((selectedRow + 1) > 7 || (selectedCol - 1) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] == board[selectedRow + 1][selectedCol - 1])   // if same piece  // can't jump over.
	{
		cout << "* Error: Can't Jump Over your Own Piece..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow + 1][selectedCol - 1] == " ")  // Dot // One Step.
	{
		board[selectedRow + 1][selectedCol - 1] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = " ";

		if (selectedRow + 1 == 7)
		{
			board[selectedRow + 1][selectedCol - 1] = "K" + gameObj.symbolTurn;
		}

	}
	else if ((selectedRow + 2) > 7 || (selectedCol - 2) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if ((board[selectedRow][selectedCol] == gameObj.player1->pKing || board[selectedRow][selectedCol] == gameObj.player2->pKing) && (board[selectedRow][selectedCol] == "K" + gameObj.symbolTurn) && (board[selectedRow + 2][selectedCol - 2] == " ") && (board[selectedRow + 2][selectedCol - 2] != gameObj.player1->pKing || board[selectedRow + 2][selectedCol - 2] != gameObj.player2->pKing))     //kING mOVEMENT
	{
		board[selectedRow + 2][selectedCol - 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow + 1][selectedCol - 1] = " ";

		if (board[selectedRow][selectedCol] == gameObj.player1->pKing)
		{
			++gameObj.player1->pScores;
			--gameObj.player2->pPieces;
		}
		else if (board[selectedRow][selectedCol] == gameObj.player2->pKing)
		{
			++gameObj.player2->pScores;
			--gameObj.player1->pPieces;
		}
	}
	else if ((board[selectedRow + 2][selectedCol - 2] == " ") && (board[selectedRow + 2][selectedCol - 2] != board[selectedRow][selectedCol])) // opponent piece // Can Jump & Capture.
	{
		board[selectedRow + 2][selectedCol - 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow + 1][selectedCol - 1] = " ";
		++gameObj.player1->pScores;
		--gameObj.player2->pPieces;

		if (selectedRow + 2 == 7)           //Promot to King.
		{
			board[selectedRow + 2][selectedCol - 2] = gameObj.player1->pKing;
		}
		
	}
	else
	{
		cout << "* Error: Can't Jump there..!" << endl;
		Sleep(3000);
	}


	if (gameObj.player1->pPiecesGetter() == 0 || gameObj.player2->pPiecesGetter() == 0)
	{
		gameObj.WinScreen(gameObj);
		terminator = true;
	}

}

void movements::moveTopRight(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator)
{

	if (board[selectedRow][selectedCol] == " ")
	{
		cout << "* Error: Empty Space.." << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] != gameObj.symbolTurn && board[selectedRow][selectedCol] != "K" + gameObj.symbolTurn)
	{
		cout << "* Error: Can't move Opponent's Pieces.." << endl;
		Sleep(3000);
	}
	else if ((selectedCol + 1) > 7 || (selectedRow - 1) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] == board[selectedRow - 1][selectedCol + 1])   // if same piece  // can't jump over.
	{
		cout << "* Error: Can't Jump Over your Own Piece..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow - 1][selectedCol + 1] == " ")  // Dot // One Step.
	{
		board[selectedRow - 1][selectedCol + 1] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = " ";

		if (selectedRow - 1 == 0)
		{
			board[selectedRow - 1][selectedCol + 1] = "K" + gameObj.symbolTurn;
		}

	}
	else if ((selectedCol + 2) > 7 || (selectedRow - 2) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if ((board[selectedRow][selectedCol] == gameObj.player1->pKing || board[selectedRow][selectedCol] == gameObj.player2->pKing) && (board[selectedRow][selectedCol] == "K" + gameObj.symbolTurn) && (board[selectedRow - 2][selectedCol + 2] == " ") && (board[selectedRow - 2][selectedCol + 2] != gameObj.player1->pKing || board[selectedRow - 2][selectedCol + 2] != gameObj.player2->pKing))     //kING mOVEMENT
	{
		board[selectedRow - 2][selectedCol + 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow - 1][selectedCol + 1] = " ";

		if (board[selectedRow][selectedCol] == gameObj.player1->pKing)
		{
			++gameObj.player1->pScores;
			--gameObj.player2->pPieces;
		}
		else if (board[selectedRow][selectedCol] == gameObj.player2->pKing)
		{
			++gameObj.player2->pScores;
			--gameObj.player1->pPieces;
		}
	}
	else if ((board[selectedRow - 2][selectedCol + 2] == " ") && (board[selectedRow - 2][selectedCol + 2] != board[selectedRow][selectedCol])) // opponent piece // Can Jump & Capture.
	{
		board[selectedRow - 2][selectedCol + 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow - 1][selectedCol + 1] = " ";
		++gameObj.player2->pScores;
		--gameObj.player1->pPieces;


		if (selectedRow - 2 == 0)    //Make it a king
		{
			board[selectedRow - 2][selectedCol + 2] = gameObj.player2->pKing;
		}

	}
	else
	{
		cout << "* Error: Can't Jump there..!" << endl;
		Sleep(3000);
	}

	if (gameObj.player1->pPiecesGetter() == 0 || gameObj.player2->pPiecesGetter() == 0)
	{
		gameObj.WinScreen(gameObj);
		terminator = true;
	}
}

void movements::moveTopLeft(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator)
{
	if (board[selectedRow][selectedCol] == " ")
	{
		cout << "* Error: Empty Space.." << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] != gameObj.symbolTurn && board[selectedRow][selectedCol] != "K" + gameObj.symbolTurn)
	{
		cout << "* Error: Can't move Opponent's Pieces.." << endl;
		Sleep(3000);
	}
	else if ((selectedRow - 1) < 0 || (selectedCol - 1) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow][selectedCol] == board[selectedRow - 1][selectedCol - 1])   // if same piece  // can't jump over.
	{
		cout << "* Error: Can't Jump Over your Own Piece..!" << endl;
		Sleep(3000);
	}
	else if (board[selectedRow - 1][selectedCol - 1] == " ")  // Dot // One Step.
	{
		board[selectedRow - 1][selectedCol - 1] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = " ";

		if (selectedRow - 1 == 0)
		{
			board[selectedRow - 1][selectedCol - 1] = "K" + gameObj.symbolTurn;
		}

	}

	else if ((selectedRow - 2) < 0 || (selectedCol - 2) < 0)
	{
		cout << "* Error: There is a Wall ahead..!" << endl;
		Sleep(3000);
	}
	else if ((board[selectedRow][selectedCol] == gameObj.player1->pKing || board[selectedRow][selectedCol] == gameObj.player2->pKing) && (board[selectedRow][selectedCol] == "K" + gameObj.symbolTurn) && (board[selectedRow - 2][selectedCol - 2] == " ") && (board[selectedRow - 2][selectedCol - 2] != gameObj.player1->pKing || board[selectedRow - 2][selectedCol - 2] != gameObj.player2->pKing))     //kING mOVEMENT
	{
		board[selectedRow - 2][selectedCol - 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow - 1][selectedCol - 1] = " ";

		if (board[selectedRow][selectedCol] == gameObj.player1->pKing)
		{
			++gameObj.player1->pScores;
			--gameObj.player2->pPieces;
		}
		else if (board[selectedRow][selectedCol] == gameObj.player2->pKing)
		{
			++gameObj.player2->pScores;
			--gameObj.player1->pPieces;
		}
	}
	else if ((board[selectedRow - 2][selectedCol - 2] == " ") && (board[selectedRow - 2][selectedCol - 2] != board[selectedRow][selectedCol])) // opponent piece // Can Jump & Capture.
	{
		board[selectedRow - 2][selectedCol - 2] = board[selectedRow][selectedCol];
		board[selectedRow][selectedCol] = board[selectedRow - 1][selectedCol - 1] = " ";
		++gameObj.player2->pScores;
		--gameObj.player1->pPieces;

		if (selectedRow - 2 == 0)            // it deserved to be a king
		{
			board[selectedRow - 2][selectedCol - 2] = gameObj.player2->pKing;
		}

	}
	else
	{
		cout << "* Error: Can't Jump there..!" << endl;
		Sleep(3000);
	}

	if (gameObj.player1->pPiecesGetter() == 0 || gameObj.player2->pPiecesGetter() == 0)
	{
		gameObj.WinScreen(gameObj);
		terminator = true;
	}
}