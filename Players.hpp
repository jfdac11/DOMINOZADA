#include "Global.hpp"
#include "Pieces.hpp"

typedef struct
{
	char nome[50];
	Hand hand;
} Player;

int createPlayers(int num_players, Dig *dig, Player *player)
{
	for (int counter = 0; counter < num_players; counter++)
	{
		cout << "Player " << counter + 1 << ": ";
		cin >> player[counter].nome;
		player[counter].hand.initializate();
		for(int i=0; i<7;i++){
			dig->it = dig->begin();
			player[counter].hand.push_front(dig->it->piece);
			dig->removeat(0);
		}
		player[counter].hand.printHand();
	}
		return 1;
		//vai ter um cava com 14 pecas sorteadas aleatoriamente
	
}
/*
void printPlayers(int num_jogadores)
{
	for (int counter = 1; counter <= num_jogadores; counter++)
	{
		cout << "Player " << counter << ", Nome:" << player[counter].nome << endl;
	}
}*/
