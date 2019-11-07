#include "Global.hpp"
#include "Pieces.hpp"

typedef struct
{
	char nome[50];
	Hand hand;
} Player;

Player player[4];

int createPlayers(int num_players)
{
	if (num_players == 2)
	{
		for (int counter = 1; counter <= num_players; counter++)
		{
			cout << "Player " << counter << ": ";
			cin >> player[counter].nome;
			player[counter].hand.initializate();
		}
		return 1;
		//vai ter um cava com 14 pecas sorteadas aleatoriamente
	}
	else
	{
		for (int counter = 1; counter <= num_players; counter++)
		{
			cout << "Player " << counter << ": ";
			cin >> player[counter].nome;
		}
		return 2;
		//nao vai ter cava
	}
}

void printPlayers(int num_jogadores)
{
	for (int counter = 1; counter <= num_jogadores; counter++)
	{
		cout << "Player " << counter << ", Nome:" << player[counter].nome << endl;
	}
}
