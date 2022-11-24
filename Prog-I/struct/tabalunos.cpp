#include<stdio.h>
#include<string.h>
#include<conio.h>
#define TF 10
struct aluno{
	int matricula;
	char nome[15];
	int anoingresso;
	float nota1,nota2,nota3;
	int frequencia;
};
void carrega (struct aluno tabela[TF],int &tl){
	tabela[0].matricula= 1111;
	strcpy(tabela[0].nome, "Pedro Oliveira");
	tabela[0].anoingresso= 2020;
	tabela[0].nota1= 7.0;
	tabela[0].nota2= 5.0;
	tabela[0].nota3= 9.5;
	tabela[0].frequencia= 80;
	//
	tabela[1].matricula= 2222;
	strcpy(tabela[1].nome, "Maria Carolina");
	tabela[1].anoingresso= 2021;
	tabela[1].nota1= 8.0;
	tabela[1].nota2= 10.0;
	tabela[1].nota3= 9.0;
	tabela[1].frequencia= 55;
	//
	tabela[2].matricula= 3333;
	strcpy(tabela[2].nome, "Vilma Pereira");
	tabela[2].anoingresso= 2019;
	tabela[2].nota1= 6.0;
	tabela[2].nota2= 7.0;
	tabela[2].nota3= 5.0;
	tabela[2].frequencia= 90;
	//
	tl= 3;
}
void exibe(struct aluno tabela[TF], int tl){
	int i;
	float media;

	for (i=0; i<tl; i++){
		media= (tabela[i].nota1+tabela[i].nota2+tabela[i].nota3)/3;
		printf("\ni= %d nome= %s matr= %d media= %5.2f freq= %d",
		i,tabela[i].nome, tabela[i].matricula, media, tabela[i].frequencia);
	}
	printf("\n");
}
void exibeaprovados(struct aluno tabela[TF],int tl){
	int i;
	float media;

	for (i=0; i<tl; i++){
		media= (tabela[i].nota1+tabela[i].nota2+tabela[i].nota3)/3;
		if ((media >= 6.0)&&(tabela[i].frequencia >= 75))
			printf("\nnome= %s status= aprovado",
			tabela[i].nome);
			
	}
	printf("\n");
}
void exibereprovados(struct aluno tabela[TF],int tl){
	int i;
	float media;

	for (i=0; i<tl; i++){
		media= (tabela[i].nota1+tabela[i].nota2+tabela[i].nota3)/3;
		if ((media < 6.0)||(tabela[i].frequencia < 75))
			printf("\nnome= %s status= reprovado",
			tabela[i].nome);
			
	}
	printf("\n");
}
void insere(struct aluno tabela[TF], int &tl){
	if (tl < TF){
		printf("Matricula: ");
		scanf("%d",&tabela[tl].matricula);
		printf("Nome: ");
		scanf("%s",&tabela[tl].nome);
		printf("Ano de ingresso: ");
		scanf("%d",&tabela[tl].anoingresso);
		printf("Nota1: ");	
		scanf("%f", &tabela[tl].nota1);
		printf("Nota2: ");
		scanf("%f", &tabela[tl].nota2);
		printf("Nota3: ");
		scanf("%f", &tabela[tl].nota3);
		printf("Frequencia: ");
		scanf("%d", &tabela[tl].frequencia);
		//
		tl++;
	}
	else 
		printf("Tabela lotada");
}
int busca(struct aluno tabela[TF],int tl, int matricula){
	int posicao = -1;
	int i;
	for (i=0; i<tl; i++){
		if (tabela[i].matricula== matricula)
			posicao= i;
	}
	return posicao;
}
main(){
	struct aluno tabela[TF];
	int tl=0;
	int opcao=0;
	bool situacao[TF];
	while(opcao!=7){
		printf("\n1- Carrega 3 alunos");
		printf("\n2- Exibe todos os alunos");
		printf("\n3- Exibe os alunos aprovados");
		printf("\n4- Exibe os alunos reprovados ");
		printf("\n5- Insere um novo aluno no final da tabela");
		printf("\n6- Alterar nota");
		printf("\n7- Sair");
		printf("\nOpcao? ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				carrega(tabela, tl);
				break;
			case 2:
				exibe (tabela,tl);
				break;
			case 3:
				exibeaprovados(tabela,tl);
				break;
			case 4:
				exibereprovados(tabela,tl);
				break;
			case 5:
				insere(tabela,tl);
				break;
			case 6:
				int matricula,posicao;
				printf("\nQual a matricula do aluno procurado? ");
				scanf("%d",&matricula);
				posicao = busca(tabela,tl,matricula);
				if (posicao == -1)
					printf("Aluno nao encontrado");
				else{
							printf("\ni= %d nome= %s matr= %d nota3= %5.2f freq= %d",
							posicao,tabela[posicao].nome, matricula, tabela[posicao].nota3, tabela[posicao].frequencia);
							tabela[posicao].nota3++;
							printf("\ni= %d nome= %s matr= %d NEW nota3= %5.2f freq= %d",
							posicao,tabela[posicao].nome, matricula, tabela[posicao].nota3, tabela[posicao].frequencia);
							printf("\n");
				}
				break;
		}
	}
}
