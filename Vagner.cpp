#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int num_head = 0, num_tail = 0;

//estrutura da peca
struct Piece
{
	//lados da peca
	int num1, num2;
};

//no da lista
struct Node
{
	Piece piece;
	Node *next, *prev;
};

//funcao que cria o no
Node *create_node(Piece piece)
{
	Node *new_node;
	new_node = (Node *)malloc(sizeof(Node));
	new_node->piece = piece;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

//classe da lista de pecas
class ListaPecas
{
protected:
	//nos que representam o inicio e fim da lista
	Node *head, *tail;

public:
	//no do iterador
	Node *it;
	int number_of_pieces;

	//funcao que inica a lista
	void initializate()
	{
		head = NULL;
		tail = NULL;
	}

	//funcao que adiciona itens no final da lista
	void push_back(Piece piece)
	{
		if (head == NULL)
		{
			head = create_node(piece);
			tail = head;
			number_of_pieces++;
		}
		else
		{
			tail->next = create_node(piece);
			tail->next->prev = tail;
			tail = tail->next;
			number_of_pieces++;
		}
	}

	//funcao que adiciona itens no inicio da lista
	int push_front(Piece piece)
	{
		if (num_head != piece.num1 && num_head != piece.num2 && head != NULL)
		{
			cout << "Error\n";
			return 0;
		}
		if (head == NULL)
		{
			head = create_node(piece);
			tail = head;
			if (num_tail == piece.num1)
				num_head = piece.num2;
			else
				num_head = piece.num1;
			return 1;
		}
		else
		{
			head->prev = create_node(piece);
			head->prev->next = head;
			head = head->prev;
			if (num_head == piece.num1)
				num_head = piece.num2;
			else
				num_head = piece.num1;
			return 1;
		}
	}

	//funcao que remove um item da lista em determinada posicao
	int removeat(int i)
	{
		if (i >= number_of_pieces)
		{
			cout << "Invalido!\n";
			return 0;
		}
		if (number_of_pieces == 1)
		{
			number_of_pieces--;
			return 1;
		}
		if (i == 0)
		{
			it = head;
			head = head->next;
			head->prev = NULL;
			number_of_pieces--;
			free(it);
			return 1;
		}
		else if (i == number_of_pieces - 1)
		{
			it = tail;
			tail = tail->prev;
			tail->next = NULL;
			number_of_pieces--;
			free(it);
			return 1;
		}
		else
		{
			it = head;
			for (int j = 0; j < i; j++)
			{
				it = it->next;
			}
			it->prev->next = it->next;
			it->next->prev = it->prev;
			number_of_pieces--;
			free(it);
			return 1;
		}
	}

	//funcao que imprime a lista
	void printList()
	{
		it = tail;
		for (int i = 0; i < number_of_pieces; i++)
		{
			cout << it->piece.num1 << " | " << it->piece.num2 << endl;
			it = it->next;
		}
	}
};

//classe que representa o cava
class Dig : public ListaPecas
{
public:
	//funcao que cria as pecas
	void createPieces()
	{
		Piece peca;
		for (int i = 6; i >= 0; i--)
		{
			peca.num1 = i;
			for (int j = i; j >= 0; j--)
			{
				peca.num2 = j;
				push_front(peca);
			}
		}
	}
};

//classe que se refere as pecas que estao na mao do jogador
class Hand : public ListaPecas
{
public:
	int won()
	{
		if (!number_of_pieces)
			return 1;
		return 0;
	}
	//confere se eh possivel da pessoa jogar a peca na mesa
	int ispossible()
	{
		it = head;
		for (int i = 0; i < number_of_pieces; i++)
			if (it->piece.num1 == num_head || it->piece.num1 == num_tail || it->piece.num2 == num_head || it->piece.num2 != num_tail)
				return 1;
			it = it->next;
		return 0;
	}
};

class Table : public ListaPecas
{
};

int main()
{
	Piece a;
	Piece b;
	a.num1 = 1;
	a.num2 = 2;
	b.num1 = 3;
	b.num2 = 4;
	Hand Player[4];
	Table table;
	table.initializate();
	table.push_front(a);
	table.push_front(b);
	//table.printList();
	for (int i = 0; i < 4; i++)
		Player[i].initializate();

	return 0;
}