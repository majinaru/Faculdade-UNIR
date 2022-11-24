#include<stdio.h>
#include<string.h>
#define TF 10
struct tptempo{
	int hora;
	int minuto;
	int segundo;
};
struct tpdata{
	int dia;
	int mes;
	int ano;
};
struct compromisso{
	char descricao[20];
	struct tptempo horario;
	struct tpdata data;
};
void carrega (struct compromisso agenda[TF], int &tl){
	struct compromisso c1,c2;
	strcpy(c1.descricao,"consulta dentista");
	c1.data.dia = 23;
	c1.data.mes = 11;
	c1.data.ano = 2022;
	c1.horario.hora=15;
	c1.horario.minuto=30;
	c1.horario.segundo=0;
	agenda[0]= c1;
	//
	strcpy(c2.descricao,"reuniao motorola");
	c2.horario.hora=9;
	c2.horario.minuto=10;
	c2.horario.segundo=0;
	c2.data.dia=16;
	c2.data.mes=11;
	c2.data.ano=2022;
	agenda[1]= c2;
	//
	tl=2;
}
void exibe(struct compromisso agenda[TF], int tl){
	int i;
	for (i=0;i<tl;i++)
	   printf("\nDescricao=%s  DATA %d/%d/%d  Horario %d:%d:%d",
	   	    agenda[i].descricao,
	    agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano,
	    agenda[i].horario.hora,agenda[i].horario.minuto,
		agenda[i].horario.segundo);
}
main(){
	struct compromisso agenda[TF];
	int tl=0;
	int opcao=0;
	while (opcao!=3){
		printf("\n1 - carrega 2 compromissos");
		printf("\n2 - exibe os compromissos");
		printf("\n3 - sair");
		printf("\nOpcao?");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: carrega(agenda,tl);
			        break;
			case 2: exibe(agenda,tl);
			        break;        
		}
	}
}
