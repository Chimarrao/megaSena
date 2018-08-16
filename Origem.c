#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

//Codigo escrito e rodado no Visual Studio

void baseResult(int elem, int elin) {
	int i, a;
	int base[61], result[61];

	for (i = 0; i < 61; i++) {
		base[i] = i + 1;
	}

	i = 0;
	do {
		a = rand() % 60 + 1;

		if (a + 1 == base[a]) {
			base[a] = 0;
			result[i] = a;
			i++;
		}
	} while (i < elem);


	print(elin, elem, result);
}

int print(int elin, int elem, int *result) {//ponteiro do result sendo passado como parametro
	int acT = elem, acLin, i = 0;//Acumulador total e acumulador da linha
	
	while (i < acT) {
		acLin = elin;
		while (acLin > 0) {
			printf("%02d ", result[i]);
			i++;
			acLin--;
		}
		printf("\n");
	}
}

int main() {
	srand(time(NULL));
	int qt = 1, elin, elem = 1, i;

	do {
		if (qt < 1) {
			printf("Por favor insira um numero maior que 0");
			Sleep(2000);
			system("cls");
		}

		printf("Quantos jogos voce deseja ? ");
		scanf_s("%d", &qt); //Visual Studio não me deixou usar o scanf() comum :/
	} while (qt < 1);

	do {
		if (elem < 1 || elem > 60) {
			printf("Por favor insira um numero entre 1 e 60");
			Sleep(2000);
			system("cls");
		}

		printf("\nCom quantas elementos por jogo ? ");
		scanf_s("%d", &elem);
	} while (elem < 1 || elem > 60);

	printf("\nCom quantas elementos por linhas as matrizes dos jogos serao exibidas ? ");
	scanf_s("%d", &elin);

	printf("\nGerando jogos para mega sena: \n\n");

	for (i = 0; i < qt; i++) {
		baseResult(elem, elin);
		printf("\n\n");
	}

	system("pause");
}
