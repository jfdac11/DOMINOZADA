#include "Global.hpp"

typedef struct{
	char Nome[50];
}Player;

Player player[4];

int CadastrarJogadores(int i){
	if(i == 2){
		for(int N = 1; N <= i; N++){
			cout<<"Player "<<N<<": ";
			cin>>player[N].Nome;
		}
		return 1;
		//vai ter um cava com 14 pecas sorteadas aleatoriamente
	}
	else if(i == 4){
		for(int N= 1; N <= i; N++){
			cout<<"Player "<<N<<": ";
			cin>>player[N].Nome;
		}
		return 2;
		//nao vai ter cava
	}
}

VisualizarPlayers(int num_jogadores){
	for(int N=1; N <= num_jogadores; N++){
		cout<<"Player "<<N<<", Nome:"<<player[N].Nome<<endl;			
	}
}
