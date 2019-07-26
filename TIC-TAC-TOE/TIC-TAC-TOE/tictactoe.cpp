
#include <iostream>
using namespace std;
char board[9] = {};              
								

void clearboard()           
{
	for (int i = 0; i<9; i++){ 
		board[i] = '-';  
	}

}


bool game_con(char player)
{
	int wins[][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, 
	{2,5,8}, {0,4,8}, {2,4,6}};
	
	for (int i = 0; i<8; i++)     
	{
		int count = 0;         
		for (int j = 0; j<3; j++) 
		{
			if (board[wins[i][j]] == player)
				count++;
		}
		if (count == 3) 
		{
			return true;
		}
	}
	return false;    
}



void print_board()
{
	cout << "     |     |     " << endl;
	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----------------" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
	cout << "     |     |     " << endl;

}

int game_map() 
{
	cout << "\n  Menu hodov: \n";     
	cout << "--7--|--8--|--9--" << endl;
	cout << "--4--|--5--|--6--" << endl;
	cout << "--1--|--2--|--3--" << endl;
	cout << "\n";                      

	print_board();
	cout << "\nVvod chisla: ";


	int move;
	cin >> move;
	while (move > 9 || move < 1 || board[move - 1] != '-') 
	{
		cout << "Vvedite chislo ot (1 do 9):\n";
		cin >> move;

	}
	return move;
}


char play_and_get_winner() 
{
	int turn = 1;

	while (!game_con('X') && !game_con('0')) 
	{
		system("cls");
		int move = game_map();

		system("cls");
		if (turn % 2 == 1) 
		{
			board[move - 1] = 'X';
			if (game_con('X')) 
			{
				cout << "X,Pozdravlyau vi viigrali!\n";
				return 'X'; 
			}

		}
		else                     
		{
			board[move - 1] = '0';
			if (game_con('0')) 
			{
				cout << "O,Pozdravlyau vi viigrali!\n";
				return '0';       
			}
		}
		turn++;                 
		if (turn == 10)          
		{
			cout << "nichya\n";
			return 'D';             
		}
	}
}

int main()                         
{
	int start;

	cout << "        Welcome to the game: " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << " ----------------------------------------" << endl;
	cout << "|                                        |" << endl;
	cout << "|            TIC-TAC-TOE                 |" << endl;
	cout << "|                                        |" << endl;
	cout << "|                                        |" << endl;
	cout << " ----------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "1 - NEW GAME: " << endl;
	cout << "2 - EXIT" << endl;
	cin >> start;
	system("pause");
	system("cls");
	if (start == 1) {
		cout << "The game beginning:" << endl;
		cout << endl;
		cout << "Privetstvuyu\n\n";
		char reply = 'y';
		int x_wins = 0, o_wins = 0, ties = 0;

		while (reply == 'y')
		{
			clearboard();
			char winner = play_and_get_winner();
			print_board();

			switch (winner) {
			case 'X':
				x_wins++;
				break;
			case '0':
				o_wins++;
				break;
			case 'D':
				ties++;
				break;
			}

			cout << "\n\t*Winer statistic*\nPlayer X: " << x_wins << ", Player 0: " << o_wins << " and Ties: " << ties << "\n\n";
			cout << "\n would you like to play again? (y/n): ";
			cin >> reply;
			while (reply != 'y' && reply != 'n')
			{
				cout << "please inter a valid reply (y/n):";
				cin >> reply;
			}

		}
		return 0;
	}
	if (start == 2) {
		cout << "Exit the game" << endl;
	}
}
