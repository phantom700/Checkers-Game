#include<iostream>
#include"players.h"
#include"CheckersGame.h"
using namespace std;

int main()
{
	CheckersGame game;

	PlayerClass player1(int, int, string, string), player2(int, int, string, string);



	int choice;    // to store the menu choice of user
	game.game_menu();   // menu list function call.

	cin >> choice;

	if (choice == 1)  // if the user chooses play game option.
	{
		system("cls");    // clear screen function.
		game.player1->nameSetter();
		game.player2->nameSetter();
		system("cls");

		game.gameRun(game);
	}
	else if (choice == 2)  // if user chooses option 2 which will call the credits() function.
	{
		system("cls");
		game.credits();
	}
	else if (choice == 3)  // if option selected is 3 then it will call the rule() function which will then display the rules of the game.
	{
		system("cls");
		game.rules();
	}
	else if (choice == 4)  // if the option selected is 4 then it will display the 3 highest scores.
	{
		system("cls");
		game.file_read();
	}
	else if (choice == 5)  // if the user input 5 the program will terminate.
	{
		system("pause");
		return 0;
	}
}