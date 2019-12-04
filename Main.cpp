#include "Game.hpp"

unsigned int numero_jogadores = 0;

int main()
{
	srand(time(NULL));
	Dig dig;
	dig.initializate();
	dig.createPieces();
	Table table;
	table.initializate();
	drawTitle();
	system("PAUSE");
	system("cls");
	Player player[4];
	while (true)
	{
		cout << "\nEscolha o numero de jogadores! \n";
		cout << "2 jogadores ou 4 jogadores?" << endl;
		cin >> numero_jogadores;
		fflush(stdin);
		if (numero_jogadores == 2 || numero_jogadores == 4)
		{
			createPlayers(numero_jogadores, &dig, player);
			break;
		}
		else
		{
			cout << "\nNUMERO ERRADO" << endl;
		}
	}
	cout << "\n\n";
	for (int i = 0; true; i++)
	{
		player[i % numero_jogadores].hand.turn(&table, &dig, player[i % numero_jogadores].nome);
		table.printTable();
		if (player[i % numero_jogadores].hand.won())
		{
			cout << "Parabens " << player[i % numero_jogadores].nome << ", Voce esta muito feliz!";
			break;
		}
	}
	return 0;
}
