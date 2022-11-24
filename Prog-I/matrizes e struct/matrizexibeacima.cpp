#include<stdio.h>
#define TF 4
void leitura(int m[TF][TF]){
     int i,j;
	 for(i=0;i<TF;i++)
	     for (j=0;j<TF;j++){
	     	printf("\nLeitura da matriz[%d][%d]=",i,j);
	     	scanf("%d",&m[i][j]);
		 }	
}
void exibe(int m[TF][TF]){
	int i,j;
	for(i=0;i<TF;i++){
		printf("\n");
		for (j=0;j<TF;j++)
		    printf("  %2d  ",m[i][j]);
	}
}
void exibeacima(int m[TF][TF]){
	int i,j;  
	for(i=0;i<TF;i++){
		printf("\n");
		for(j=0;j<TF;j++)// i menor que j elementos acima diag.principal
		  if (i < j) 
		    printf("  %2d  ",m[i][j]);
		    else printf("      ");
	}     
}
void exibeabaixo(int m[TF][TF]){
    int i,j;
	for(i=0;i<TF;i++){
		printf("\n");
		for(j=0;j<TF;j++)// i maior que j elementos abaixo diag.principal
		  if (i > j) 
		    printf("  %2d  ",m[i][j]);
	}     
}
main(){
	int opcao=0;
	int matriz[TF][TF];
	//
	while (opcao!=5){
		printf("\n1- Leitura da matriz %d x %d",TF,TF);
		printf("\n2- Exibe matriz %d x %d",TF,TF);
		printf("\n3- Exibe elementos acima da diagonal principal");
		printf("\n4- Exibe elementos abaixo da diag.principal");
		printf("\n5- sair");
		printf("\nOpcao?");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: leitura(matriz); break;
			case 2: exibe(matriz); break;
			case 3: exibeacima(matriz);break;
			case 4: exibeabaixo(matriz);break;
		}
	}
}
