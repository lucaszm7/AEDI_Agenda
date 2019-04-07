#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[20];
    int numero;
}contato;

void menu(void);
void addContato (void);
void listaContato(void);
void rmContato(void);
void ordena(void);

void *pBuffer;
int *ntotal, *escolha, *cont;
contato *pessoa,*aux;

int main () {
    pBuffer = malloc(3*sizeof(int));
    ntotal = pBuffer;
    escolha = ntotal+1;
    cont = escolha+1;
    pessoa = cont+1;
    *ntotal = 0;
    do {
        menu ();
        scanf("%d",escolha);
        getchar;
        switch (*escolha) {
        case 1:
            (*ntotal)++;
            addContato ();
            break;
        case 2:
            rmContato ();
            break;
        case 3:
            listaContato ();
            break;
        default:
            printf("\n----- Saindo do programa! -----\n\n");
            return 0;
        }
    } while (*escolha != 4);
}

void addContato () {
    pBuffer = realloc(pBuffer,(3*sizeof(int)) + ((*ntotal)*sizeof(contato)));
    ntotal = (int*)pBuffer;
    escolha = (int*)ntotal+ 1;
    cont = (int*)escolha+ 1;
    pessoa = (contato*) (cont + 1);
    for (*cont = 1; *cont < *ntotal; (*cont) = (*cont) + 1){
            pessoa++;
    }
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
    pessoa = (int*) cont + 1;
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
    printf("\nDigite o numero do contato que desejas remover: ");
    scanf("%d",escolha);
    aux = pessoa - 1;
    pessoa = (contato*) (cont + 1);
    for ((*cont)=0;(*cont)<=(*ntotal);(*cont)++) {
        if ((*escolha) == pessoa->numero) {
            (*ntotal)--;
            strcpy(pessoa->nome,aux->nome);
            pessoa->numero = aux->numero;
            pBuffer  = (void*) realloc (pBuffer,3*sizeof(int)+(*ntotal)*sizeof(contato));
            ntotal = (int*)pBuffer;
            escolha = (int*)ntotal+ 1;
            cont = (int*)escolha+ 1;
            pessoa = (contato*) (cont + 1);
            for (*cont = 1; *cont < *ntotal; (*cont) = (*cont) + 1){
                    pessoa++;
            }

        }
        pessoa++;
    }
    }
}

/*void rmContato () {
    int *cont2;
    printf("\nDigite o numero do contato que desejas remover: ");
    scanf("%d",escolha);
    for (*cont = 0; *cont < *ntotal; (*cont) = (*cont)+1){
        if (pessoa->numero == escolha) {
                for (*cont2 = cont; *cont2 < *ntotal; (*cont) = (*cont) + 1) {
                    pessoa->numero = (++pessoa)->numero;
                    strcpy (pessoa->nome;(++pessoa)->nome);
                    pessoa = (contato*)pessoa + 1;
                }
        }
    }
}*/

void menu (void) {
    printf("\n\n----- MENU ----\n1 - Adicionar Contato\n2 - Remover Contato\n3 - Listar Contatos\n ");
}
