#pragma once
#include<iostream>
#include<string>
#include"CheckersGame.h"

class movements
{
public:
	static void moveBottomRight(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool &terminator);

	static void moveBottomLeft(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator);

	static void moveTopRight(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator);

	static void moveTopLeft(string board[][8], int selectedRow, int selectedCol, CheckersGame& gameObj, bool& terminator);

};