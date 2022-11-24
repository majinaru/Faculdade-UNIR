#include <stdio.h>
#define TF 5
void leitura(int vetor[TF])
{
	int i;
	for (i = 0; i < TF; i++)
	{
		printf("\nEntre com valor da posicao %d=", i);
		scanf("%d", &vetor[i]);
	}
}
void exibe(int vetor[TF])
{
	int i;
	for (i = 0; i < TF; i++)
		printf("\nvetor[%d]=%d", i, vetor[i]);
}
int busca(int vetor[TF], int numero)
{
	int posicao = -1;
	int i;
	for (i = 0; i < TF; i++)
	{
		if (numero == vetor[i])
			posicao = i;
	}
	return posicao;

	void
}
main()
{
	int opcao = 0;
	int vetA[TF], vetB[TF], vetC[TF];
	int tl = 0;
	while (opcao != 7)
	{
		printf("\n1 - Leitura do vetor A");
		printf("\n2 - Exibe o vetor A");
		printf("\n3 - Leitura do vetor B");
		printf("\n4 - Exibe o vetor B");
		printf("\n5 - Interseccao dos vetores - Vetor C");
		printf("\n6 - Uniao SEM repeticao");
		printf("\n7 - Sair");
		printf("\nOpcao?");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			printf("\nLeitura do Vetor A");
			leitura(vetA);
			break;
		case 3:
			printf("\nLeitura do Vetor B");
			leitura(vetB);
			break;
		case 2:
			printf("\nExibe o vetor A");
			exibe(vetA);
			break;
		case 4:
			printf("\nExibe o vetor B");
			exibe(vetB);
			break;
		case 5:
			printf("\nIntersecao dos vetores A e B");
			int numero, posicao;
			int tl = 0;
			for (int i = 0; i < TF; i++)
			{
				numero = vetA[i];
				posicao = busca(vetB, numero);
				if (posicao != -1)
				{
					printf("\nEncontrei o numero %d no vetor B", numero);
					tl++;
				}
			}
			printf("\n Qtdade de numeros da interseccao = %d", tl);
			break;
		}
	}
}
