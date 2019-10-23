#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int IntH = 0, IntT = 0;
struct Piece{
	int num1, num2;
};

struct Node{
	Piece piece;
	Node *next, *prev;
};
Node* create_node(Piece piece){
	Node* new_node;
	new_node = (Node*) malloc(sizeof(Node));
	new_node->piece = piece;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

class Hand{
private:
	Node *head, *tail;
public:
	Node *it;
	int number_of_pieces;
	void initializate(){
		head = NULL;
		tail = NULL;
		number_of_pieces = 0;
	}
	void push_back(Piece piece){
		if(head == NULL){
			head = create_node(piece);
			tail = head;
			number_of_pieces++;
		}
		else{
			tail->next = create_node(piece);
			tail->next->prev = tail;
			tail = tail->next;
			number_of_pieces++;
		}
		
	}
	int removeat(int i){
		if(i>=number_of_pieces){
			cout<<"Invalido!\n";
			return 0;
		}
		if(number_of_pieces == 1){
			number_of_pieces--;
			return 1;
		}
		if(i == 0){
			it=head;
			head=head->next;
			head->prev = NULL;
			number_of_pieces--;
			free(it);
			return 1;
		}
		else if(i == number_of_pieces - 1){
			it=tail;
			tail=tail->prev;
			tail->next = NULL;
			number_of_pieces--;
			free(it);
			return 1;
		}
		else{
			it = head;
			for(int j = 0; j<i; j++){
				it = it->next;
			}
			it->prev->next = it->next;
			it->next->prev = it->prev;
			number_of_pieces--;
			free(it);
			return 1;
		}
	}
	int won(){
		if(!number_of_pieces)
			return 1;
		return 0;
	}
	int ispossible(){
		it=head;
		for(int i=0; i<number_of_pieces; i++)
			if(it->piece.num1 == IntH || it->piece.num1 == IntT || it->piece.num2 == IntH || it->piece.num2 != IntT)
				return 1;
		return 0;
	}
};

class Table{
private:
	Node *head, *tail;
public:
	Node *it;
	int number_of_pieces;
	void initializate(){
		head = NULL;
		tail = NULL;
		IntH = 0;
		IntT = 0;
	}
	int push_back(Piece piece){
		if(IntT != piece.num1 && IntT != piece.num2 && head != NULL){
			cout<<"Error\n";
			return 0;
		}
		if(head == NULL){
			head = create_node(piece);
			tail = head;
			if(IntT == piece.num1)
				IntT = piece.num2;
			else
				IntT = piece.num1;
			return 1;
		}
		else{
			tail->next = create_node(piece);
			tail->next->prev = tail;
			tail = tail->next;
			if(IntT == piece.num1)
				IntT = piece.num2;
			else
				IntT = piece.num1;
			return 1;
		}
		
	}
	int push_front(Piece piece){
		if(IntH != piece.num1 && IntH != piece.num2 && head != NULL){
			cout<<"Error\n";
			return 0;
		}
		if(head == NULL){
			head = create_node(piece);
			tail = head;
			if(IntT == piece.num1)
				IntH = piece.num2;
			else
				IntH = piece.num1;
			return 1;
		}
		else{
			head->prev = create_node(piece);
			head->prev->next = head;
			head = head->prev;
			if(IntH == piece.num1)
				IntH = piece.num2;
			else
				IntH = piece.num1;
			return 1;
		}
	}
	
};

int main(){
	Piece a;
	a.num1=1;
	a.num2=2;
	Hand Player[4];
	Table table;
	table.initializate();
	for(int i=0; i<4; i++)
		Player[i].initializate();
	
	
	
	
	return 0;
}
