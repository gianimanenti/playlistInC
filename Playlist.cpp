#include<stdio.h>							   
#include<stdlib.h>

int menu();
void InserirInicio(int id, char nomeMusica[], char artista[], int duracaoFaixa);
void InserirFim(int id, char nomeMusica[], char artista[], int duracaoFaixa);
void InserirMeio(int id, char nomeMusica[], char artista[], int duracaoFaixa, int posicao);
int Remover(int id);
void Listar();

struct ElementoDaLista_Simples {
	int id;
	char* nomeMusica;
	char* artista;
	int duracaoFaixa;
	struct ElementoDaLista_Simples *prox;
} *Head;

int  main() {
	int op, id = 0, duracaoFaixa, num, pos, c;
	char nomeMusica[20], artista[20];
	Head = NULL;

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o nome da Musica: ");
			scanf("%s", &nomeMusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome do Artista: ");
			scanf("%s", &artista);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a duracao da Faixa: ");
			scanf("%d", &duracaoFaixa);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			id = id +1;
			InserirInicio(id, nomeMusica, artista, duracaoFaixa);
			break;
		case 2:
			printf("Digite o nome da Musica: ");
			scanf("%s", &nomeMusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome do Artista: ");
			scanf("%s", &artista);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a duracao da Faixa: ");
			scanf("%d", &duracaoFaixa);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			id = id +1;
			InserirFim(id, nomeMusica, artista, duracaoFaixa);
			break;
		case 3:
			printf("Digite o nome da Musica: ");
			scanf("%s", &nomeMusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome do Artista: ");
			scanf("%s", &artista);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a duracao da Faixa: ");
			scanf("%d", &duracaoFaixa);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a posicao que deseja inserir: ");
			scanf("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			id = id +1;
			InserirMeio(id, nomeMusica, artista, duracaoFaixa, pos);
			break;
		case 4:
			int res;
			printf("Digite o id da faixa a ser removida: ");
			scanf("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(id);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 5:
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");
	system("COLOR 0A");

	printf("1.Inserir no inicio da lista encadeada simples\n");
	printf("2.Inserir no fim da lista encadeada simples\n");
	printf("3.Inserir no meio da lista encadeada simples\n");
	printf("4.Remover da lista encadeada simples\n");
	printf("5.Listar a lista encadeada simples\n");
	printf("6.Sair\n");
	printf("Digite sua escolha: ");

	scanf("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
	
	system("Cls");
	return op;
}

void InserirInicio(int id, char nomeMusica[], char artista[], int duracaoFaixa)
{
	ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	
	NovoElemento->nomeMusica = nomeMusica;
	NovoElemento->duracaoFaixa = duracaoFaixa;
	NovoElemento->artista = artista;
	NovoElemento->id = id;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void InserirFim(int id, char nomeMusica[], char artista[], int duracaoFaixa)
{
	ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->nomeMusica = nomeMusica;
	NovoElemento->duracaoFaixa = duracaoFaixa;
	NovoElemento->artista = artista;
	NovoElemento->id = id;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}

void InserirMeio(int id, char nomeMusica[], char artista[], int duracaoFaixa, int posicao)
{
	ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->nomeMusica = nomeMusica;
	NovoElemento->duracaoFaixa = duracaoFaixa;
	NovoElemento->artista = artista;
	NovoElemento->id = id;

	if (posicao == 0)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}

int Remover(int id)
{
	ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *Anterior;
	Anterior = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->id == id) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox ;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

void Listar()
{
	ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	printf("***** Musicas na sua lista! ****** \n\n");
	while (ElementoVarredura != NULL) {
		printf("ID da faixa: %d \n\n", ElementoVarredura->id);
		printf("Nome da musica: %s \n\n", ElementoVarredura->nomeMusica);
		printf("Duracao da faixa: %d min \n\n", ElementoVarredura->duracaoFaixa);
		printf("Artista: %s \n\n", ElementoVarredura->artista);
		ElementoVarredura = ElementoVarredura->prox;
	printf("*************************** \n\n");
	}
	printf("\n");

	system("pause");
	return;
}
