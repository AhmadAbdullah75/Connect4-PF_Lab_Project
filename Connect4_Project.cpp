#include <iostream>
#include <string>
#include<ctime>
#include<fstream>
std::string player1, player2;
int turns = 0;
char ch;
int r = 0, b = 0;
char play_opt();
char option[50];
const int ROWS = 6;
const int COLUMNS = 7;
char board[ROWS][COLUMNS];
void file();
std::string fill;
// to initialize board
void initializeBoard()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j] = '.';
		}
	}
}
// to print board
void printBoard() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
//storing moves
bool placeDisc(int column, char disc) {
	if (column < 1 || column > COLUMNS) {
		return false;
	}
	//storing moves from the end
	for (int i = ROWS - 1; i >= 0; i--)
	{
		if (board[i][column - 1] == '.')
		{
			board[i][column - 1] = disc;
			return true;
		}
	}
	return false;
}
//horizontal
bool checkWin(char disc)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS - 3; j++)
		{
			if (board[i][j] == disc && board[i][j + 1] == disc &&
				board[i][j + 2] == disc && board[i][j + 3] == disc)
			{
				return true;
			}
		}
	}
	//vertical checking 
	for (int i = 0; i < ROWS - 3; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (board[i][j] == disc && board[i + 1][j] == disc &&
				board[i + 2][j] == disc && board[i + 3][j] == disc)
			{
				return true;
			}
		}
	}
	//right to left diagonal
	for (int i = 3; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS - 3; j++) {
			if (board[i][j] == disc && board[i - 1][j + 1] == disc &&
				board[i - 2][j + 2] == disc && board[i - 3][j + 3] == disc) {
				return true;
			}
		}
	}//lef to right diagonal
	for (int i = 3; i < ROWS; i++) {
		for (int j = 3; j < COLUMNS; j++) {
			if (board[i][j] == disc && board[i - 1][j - 1] == disc &&
				board[i - 2][j - 2] == disc && board[i - 3][j - 3] == disc) {
				return true;
			}
		}
	}
	return false;
}
//draw
bool checkDraw() {
	for (int i = 0; i < COLUMNS; i++) {
		if (board[0][i] == '.') {
			return false;
		}
	}
	return true;
}
void all()
{
	//instruction option
	std::string ins = "instructions";
	std::string inst = "Instructions";
	if (option == ins || option == inst)
	{
		std::cout << "\t\t\tINSTRUCTIONS:";
		std::cout << "\nThe Connect 4 game is a classic strategy game in which 2 players go head-to-head in a battle to own the grid!\n";
		std::cout << "Players choose blue or red discs. \nThey drop the discs into the grid, starting in the middle or at the edge to stack their colored discs\nupwards, horizontally, or diagonally.\nUse strategy to block opponents while aiming to be the first player to get 4 in a row to win. ";
	}
	//credits option
	std::string cr = "credits";
	std::string cred = " Credits";
	if (option == cr || option == cred)
	{
		std::cout << " \t\t\t CREDITS:\nProgrammed by: \nAyesha Noor\nHashim Shaid\nAhmad Abdullah ";
	}

	//play option
	std::string pl = "play";
	std::string play = " Play";
	if (option == pl || option == play)
	{
		turns = 0;
		ch = play_opt();
	}
	//records option
	std::string re = "records";
	std::string rec = "Records";
	if (option == re || option == rec)
	{
		file();
	}
	//exit game
	std::string ex = "exit";
	std::string exit = "Exit";
	if (option == ex || option == exit)
	{
		std::exit(0);
	}
}
//all play criteria and code
char play_opt() {

	std::cout << "Enter name for Player 1 (Red): ";
	std::cin >> player1;
	std::cout << "Enter name for Player 2 (Blue): ";
	std::cin >> player2;
	std::cout << "\n\t For Toss select head or tail\n " << player1 << " enter choice:";
	std::string currentPlayer;
	std::string choice;
	std::cin >> choice;
	srand((int)time(0));
	// Toss by random numbers
	int time = (rand() % 2) + 1;
	if (time == 1)
	{
		if (choice == "head" || choice == " Head")
		{
			std::cout << " head!  " << player1 << " wins the race";
			std::cout << " wins the race.";
		}
		else
		{
			std::cout << " tail!  " << player1 << " wins the race";
			std::cout << " wins the race.";
		}
		currentPlayer = player1;
	}
	if (time == 2)
	{
		if (choice == "head" || choice == "Head")
		{
			std::cout << " tail!  " << player2 << " wins the race";
			std::cout << " wins the race.";
		}
		else
		{
			std::cout << " head!  " << player2 << " wins the race";
			std::cout << " wins the race.";
		}
		currentPlayer = player2;
	}
	std::cout << std::endl;
	initializeBoard();//calling function of initialize board
	printBoard();// to print board
	char currentDisc = 'R';
	int column;
	//storing moves and displaing turns
	while (true) {
		std::cout << currentPlayer << "'s turn. Please enter your choice (column 1-7): ";
		std::cin >> column;
		if (!placeDisc(column, currentDisc)) {
			std::cout << "Invalid move! Try again." << std::endl;
			continue;
		}
		turns++;
		printBoard();
		//checking winning conditions
		if (checkWin(currentDisc))
		{
			std::cout << currentPlayer << " wins in " << turns << " turns!" << std::endl;
			break;
		}
		// draw case
		if (checkDraw())
		{
			std::cout << "Game is a draw!" << std::endl;
			break;
		}

		currentPlayer = (currentPlayer == player1) ? player2 : player1;
		currentDisc = (currentDisc == 'R') ? 'B' : 'R';
	}
	fill = currentPlayer;
	return currentDisc;
}
int main()
{

	for (int i = 0; i >= 0; i++)
	{
		//menu
		std::cout << "Menu:\n\t\t      Play\n\tInstructions\t\t Credits\n\tRecords\t\t\t Exit\n";
		//getting option from menu from user
		std::cout << "\nEnter option: ";
		std::cin.getline(option, 50);
		all();
	}
	system("pause");
}
//file handling
void file() {
	std::ofstream out;
	std::ifstream in;
	out.open("file.txt");
	if (!out.is_open())
	{
		std::cout << "error in opening file";
	}
	else
	{
		out << fill << "\t\t" << " wins in " << turns << " turns!" << std::endl;
	}
	out.close();
	in.open("file.txt");
	if (!in.is_open())
	{
		std::cout << "error in opening file";
	}
	else
	{
		std::string line;
		char ch;
		while (!in.eof())
		{
			in.get(ch);
			std::cout << ch;
		}
	}
}
