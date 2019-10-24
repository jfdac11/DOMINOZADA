#include "Global.hpp"
#include "PiecesList.hpp"

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
public:

	//sobrecarga da funcao ListaPecas, com verificacao se eh possivel inserir a peca na mesa
	int push_back(Piece piece)
	{
		if (num_tail != piece.num1 && num_tail != piece.num2 && head != NULL)
		{
			cout << "Error\n";
			return 0;
		}
		if (head == NULL)
		{
			head = create_node(piece);
			tail = head;
			if (num_tail == piece.num1)
				num_tail = piece.num2;
			else
				num_tail = piece.num1;
			return 1;
		}
		else
		{
			tail->next = create_node(piece);
			tail->next->prev = tail;
			tail = tail->next;
			if (num_tail == piece.num1)
				num_tail = piece.num2;
			else
				num_tail = piece.num1;
			return 1;
		}
	}

	//sobrecarga da funcao ListaPecas, com verificacao se eh possivel inserir a peca na mesa
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
};