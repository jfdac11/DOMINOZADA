#include "Global.hpp"
#include <list>

typedef struct
{
	int lado_peca[2];
} PECA;

list<PECA> Pecas;

void createPieces()
{
	PECA aux;
	for (int i = 6; i >= 0; i--)
	{
		aux.lado_peca[0] = i;
		for (int j = i; j >= 0; j--)
		{
			aux.lado_peca[1] = j;
			Pecas.push_back(aux);
		}
	}
}

void printPieces()
{
	for (list<PECA>::iterator it = Pecas.begin(); it != Pecas.end(); it++)
	{
		cout << it->lado_peca[0] << " | " << it->lado_peca[1] << endl;
	}
}
