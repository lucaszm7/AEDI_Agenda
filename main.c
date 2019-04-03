#include <stdio.h>
#include <stdlib.h>
typedef struct contato {
    int numero;
    char nome[20];
}contato;

int *ntotal,*escolha;
int *acontador,*bcontador;

int main(int argc, char **argv) {
	void *buffer = malloc(4*sizeof(int));
	ntotal = buffer;
	*total = 0;
	escolha = ntotal + 1;
	*escolha = 0;
	acontador = escolha + 1;
	*acontador = 0;
	bcontador = acontador + 1;
	*bcontador = 0;
	while (*escolha == 4) {
    	menu();
	    scanf("%d",escolha);
	    getchar();
	    if (*escolha == 1) buffer = addContato (buffer);
	    else if (*escolha == 2) ;
	    else if (*escolha == 3) mostraContatos(buffer,ntotal);
	}
	return 0;
}



void menu () {
    printf("----- MENU ----\n1 - Adicionar Contato\n2 - Remover Contato\n")
}

void *addContato (void *buffer) {
	void *aux;
	aux = bcontador + 1;
	if((*ntotal == 0) {
		
	}
	else {
		printf("ENTRO AQUI K7\n");
		buffer = realloc(buffer,(*ntotal)*(sizeof(int)+sizeof(char)));
		for(aux = buffer;count < *ntotal;count++) {
			(int*)aux++;
			printf("\n%d\n",count);
			(char*)aux++;
		}
		*(int*)aux = 10;
		(int*)aux++;
		*(char*)aux = 'b';
		return buffer;
	}
}

//void rmContato (void *buffer)

void mostraContatos(void *buffer,int ntotal) {
	if (ntotal == 0) return;
	int i=1;
	for (;i <= ntotal;i++) {
		printf("Numero - %d\n",*(int*)buffer);
		*(int*)buffer++;
		printf("Nome   - %c\n\n",*(char*)buffer);
		*(char*)buffer++;
	}
}
