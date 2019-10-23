#include "Global.hpp"

typedef struct
{
	char Nome[50];
} Player;

Player player[4];

int createPlayers(int num_players)
{
	if (num_players == 2)
	{
		for (int counter = 1; counter <= num_players; counter++)
		{
			cout << "Player " << counter << ": ";
			cin >> player[counter].Nome;
		}
		return 1;
		//vai ter um cava com 14 pecas sorteadas aleatoriamente
	}
	else
	{
		for (int counter = 1; counter <= num_players; counter++)
		{
			cout << "Player " << counter << ": ";
			cin >> player[counter].Nome;
		}
		return 2;
		//nao vai ter cava
	}
}

void printPlayers(int num_jogadores)
{
	for (int counter = 1; counter <= num_jogadores; counter++)
	{
		cout << "Player " << counter << ", Nome:" << player[counter].Nome << endl;
	}
}
