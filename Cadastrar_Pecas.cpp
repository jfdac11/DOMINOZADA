#include "Variaveis.hpp"
using namespace std;

typedef struct{
	int lado_peca[2];
	
}PECA;

PECA pecas[28];

criar_pecas(){
	
	for(int i = 0; i<4;i++){
		for(int j = 6; j>=0; j--){
			pecas[x].lado_peca[1] = j;
			pecas[x].lado_peca[2] = j;
			cout<<j<<endl;
		}
	}
	
	
	
}
visualisar_pecas(){
		for(int i = 0; i<28;i++){
			cout<<pecas[i].lado_peca[1]<<"|"<<pecas[i].lado_peca[2]<<endl;
			
		}
	 
}
main(){
	criar_pecas();
	visualisar_pecas();
	
	
	
	
	
	
	system("PAUSE");
}
