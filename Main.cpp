#include "Game.hpp"


using namespace std;
int main()
{
	unsigned int numero_jogadores = 0;
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
	bucha.num1 = 7;
	bucha.num2 = 7;
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
			{
				continue;
			}
			else
			{
				table.push_back(player[i % numero_jogadores].hand.it->piece);
				player[i % numero_jogadores].hand.removeat(player[i % numero_jogadores].hand.it->piece.index);
				table.printTable();
				cout << player[i % numero_jogadores].nome << " iniciou a partida.\n";
				system("pause");
				firstTurn = false;
				i++;
			}
		}
		player[i % numero_jogadores].turn(&table, &dig, player[i % numero_jogadores].nome);
		table.printTable();
		if (player[i % numero_jogadores].hand.won())
		{
			cout << "Parabens " << player[i % numero_jogadores].nome << ", voce esta muito feliz!";
		
			ofstream makefile;
			makefile.open("config.txt",ios_base::in);
		
			if(!cadastro)
			{
				makefile.open("C://Vencedores.txt");
				 /* Se não existe, cria */
			}
			makefile << player[i % numero_jogadores].nome;
			makefile.close();
			break;
		}
		
		
		int cont = 0;
		while (dig.size() == 0 && cont < numero_jogadores && !player[cont].hand.ispossible(&table))
		{
			cont++;
		}
		if (cont == numero_jogadores)
		{
			//front do empate
			break;
		}
}
	return 0;
    
}
