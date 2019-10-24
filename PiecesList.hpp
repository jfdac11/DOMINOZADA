#include "Global.hpp"

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
		number_of_pieces = 0;
	}

	//funcao que adiciona itens no final da lista
	//virtual serve para ser possivel dar override
	virtual int push_back(Piece piece)
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
		return 1;
	}

	//funcao que adiciona itens no inicio da lista
	virtual int push_front(Piece piece)
	{
		if (head == NULL)
		{
			head = create_node(piece);
			tail = head;
			number_of_pieces++;
		}
		else
		{
			head->prev = create_node(piece);
			head->prev->next = head;
			head = head->prev;
			number_of_pieces++;
		}
		return 1;
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
		it = head;
		for (int i = 0; i < number_of_pieces; i++)
		{
			cout << it->piece.num1 << " | " << it->piece.num2 << endl;
			it = it->next;
		}
	}
};