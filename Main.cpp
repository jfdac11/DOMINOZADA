#include "Global.hpp"
#include "Players.hpp"
#include "Pieces.hpp"

unsigned int numero_jogadores = 0;

int main()
{
	cout << "Bem vindo a o DOMINO BRABO\n";
	system("PAUSE");
	while (true)
	{
		cout << "\nEscolha o numero de jogadores! \n";
		cout << "2 jogadores ou 4 jogadores?" << endl;
		cin >> numero_jogadores;
		fflush(stdin);
		if (numero_jogadores == 2 || numero_jogadores == 4)
		{
			createPlayers(numero_jogadores);
			break;
		}
		else
		{
			cout << "\nNUMERO ERRADO" << endl;
		}
	}
	cout << "\n\n";
	printPlayers(numero_jogadores);
	system("pause");
	return 0;
}
