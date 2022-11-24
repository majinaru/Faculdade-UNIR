#include<stdio.h>
#include<string.h>
#include<conio.h>
#define TF 10
struct cliente{	
	int num_conta;
	char tipo_conta;
	char nome[20];
	float limite;
	float saldo;
};

void insere(struct cliente banco[TF], int &tl){  
		banco[0].num_conta=110;
		banco[0].tipo_conta='c';
		strcpy(banco[0].nome, "Joao Henrique");
		banco[0].limite=0;
		banco[0].saldo=1500.43;
		
		banco[1].num_conta=220;
		banco[1].tipo_conta='e';
		strcpy(banco[1].nome, "Carlota Joaquina");
		banco[1].limite=1000.00;
		banco[1].saldo=8500.75;
		//
		banco[2].num_conta=330;
		banco[2].tipo_conta='c';
		strcpy(banco[2].nome, "Marcelo Pereira");
		banco[2].limite=0;
		banco[2].saldo=780.90;
		
		/* TODO (#1#): 
		tl=3;
		printf("\n\n3 Clientes inseridos com sucesso\n\n");
}


void exibe(struct cliente banco[TF], int tl){
		
		int i;
		printf("\n-----------------------------------------------------------------------------------\n");
		for(i=0;i<tl;i++){
			printf("\nnome:%s\nnum:%d\ntipo:%c\nlimite:%5.2f\nsaldo:%5.2f\n", banco[i].nome, banco[i].num_conta, banco[i].tipo_conta, banco[i].limite, banco[i].saldo);
	}
	printf("\n-----------------------------------------------------------------------------------\n");		
}

int busca(struct cliente banco[TF], int tl, int numconta){
		
		int i, posicao=-1;
		for(i=0;i<tl;i++){
			if (numconta == banco[i].num_conta)
				posicao = i; 
		}
		return posicao;
}

main(){
	
		struct cliente banco[TF];
		struct cliente c;
		int tl=0;
		int opcao;  
		int numconta, posicao;
		float valor;
		opcao=0;
		while(opcao!=7){
		
			printf("\n 1 - Carrega 3 clientes fixos");
			printf("\n 2 - Exibe todos os clientes do banco");
			printf("\n 3 - Busca um cliente pelo num da conta e exibir saldo");
			printf("\n 4 - Fazer um deposito");
			printf("\n 5 - Fazer um saque de uma determinada conta");
			printf("\n 6 - Inserir um novo cliente no final do vetor");
			printf("\n 7 - Sair");
			printf("\n Opcao: ");
			scanf("%d", &opcao);
			
			switch(opcao){
				
				case 1: insere(banco,tl);
						break;
				///*		
				case 2: exibe(banco,tl);
						break;
				
				case 3: printf("\n Qual num de conta quer consultar?");
						 scanf("%d", &numconta);
						posicao = busca(banco,tl,numconta);
						if (posicao ==-1)
							printf("\n Nao encontrou a conta");
						else
							printf("\n Nro conta %d, nome %s, saldo %5.2f", banco[posicao].num_conta, banco[posicao].nome, banco[posicao].saldo);						
						break;
						
				case 4: printf("\n Qual nro conta quer depositar?");
						 scanf("%d", &numconta);
						posicao = busca(banco,tl,numconta);
						if (posicao == -1)
							printf("\n Conta nao existe");
						else{
							printf("\n Qual o valor a ser depositado?");
							 scanf("%f",&valor);
							banco[posicao].saldo += valor;
							printf("\n Deposito realizado nome %s, conta %d, novo saldo %5.2f", banco[posicao].nome, banco[posicao].num_conta, banco[posicao].saldo); 
							}
						break;
						
				case 5: printf("\n Qual nro conta quer fazer saque?");
						 scanf("%d", &numconta);
						posicao = busca (banco,tl,numconta);
						if (posicao == -1)
							printf("\n Nao encontrou a conta");
						else{							
							printf("\n Qual o valor do saque?");
							 scanf("%f", &valor);
							if ((banco[posicao].tipo_conta =='c')&&(banco[posicao].saldo >= valor)){
								printf("\n Saque Realizado");
						    	banco[posicao].saldo -= valor;
							    printf("\n Nome %s, novo saldo %5.2f", banco[posicao].nome, banco[posicao].saldo);
							}
							if ((banco[posicao].tipo_conta == 'e')&&(
							     banco[posicao].saldo + banco[posicao].limite >= valor)){
						     	banco[posicao].saldo -= valor;
							    printf("\n Saque Realizado, Nome %s, Novo Saldo %5.2f",
								       banco[posicao].nome, banco[posicao].saldo);
					    	}					
						break;
						
				case 6: if(tl+1<TF){
							printf("\n Numero conta: ");
							 scanf("%d",&c.num_conta);
							printf("\n Entre tipo conta (E/C): ");
							c.tipo_conta=getche();
							if (c.tipo_conta == 'C')
								c.limite = 0;
								else{
								printf("\n Limite?");
								scanf("%f",&c.limite);
								}
							printf("\n Entre com o nome: ");
							scanf("%s",&c.nome);
							printf("\n Entre com o saldo");
							scanf("%f",&c.saldo);
							banco[tl] = c;
						    tl++;
						}
						else
							printf("\n SEM ESPACO NO VETOR");
						break;
				}
			}
		}
	}			

