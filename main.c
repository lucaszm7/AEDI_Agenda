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
void insertSort(void);
void ordena(void); //Ordena os ponteiros depois das funções de add e rm


//Primeiro é o 'ntotal' e por ultimo '(acharNome + 10)', ponteiro 'pessoa' sempre aponta para o final do pBuffer
void *pBuffer;
int *ntotal, *escolha, *cont, *cont2;
contato *pessoa,*aux;
char *achaNome;



int main () {
    pBuffer = malloc(4*sizeof(int)+(10*sizeof(char)));
    ntotal = pBuffer;
    escolha = ntotal+1;
    cont = escolha+1;
    cont2 = cont + 1;
    achaNome = cont2;
    pessoa = (achaNome + 10);
    *ntotal = 0;
    do {
        menu ();
        scanf("%d",escolha);
        system("cls");
        switch (*escolha) {
        case 1:
            (*ntotal)++;
            addContato ();
            break;
        case 2:
            rmContato ();
            break;
        case 3:
			insertSort();
            listaContato ();
            break;
        case 5:
            printf("\n----- Saindo do programa! -----\n\n");
            free (pBuffer);
            return 0;
        case 4:
            achaContato();
        
        }
    } while (1);
}

void insertSort() {
	if ((*ntotal) > 2 ) {
		contato *temp = malloc(sizeof(contato));
	    aux = (achaNome + 10);
	    for ((*cont2) = 1; (*cont2) < (*ntotal); (*cont2)++) {
			strcpy(temp->nome,aux[(*cont2)].nome);
			temp->numero = aux[(*cont2)].numero;
			for ((*cont) = (*cont2) - 1; (*cont) >= 0 && strcmp(temp->nome,aux[(*cont)].nome) < 0; (*cont)--) {
				 strcpy(aux[(*cont) + 1].nome,aux[(*cont)].nome);
				 aux[(*cont) + 1].numero = aux[(*cont)].numero;
			}
			strcpy(aux[(*cont) + 1].nome,temp->nome);
			aux[(*cont) + 1].numero = temp->numero;
		}
	}
}

void ordena () {
    ntotal = (int*)pBuffer;
    escolha = (int*)ntotal+ 1;
    cont = (int*)escolha+ 1;
    cont2 = (int*)cont + 1;
    achaNome = (char*)cont2;
    pessoa = (contato*) (achaNome + 10);
    for (*cont = 1; *cont < *ntotal; (*cont) = (*cont) + 1){
            pessoa++;
    }
}

void addContato () {
    pBuffer = realloc(pBuffer,(4*sizeof(int)) + (10*sizeof(char))+((*ntotal)*sizeof(contato)));
    ordena ();
    printf("\nNome: ");
    scanf("%s",pessoa->nome);
    printf("Telefone: ");
    scanf("%d",&pessoa->numero);
}

void listaContato () {
    if (*ntotal == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else {
        pessoa = (char*) achaNome + 10;
        for(*cont = 0; *cont < *ntotal; (*cont) = (*cont)+1){
            printf("\nNome: %s",pessoa->nome);
            printf("\nTelefone: %d\n",pessoa->numero);
            pessoa = (contato*)pessoa + 1;
        }
    }
}

void rmContato () {
    if (*ntotal == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else { 
        printf("\nDigite o nome do contato que desejas remover: ");
        scanf("%s",achaNome);
        pessoa = (char*)achaNome + 10;
        for (*cont = 0; *cont < *ntotal; (*cont) = (*cont)+1){
            if (strcmp(pessoa->nome,achaNome) == 0) {
                for (*cont2 = *cont; *cont2 < *ntotal; (*cont2) = (*cont2) + 1) {
                    aux = pessoa + 1;
                    pessoa->numero = aux->numero;
                    strcpy (pessoa->nome,aux->nome);
                    pessoa = (contato*)pessoa + 1;
                }
                (*ntotal)--;
                pBuffer  = (void*) realloc (pBuffer,4*sizeof(int)+(10*sizeof(char))+(*ntotal)*sizeof(contato));
                ordena();
            }
            pessoa++;
        }
    }
}

void achaContato () {
    if (*ntotal == 0) {
        printf("\nAinda nao ha contatos adicionados\n");
    }
    else {
        printf("Qual o nome do contato que desejas achar? ");
        scanf("%s",achaNome);
        pessoa = (char*) achaNome + 10;
        for (*cont = 0; *cont < *ntotal; (*cont) = (*cont)+1){
            if (strcmp(pessoa->nome,achaNome) == 0) {
                printf("\nNome     - %s\n",pessoa->nome);
                printf("Telefone - %d\n",pessoa->numero);
            }
            pessoa = (contato*)pessoa + 1;
        }
    }
}


void menu (void) {
    printf("\n\n------- MENU ------\n1 - Adicionar Contato\n2 - Remover Contato\n3 - Listar Contatos\n4 - Achar Contato\n5 - Sair do Programa\n");
}
