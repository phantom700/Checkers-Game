#pragma once
#include<iostream>
#include<string>

using namespace std;

class PlayerClass
{
	string pName;
	unsigned int pPieces;
	int pScores;

public:
	string pSymbol;
	string pKing;
	
	static int countPlayers;

	friend class movements;

	PlayerClass();

	void nameSetter();

	string nameGetter();

	int pScoreGetter();

	int pPiecesGetter();
};
