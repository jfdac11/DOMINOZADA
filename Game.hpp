#include "ListPieces.hpp"

//classe que representa o cava
class Dig : public ListaPecas
{
public:
    //funcao que cria as pecas
    void createPieces()
    {
        Piece vector[28];
        Piece piece;
        int pos = 0;
        for (int i = 6; i >= 0; i--)
        {
            piece.num1 = i;
            for (int j = i; j >= 0; j--)
            {
                piece.num2 = j;
                vector[pos] = piece;
                pos++;
            }
        }
        //randomiza a lista
        for (int k = 0; k < 200; k++)
        {
            Piece aux;
            int randNum1 = (rand()) % 28;
            aux = vector[randNum1];
            int randNum2 = (rand()) % 28;
            vector[randNum1] = vector[randNum2];
            vector[randNum2] = aux;
        }
        for (int m = 0; m < 28; m++)
        {
            push_front(vector[m]);
        }
        printList();
    }
};

//classe que se refere as pecas da mesa
class Table : public ListaPecas
{
public:
    int num_head, num_tail;
    //sobrecarga da funcao ListaPecas, com verificacao se eh possivel inserir a piece na mesa
    int push_back(Piece piece)
    {
        if (num_tail != piece.num1 && num_tail != piece.num2 && head != NULL)
        {
            cout << "Impossivel inserir peca\n";
            system("pause");
            return 0;
        }
        if (head == NULL)
        {
            head = create_node(piece);
            tail = head;
            num_tail = piece.num2;
            num_head = piece.num1;
            return 1;
        }
        else
        {
            tail->next = create_node(piece);
            tail->next->prev = tail;
            tail = tail->next;
            if (num_tail == piece.num1)
            {
                num_tail = piece.num2;
                tail->piece.num1 = piece.num1;
                tail->piece.num2 = piece.num2;
            }
            else
            {
                num_tail = piece.num1;
                tail->piece.num1 = piece.num2;
                tail->piece.num2 = piece.num1;
            }
            return 1;
        }
    }

    //sobrecarga da funcao ListaPecas, com verificacao se eh possivel inserir a piece na mesa
    int push_front(Piece piece)
    {
        if (num_head != piece.num1 && num_head != piece.num2 && head != NULL)
        {
            cout << "Impossivel inserir peca\n";
            system("pause");
            return 0;
        }
        if (head == NULL)
        {
            head = create_node(piece);
            tail = head;
            num_tail = piece.num2;
            num_head = piece.num1;
            return 1;
        }
        else
        {
            head->prev = create_node(piece);
            head->prev->next = head;
            head = head->prev;
            if (num_head == piece.num1)
            {
                num_head = piece.num2;
                head->piece.num1 = piece.num2;
                head->piece.num2 = piece.num1;
            }
            else
            {
                num_head = piece.num1;
                head->piece.num1 = piece.num1;
                head->piece.num2 = piece.num2;
            }
            return 1;
        }
    }
    void printTable()
    {
        system("cls");
        for (it = head; it != NULL; it = it->next)
        {
            cout << "\t\t***\n";
            cout << "\t\t*" << it->piece.num1 << "*\n";
            cout << "\t\t*" << (char)205 << "*\n";
            cout << "\t\t*" << it->piece.num2 << "*\n";
            cout << "\t\t***\n\n";
        }
        cout << endl;
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
    //confere se eh possivel que a pessoa jogue alguma peca na mesa
    bool ispossible(Table *table)
    {
        int i = 0;
        it = head;
        while (it != NULL)
        {
            if (it->piece.num1 == table->num_head || it->piece.num1 == table->num_tail || it->piece.num2 == table->num_head || it->piece.num2 == table->num_tail)
                return true;
            i++;
            it = it->next;
        }
        if (!table->size())
            return true;
        return false;
    }
    //imprime a lista
    void printHand()
    {
        int count = 0;
        it = head;
        while (it != NULL)
        {
            cout << " " << count++ << "  ";
            it = it->next;
        }
        cout << endl;

        it = head;
        while (it != NULL)
        {
            cout << "*** ";
            it = it->next;
        }
        cout << endl;

        it = head;
        while (it != NULL)
        {
            cout << "*" << it->piece.num1 << "* ";
            it = it->next;
        }
        cout << endl;

        it = head;
        while (it != NULL)
        {
            cout << "*" << (char)205 << "* ";
            it = it->next;
        }
        it = head;
        cout << endl;
        while (it != NULL)
        {
            cout << "*" << it->piece.num2 << "* ";
            it = it->next;
        }
        cout << endl;
        it = head;
        while (it != NULL)
        {
            cout << "*** ";
            it = it->next;
        }
        cout << "\n\n";
    }
    int selectPiece(char nomePlayer[50])
    {
        int n;
        cout << nomePlayer << " escolha o numero da peca que voce deseja colocar na mesa.\n";
        cin >> n;
        it = head;
        for (int i = 0; i < n; i++)
        {
            it = it->next;
        }
        return n;
    }
    //deveria estar em player, porem player n�o foi feito como classe :(
    int turn(Table *table, Dig *dig, char nomePlayer[50])
    {
        int s;
        table->printTable();
        //se pode jogar alguma peca
        if (ispossible(table))
        {
            table->printTable();
            printHand();
            int n = selectPiece(nomePlayer);
            cout << "Digite 1 para inserir acima ou 2 para inserir abaixo\n";
            cin >> s;
            if (s == 1 && table->push_front(it->piece))
                removeat(n);
            if (s == 2 && table->push_back(it->piece))
                removeat(n);
            turn(table, dig, nomePlayer);
        }
        //se nao pode jogar nenhuma das pecas
        else
        {
            //se ainda pode cavar
            if (dig->size() != 0)
            {
                dig->it = dig->begin();
                push_back(dig->it->piece);
                dig->removeat(0);
                cout << "Cavou!\n";
                system("pause");
                turn(table, dig, nomePlayer);
            }
            //se nao pode cavar
            else
            {
                cout << nomePlayer << " voce perdeu a vez!\n";
                system("pause");
                return 0;
            }
        }
        return 0;
    }
};

typedef struct
{
    char nome[50];
    Hand hand;
} Player;

void createPlayers(int num_players, Dig *dig, Player *player)
{
    for (int counter = 0; counter < num_players; counter++)
    {
        cout << "Player " << counter + 1 << ": ";
        cin >> player[counter].nome;
        player[counter].hand.initializate();
        for (int i = 0; i < 7; i++)
        {
            dig->it = dig->begin();
            player[counter].hand.push_front(dig->it->piece);
            dig->removeat(0);
        }
        player[counter].hand.printHand();
    }
    //vai ter um cava com 14 pecas sorteadas aleatoriamente
}

void drawTitle()
{
    FILE *arq = fopen("title.txt", "r+");
    if (arq == NULL)
        cout << "Erro ao abrir arquivo.\n";
    char c;
    c = fgetc(arq);
    while (c != EOF)
    {
        cout << c;
        c = fgetc(arq);
    }
    fclose(arq);
}