#include <stdio.h>
#include <stdlib.h>
typedef struct contato {
    int numero;
    char nome[20];
}contato;


void *buffer;
int *ntotal,*escolha;
int *acontador,*bcontador;
contato *pessoa;

void menu(void);
void addContato (void);
void mostraContatos(void);


int main(int argc, char **argv) {
	buffer = malloc(4*sizeof(int));
	ntotal = buffer;
	*ntotal = 0;
	escolha = ntotal + 1;
	*escolha = 0;
	acontador = escolha + 1;
	*acontador = 0;
	bcontador = acontador + 1;
	*bcontador = 0;
	pessoa = bcontador + 1;
	while (*escolha != 4) {
    	menu();
	    scanf("%d",escolha);
	    getchar();
	    if (*escolha == 1) addContato ();
	    else if (*escolha == 2) ;
	    else if (*escolha == 3) mostraContatos();
	}
	return 0;
}



void menu (void) {
    printf("\n\n----- MENU ----\n1 - Adicionar Contato\n//2 - Remover Contato\n3 - Listar Contatos");
}

void addContato (void) {
	    (*ntotal)++;
	    printf("ntotal - %d\n", *ntotal);
		buffer = realloc (buffer,4*sizeof(int) + (*ntotal)*sizeof(contato));
		printf("Nome: ");
        scanf("%[^\n]",pessoa->nome);
        printf("Telefone: ");
        scanf("%d",&pessoa->numero);
        pessoa++;
}

//void rmContato (void *buffer)

void mostraContatos(void) {
	if ((*ntotal) == 0) printf("\nNão há nenhum contato ainda\n");
	else {
		pessoa = bcontador + 1;
	    for ((*acontador) = 0;(*acontador) < (*ntotal); (*acontador)++) {
		    printf("\nacontador - %d\n", *acontador);
	    	printf("Nome - %s\n",pessoa->nome);
	    	printf("Numero - %d\n\n",pessoa->numero);
	    	pessoa++;
	    }
	}
}
