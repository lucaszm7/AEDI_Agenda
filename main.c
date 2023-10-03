#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Comentário

typedef struct contato {
    char nome[20];
    int numero;
}contato;

void menu(void);
void addContato (void);
void listaContato(void);
void rmContato(void);
void achaContato(void);
void ordenaPonteiros(void); //Ordena os ponteiros depois das funções de add e rm

void insertSort(void);
void selectionSort(void);
void quickSort(void);
//void bubleSort(void);


//Primeiro é o 'ntotal' e por ultimo '(acharNome + 10)', ponteiro 'pessoa' sempre aponta para o final do pBuffer
void *startBuffer;
int *pessoasSizeBuffer; 
int *menuBuffer; 
int *iBuffer;
int *jBuffer;
contato *endBuffer, *aux;
char *startStringBuffer;

//pBuf
//ntotal
//   escolha
//        cont
//            cont2
//           achaNome
//                                 pessoa
//[int|int|int|int|c|c|c|c|c|c|c|c|c|c]
int main () {
    // int buffer - string buffer - pessoas buffer
    startBuffer = malloc(4*sizeof(int)+(10*sizeof(char)));
    pessoasSizeBuffer = startBuffer;
    *pessoasSizeBuffer = 0;
    ordenaPonteiros();
    do {
        menu ();
        scanf("%d",menuBuffer);
        ordenaPonteiros();
        system("cls");
        switch (*menuBuffer) 
        {
            case 1:
                addContato ();
                break;
            case 2:
                rmContato ();
                break;
            case 3:
                listaContato ();
                break;
            case 4:
                achaContato();
                break;
            case 5:
                insertSort();
                break;
            case 6:
                printf("\n----- Saindo do programa! -----\n\n");
                free (startBuffer);
                return 0;
        }
        ordenaPonteiros();
    } while (1);
}

void insertSort() {
	if ((*pessoasSizeBuffer) > 2 ) {
		contato *temp = malloc(sizeof(contato));
	    aux = (contato*)(startStringBuffer + 10);

	    for ((*jBuffer) = 1; (*jBuffer) < (*pessoasSizeBuffer); (*jBuffer)++) {
			strcpy(temp->nome,aux[(*jBuffer)].nome);
			temp->numero = aux[(*jBuffer)].numero;

			for ((*iBuffer) = (*jBuffer) - 1; (*iBuffer) >= 0 && strcmp(temp->nome,aux[(*iBuffer)].nome) < 0; (*iBuffer)--) {
				 strcpy(aux[(*iBuffer) + 1].nome,aux[(*iBuffer)].nome);
				 aux[(*iBuffer) + 1].numero = aux[(*iBuffer)].numero;
			}

			strcpy(aux[(*iBuffer) + 1].nome,temp->nome);
			aux[(*iBuffer) + 1].numero = temp->numero;
		}
        free(temp);
        ordenaPonteiros();
	}
}

void selectionSort () {
    if ((*pessoasSizeBuffer) > 2) {
        contato *temp = malloc(sizeof(contato));
        aux = (contato*)(startStringBuffer + 10);
        for ((*iBuffer) = 0; (*iBuffer) < (*pessoasSizeBuffer) - 1; (*iBuffer)++) {
            for ((*jBuffer) = (*pessoasSizeBuffer) - 1; (*jBuffer) > (*iBuffer); (*jBuffer)--) {
                if (strcmp(aux[(*jBuffer)].nome,aux[(*iBuffer)].nome) < 0) {

                    temp->numero = aux[(*iBuffer)].numero;
                    strcpy(temp->nome,aux[(*iBuffer)].nome);

                    aux[(*iBuffer)].numero = aux[(*jBuffer)].numero;
                    strcpy(aux[(*iBuffer)].nome,aux[(*jBuffer)].nome);

                    strcpy(aux[(*jBuffer)].nome,temp->nome);
                    aux[(*jBuffer)].numero = temp->numero;
                }
            }
        }
        free(temp);
        ordenaPonteiros();
    }
}

void swap(contato **a1,contato **a2, int local) {
    contato *temp = malloc(sizeof(contato));
    temp->numero = aux[(*iBuffer)].numero;
    strcpy(temp->nome,aux[(*iBuffer)].nome);

    aux[(*iBuffer)].numero = aux[(*jBuffer)].numero;
    strcpy(aux[(*iBuffer)].nome,aux[(*jBuffer)].nome);

    strcpy(aux[(*jBuffer)].nome,temp->nome);
    aux[(*jBuffer)].numero = temp->numero;

}

void quickSort() {

}

void ordenaPonteiros () {
    pessoasSizeBuffer = (int*)startBuffer;
    menuBuffer        = (int*)startBuffer  + 1;
    iBuffer           = (int*)startBuffer  + 2;
    jBuffer           = (int*)startBuffer  + 3;
    startStringBuffer = (char*)((int*)startBuffer + 4);
    endBuffer   = (contato*)(startStringBuffer + 10);
    for (*iBuffer = 1; *iBuffer < *pessoasSizeBuffer; (*iBuffer) = (*iBuffer) + 1){
            endBuffer++;
    }
}

void addContato () {
    (*pessoasSizeBuffer)++;
    startBuffer = realloc(startBuffer,(4*sizeof(int)) + (10*sizeof(char)) + ((*pessoasSizeBuffer)*sizeof(contato)));
    ordenaPonteiros ();
    printf("\nNome: ");
    scanf("%s",endBuffer->nome);
    printf("Telefone: ");
    scanf("%d",&endBuffer->numero);
}

void listaContato () {
    if (*pessoasSizeBuffer == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else {
        contato* startPessoasBuffer = (contato*)(startStringBuffer + 10);
        for(*iBuffer = 0; *iBuffer < *pessoasSizeBuffer; (*iBuffer) = (*iBuffer)+1){
            printf("\nNome: %s",startPessoasBuffer->nome);
            printf("\nTelefone: %d\n",startPessoasBuffer->numero);
            startPessoasBuffer++;
        }
    }
}

void rmContato () {
    if (*pessoasSizeBuffer == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else {
        printf("\nDigite o nome do contato que desejas remover: ");
        scanf("%s",startStringBuffer);
        contato* startPessoasBuffer = (contato*)(startStringBuffer + 10);
        for (*iBuffer = 0; *iBuffer < *pessoasSizeBuffer; (*iBuffer) = (*iBuffer)+1){
            if (strcmp(startPessoasBuffer->nome, startStringBuffer) == 0) {
                for (*jBuffer = *iBuffer; *jBuffer < *pessoasSizeBuffer; (*jBuffer) = (*jBuffer) + 1) {
                    aux = startPessoasBuffer + 1;
                    startPessoasBuffer->numero = aux->numero;
                    strcpy (startPessoasBuffer->nome,aux->nome);
                    startPessoasBuffer++;
                }
                (*pessoasSizeBuffer)--;
                startBuffer  = (void*) realloc (startBuffer,4*sizeof(int)+(10*sizeof(char))+(*pessoasSizeBuffer)*sizeof(contato));
                ordenaPonteiros();
                break;
            }
            startPessoasBuffer++;
        }
    }
}

void achaContato () {
    if (*pessoasSizeBuffer == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else {
        printf("Qual o nome do contato que desejas achar? ");
        scanf("%s",startStringBuffer);
        endBuffer = (contato*)(startStringBuffer + 10);
        for (*iBuffer = 0; *iBuffer < *pessoasSizeBuffer; (*iBuffer) = (*iBuffer)+1){
            if (strcmp(endBuffer->nome,startStringBuffer) == 0) {
                printf("\nNome     - %s\n",endBuffer->nome);
                printf("Telefone - %d\n",endBuffer->numero);
            }
            endBuffer = (contato*)endBuffer + 1;
        }
    }
}


void menu (void) {
    printf("\n\n------- MENU ------\n1 - Adicionar Contato\n2 - Remover Contato\n3 - Listar Contatos\n4 - Achar Contato\n5 - Ordenar Contatos\n6 - Sair do Programa\n");
}
