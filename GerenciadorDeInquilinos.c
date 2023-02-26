#include <string.h>
#include <stdio.h>
#define inquilinos_MAX 3

struct Inquilino {
char apartamento[64];
char nome[64];
float valorAluguel;
};

struct Inquilino inquilinos[inquilinos_MAX];

int dadosInquilinos = 0;

int blocoA = 0;
int blocoB = 0;
int blocoC = 0;


void cadastrarInquilino(int X) {

if (X == 1) {
		
if (blocoA == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco A, todos os apartamentos ja foram ocupados\n");
return;
} else {

	
printf("\nApartamento bloco A\n");
char apartamentoBloco = 'A';
apartamentoBloco = &inquilinos[blocoA].apartamento;
blocoA++;
}
}

if (X == 2) {

if (blocoB == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco B, todos os apartamentos ja foram ocupados\n");
return;
} else {	
	
printf("\nApartamento bloco B\n");
char apartamentoBloco = 'B';
apartamentoBloco = &inquilinos[blocoB].apartamento;
blocoB++;
}
}

if (X == 3) {
	
if (blocoC == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco C, todos os apartamentos ja foram ocupados\n");
return;
} else {
	
printf("\nApartamento bloco C\n");
char apartamentoBloco = 'C';
apartamentoBloco = &inquilinos[blocoC].apartamento;
blocoC++;
}
}

printf("Numero do apartamento: ");
scanf("%s", &inquilinos[dadosInquilinos].apartamento);

printf("Nome do inquilino: ");
scanf("%s", &inquilinos[dadosInquilinos].nome);

printf("Valor do aluguel: R$");
scanf("%f", &inquilinos[dadosInquilinos].valorAluguel);


dadosInquilinos++;

return;
}




void escolhaApartamento() {
	
int opcao;

do {

printf("\nQual sera o bloco de apartamentos do novo inquilino:\n");
printf("1 - Bloco A\n");
printf("2 - Bloco B\n");
printf("3 - Bloco C\n");
printf("9 - Voltar ao menu principal\n\n");


scanf("%d", &opcao);


switch (opcao) {
	
case 1:
cadastrarInquilino(1);
break;

case 2:
cadastrarInquilino(2);
break;

case 3:
cadastrarInquilino(3);
break;

case 9:
return;
break;

default:
	
printf("Opcao invalida, escolha novamente\n");
break;
}
} while (opcao != 0); 


}






void consultarInquilino(struct Inquilino dados) {
printf("\nApartamento: %s\n", dados.apartamento);
printf("Nome: %s\n", dados.nome);
printf("Valor do aluguel: %.2f \n", dados.valorAluguel);
}





void consultarInquilinos() {

if (dadosInquilinos == 0) {
printf("Todos os apartamentos estao vazios!\n");
return;
}


int i;
for (i = 0; i < blocoA; i++) {
printf("\n------------\nBloco A: inquilino %d\n", i + 1);
consultarInquilino(inquilinos[i]);
}


for (i = 0; i < blocoB; i++) {
printf("\n------------\nBloco B: inquilino %d\n", i + 1);
consultarInquilino(inquilinos[i]);
}


for (i = 0; i < blocoC; i++) {
printf("\n------------\nBloco C: inquilino %d\n", i + 1);
consultarInquilino(inquilinos[i]);
}

}








int main() {
	
int opcao;

do {

printf("\nEscolha uma opcao:\n");
printf("1 - Registrar inquilinos\n");
printf("2 - Consultar inquilinos\n");
printf("0 - Deixar o programa\n\n");


scanf("%d", &opcao);


switch (opcao) {
	
case 1:
escolhaApartamento();
break;

case 2:
consultarInquilinos();
break;

case 3:
break;

case 0:
printf("Saindo do programa...\n");
break;

default:
	
printf("Opcao invalida, escolha novamente\n");
break;
}
} while (opcao != 0); 

return 0;
}
