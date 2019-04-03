#include <stdio.h>
#include <stdlib.h>
typedef struct contato {
    int numero;
    char nome[20];
}contato;

int *ntotal,*escolha;
int *acontador,*bcontador;
contato *pessoa;

void menu(void);
void *addContato (void *buffer);
void mostraContatos(void *buffer);


int main(int argc, char **argv) {
	void *buffer = malloc(4*sizeof(int));
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
	    if (*escolha == 1) buffer = addContato (buffer);
	    else if (*escolha == 2) ;
	    else if (*escolha == 3) mostraContatos(buffer);
	}
	return 0;
}



void menu (void) {
    printf("----- MENU ----\n1 - Adicionar Contato\n2 - Remover Contato\n");
}

void *addContato (void *buffer) {
	    *ntotal = *ntotal + 1;
		buffer = realloc (buffer,4*sizeof(int) + (*ntotal)*sizeof(contato));
		printf("Nome: ");
        scanf("%[^\n]",pessoa->nome);
        printf("Telefone: ");
        scanf("%d",&pessoa->numero);
        return buffer;
	}

//void rmContato (void *buffer)

void mostraContatos(void *buffer) {
	if (ntotal == 0) return;
	int i=1;
	for (;i <= ntotal;i++) {
		printf("Numero - %d\n",*(int*)buffer);
		*(int*)buffer++;
		printf("Nome   - %c\n\n",*(char*)buffer);
		*(char*)buffer++;
	}
}
