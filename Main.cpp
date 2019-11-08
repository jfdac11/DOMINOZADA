#include "Global.hpp"
#include "Players.hpp"
//#include "Pieces.hpp"

unsigned int numero_jogadores = 0;

int main()
{
	srand(time(NULL));
	Dig dig;
	dig.initializate();
	dig.createPieces();
	Table table;
	table.initializate();
	cout << "Bem vindo a o DOMINO BRABO\n";
	system("PAUSE");
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
	system("pause");
	system("cls");
	return 0;
}
