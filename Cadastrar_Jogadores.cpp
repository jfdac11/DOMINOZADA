#include <iostream>
#include <cstdlib>

using namespace std;

unsigned int numero_jogadores;

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
		//vai ter um cava com 14 peças sorteadas aleatoriamente
	}
	else if(i == 4){
		for(int N= 1; N <= i; N++){
			cout<<"Player "<<N<<": ";
			cin>>player[N].Nome;
				
		}
		return 2;
		//não vai ter cava
	}
		
}


VisualizarPlayers(){
	for(int N=1; N <= 4; N++){
			cout<<"Player "<<N<<", Nome:"<<player[N].Nome<<endl;
				
		}
	
}
main(){
 	
 	cout<<"Bem vindo a o DOMINO BRABO\n";
 	system("PAUSE");
 	
 	while(true){
 		cout<<"\nEscolha o numero de jogadores! \n";
 		cout<<"2 jogadores ou 4 jogadores?"<<endl;
 		cin >> numero_jogadores;
 		
 		if(numero_jogadores == 2 || numero_jogadores == 4){
 			CadastrarJogadores(numero_jogadores);
			break;	
		}else{
			cout<<"\nNUMERO ERRADO"<<endl;
		}
		
	}
	cout<<"\n\n";
	VisualizarPlayers();
 	
 	system("pause");
}
