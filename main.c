#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[20];
    int numero;
}contato;


void menu(void);
void addContato (void);
void mostraContatos(void);
void rmContato(void);
void ordena(void);

contato *pessoa;
void *buffer;
int *ntotal,*escolha;
int *acontador,*bcontador;

int main(){
   buffer = (void*) malloc (4*sizeof(int));
   acontador = buffer;
   bcontador = acontador+1;
   ntotal = bcontador+1;
   escolha = ntotal +1;
   pessoa = escolha+1;
   *ntotal = 0;
    while(1){
        menu();
        scanf("%d",escolha);
        getchar();
        if     (*escolha==1) addContato();
        else if(*escolha==2) rmContato();
        else if(*escolha==3) mostraContatos();
        else return 0;
   }
}

/*void ordena () {
    acontador = buffer;
    bcontador = acontador+1;
    ntotal = bcontador+1;
    escolha = ntotal +1;
    pessoa = escolha + 1;
    //if(*ntotal != 1) {
    for ((*acontador) = 0;(*acontador) < (*ntotal); *acontador = (*acontador) + 1) pessoa++;
    //}
}*/

void menu (void) {
    printf("\n\n----- MENU ----\n1 - Adicionar Contato\n2 - Remover Contato\n3 - Listar Contatos\n ");
}


void addContato(void){
    *ntotal=*ntotal+1;
    buffer  = (void*) realloc (buffer,4*sizeof(int)+(*ntotal)*sizeof(contato));
    printf("\nNome: ");
    scanf("%[^\n]",pessoa->nome);
    printf("Telefone: ");
    scanf("%d",&pessoa->numero);
    pessoa++;
    //ordena();
    //if (*ntotal == 1) {
    //buffer  = (void*) realloc (buffer,4*sizeof(int));
    //ordena();
    //addContato();
    //}
}
void rmContato (void) {
    char remover[20];
    contato *aux;
    printf("\nQual Contato desejas removar: ");
    scanf("%[^\n]",remover);
    aux = pessoa - 1;
    pessoa = escolha + 1;
    for ((*acontador)=0;(*acontador)<=(*ntotal);(*acontador)++) {
        printf("\nNome pessoa - %s\nNome Aux - %s\n",pessoa->nome,aux->nome);
        if (strcmp(pessoa->nome,remover) == 0) {
            printf("\nNome pessoa - %s\nNome Aux - %s\n",pessoa->nome,aux->nome);
            strcpy(pessoa->nome,aux->nome);
            pessoa->numero = aux->numero;
            (*ntotal)--;
            printf("\nntotal - %d",*ntotal);
            buffer  = (void*) realloc (buffer,4*sizeof(int)+(*ntotal)*sizeof(contato));
        }
        pessoa++;
    }
    //ordena();
}

void mostraContatos(void) {
	if ((*ntotal) == 0) printf("\nNao ha nenhum contato ainda\n");
	else {
		pessoa = escolha + 1;
	    for ((*acontador) = 0;(*acontador) < (*ntotal); *acontador = (*acontador) + 1) {
	    	printf("\nNome - %s\n",pessoa->nome);
	    	printf("Numero - %d\n\n",pessoa->numero);
	    	pessoa++;
	    }
	}
}
