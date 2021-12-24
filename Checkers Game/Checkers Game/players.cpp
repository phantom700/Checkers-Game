#include"players.h"


int PlayerClass::countPlayers = 0;

PlayerClass::PlayerClass()
{
	pPieces = 12;
	pScores = 0;
	if (countPlayers == 0)
	{
		pSymbol = "@";
		pKing = "K@";
		countPlayers++;
	}
	else
	{
		pSymbol = "#";
		pKing = "K#";
		//countPlayers++;
	}
}

void PlayerClass::nameSetter() { cout << "* Type Player " << (pSymbol == "@" ? 1 : 2) << " Name: "; cin >> pName; }
string PlayerClass::nameGetter() { return pName; }
int PlayerClass::pScoreGetter() { return pScores; }
int PlayerClass::pPiecesGetter() { return pPieces; }



