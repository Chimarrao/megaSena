#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

void baseResult(int elin, int elem) {

	srand(time(NULL));

	int i, a;
	int base[9999], result[9999];

	for (i = 0; i < 60; i++) {
		base[i] = i + 1;
	}

	i = 0;
	do {
		a = rand() % 60 + 1;

		if (a + 1 == base[a]) {
			base[a + 1] = 0;
			result[i] = a;
			i++;
		}
	} while (i < elem);

	print(elin, elem, result);
}

int print(int elin, int elem, int *result) {//ponteiro do result sendo passado como parametro
	int acT = elem, acLin, i = 0;
	
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
	int qt = 1, elin, elem, i;

	do {
		if (qt < 1) {
			printf("Por favor insira um numero maior que 0");
			Sleep(2000);
		}

		system("cls");

		printf("Quantos jogos voce deseja ? ");
		scanf_s("%d", &qt); //Visual Studio não me deixou usar o scanf() comum :/
	} while (qt < 1);

	printf("\nCom quantas elementos por jogo ? ");
	scanf_s("%d", &elem);

	printf("\nCom quantas elementos por linhas as matrizes dos jogos serao exibidas ? ");
	scanf_s("%d", &elin);

	printf("\nGerando jogos para mega sena: \n\n");

	for (i = 0; i < qt; i++) {
		baseResult(elin, elem);
		printf("\n\n");
	}

	system("pause");
}