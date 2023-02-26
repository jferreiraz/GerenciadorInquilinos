/*
O código em questão visa fazer o registro de inquilinos presentes no condomínio.
O condomínio possui 3 blocos divididos em bloco A, bloco B e bloco C.
Cada bloco possui 3 apartamentos.
Cada novo inquilino no condomínio deverá ter seus dados registrados,
primeiro se adiciona o bloco do novo inquilino, depois o apartamento, nome e valor do aluguel.
No menu principal, pode-se realizar o registro de novos inquilinos, assim como consultar os já registrados.
*/

//bibliotecas
#include <string.h>
#include <stdio.h>

//máximo de 3 inquilinos por bloco
#define inquilinos_MAX 3

//estrutura inquilino com os dados que devem ser preenchidos
struct Inquilino {
char apartamento[64];
char nome[64];
float valorAluguel;
};

//objeto
struct Inquilino inquilinos[inquilinos_MAX];

//array para armazenar os dados dos inquilinos
int dadosInquilinos = 0;

//arrays que controlam os blocos dos inquilinos
int blocoA = 0;
int blocoB = 0;
int blocoC = 0;

//função de cadastro dos inquilinos
//recebe X referente ao bloco do novo inquilino
void cadastrarInquilino(int X) {
//averigua qual é o bloco com base no X, 1 = A, 2 = B, 3 = C
if (X == 1) {
//confere se o limite foi atingido		
if (blocoA == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco A, todos os apartamentos ja foram ocupados\n");
return;
} else {
//grava o bloco do novo inquilino	
printf("\nApartamento bloco A\n");
char apartamentoBloco = 'A';
apartamentoBloco = &inquilinos[blocoA].apartamento;
blocoA++;
}
}

if (X == 2) {
//confere se o limite foi atingido	
if (blocoB == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco B, todos os apartamentos ja foram ocupados\n");
return;
} else {	
//grava o bloco do novo inquilino	
printf("\nApartamento bloco B\n");
char apartamentoBloco = 'B';
apartamentoBloco = &inquilinos[blocoB].apartamento;
blocoB++;
}
}

if (X == 3) {
//confere se o limite foi atingido		
if (blocoC == inquilinos_MAX) {
printf("Nao e possivel cadastrar mais inquilinos no bloco C, todos os apartamentos ja foram ocupados\n");
return;
} else {
//grava o bloco do novo inquilino		
printf("\nApartamento bloco C\n");
char apartamentoBloco = 'C';
apartamentoBloco = &inquilinos[blocoC].apartamento;
blocoC++;
}
}
//solicita número do apartamento
printf("Numero do apartamento: ");
scanf("%s", &inquilinos[dadosInquilinos].apartamento);
//solicita nome do inquilino
printf("Nome do inquilino: ");
scanf("%s", &inquilinos[dadosInquilinos].nome);
//solicita valor do aluguel combinado
printf("Valor do aluguel: R$");
scanf("%f", &inquilinos[dadosInquilinos].valorAluguel);

//armazena valores no array e aguarda próximo registro
dadosInquilinos++;
//sai da função
return;
}



//função de escolher apartamentos, em qual bloco ficará o novo inquilino
void escolhaApartamento() {
	
int opcao;

do {
//opções abaixo
printf("\nQual sera o bloco de apartamentos do novo inquilino:\n");
printf("1 - Bloco A\n");
printf("2 - Bloco B\n");
printf("3 - Bloco C\n");
printf("9 - Voltar ao menu principal\n\n");


scanf("%d", &opcao);


switch (opcao) {
//bloco A	
case 1:
cadastrarInquilino(1);
break;
//bloco B
case 2:
cadastrarInquilino(2);
break;
//bloco C
case 3:
cadastrarInquilino(3);
break;
//Voltar ao menu
case 9:
return;
break;
//Tratamento de exceção
default:	
printf("Opcao invalida, escolha novamente\n");
break;
}
} while (opcao != 0); 


}

//Padrão de consulta dos dados dos inquilinos
void consultarInquilino(struct Inquilino dados) {
printf("\nApartamento: %s\n", dados.apartamento);
printf("Nome: %s\n", dados.nome);
printf("Valor do aluguel: %.2f \n", dados.valorAluguel);
}

//Função para imprimir os dados dos inquilinos presentes no array de dados
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

//Função principal de execução
int main() {
	
int opcao;

do {

printf("\nEscolha uma opcao:\n");
printf("1 - Registrar inquilinos\n");
printf("2 - Consultar inquilinos\n");
printf("0 - Deixar o programa\n\n");


scanf("%d", &opcao);

//Opções do menu principal
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
