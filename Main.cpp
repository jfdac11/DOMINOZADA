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
		ignore_char_cin();
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
			system("pause");
			system("cls");
		}
	}
	cout << "\n\n";
	bool firstTurn = true;
	bool hasBucha = false;
	Piece bucha;
	bucha.num1 = 6;
	bucha.num2 = 6;
	for (int i = 0; true; i++)
	{
		if (firstTurn)
		{
			hasBucha = player[i % numero_jogadores].hand.has_piece(bucha);
			if (!(i % numero_jogadores))
			{
				bucha.num1--;
				bucha.num2--;
			}
			if (!hasBucha)
				continue;
			else
				firstTurn = false;
		}
		player[i % numero_jogadores].hand.turn(&table, &dig, player[i % numero_jogadores].nome);
		table.printTable();
		if (player[i % numero_jogadores].hand.won())
		{
			cout << "Parabens " << player[i % numero_jogadores].nome << ", Voce esta muito feliz!";
			break;
		}
		int cont=0;
		while(cont < numero_jogadores && !player[cont].hand.ispossible(&table))
		{
			cont++;
		}
		if(cont == numero_jogadores){
			break;
		}
	}
	return 0;
}