#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato {
    char nome[20];
    int numero;
} contato;

void menu(void);
void addContato (void);
void listaContato(void);
void rmContato(void);
void achaContato(void);
void ordenaPonteiros(void); //Ordena os ponteiros depois das funções de add e rm

void encherLista(void);
void ordernarContatos(void);

void insertionSort(void);
void selectionSort(void);
void quickSort(contato* list, int lo, int hi);
void bubbleSort(void);
void swap(contato *a1,contato *a2);

//Primeiro é o 'ntotal' e por ultimo '(acharNome + 10)', ponteiro 'pessoa' sempre aponta para o final do pBuffer
void *startBuffer;
int *pessoasSizeBuffer; 
int *menuBuffer;
int *iBuffer;
int *jBuffer;
contato *endBuffer, *aux;
contato *startList;
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
                ordernarContatos();
                break;
            case 6:
                encherLista();
                break;
            case 0:
                printf("\n----- Saindo do programa! -----\n\n");
                free (startBuffer);
                return 0;
        }
        ordenaPonteiros();
    } while (1);
}

void ordernarContatos()
{
    printf("\n1 - Insert Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Quick Sort\n");
    printf("4 - Buble Sort\n");
    printf("0 - Voltar\n");
    scanf("%d",menuBuffer);
    ordenaPonteiros();
    switch (*menuBuffer) {
        case 1:
            insertionSort();
            break;
        case 2:
            selectionSort();
            break;
        case 3:
            quickSort(startList, 0, (*pessoasSizeBuffer) - 1);
            break;
        case 4:
            bubbleSort();
            break;
        case 0:
            break;
    }
    ordenaPonteiros();
}

void insertionSort() {
	if ((*pessoasSizeBuffer) < 2 ) 
        return;

    contato* list = startList;
    for ((*iBuffer) = 1; (*iBuffer) < (*pessoasSizeBuffer); (*iBuffer)++) 
    {
        for ((*jBuffer) = (*iBuffer) - 1; (*jBuffer) >= 0 && 
            strcmp(list[(*jBuffer + 1)].nome, list[(*jBuffer)].nome) < 0; 
            (*jBuffer)--) 
        {
                swap(&list[(*jBuffer + 1)], &list[(*jBuffer)]);
        }
    }
    ordenaPonteiros();
}

void selectionSort () {
    if ((*pessoasSizeBuffer) < 2)
        return;

    contato* list = startList;

    for ((*iBuffer) = 0; (*iBuffer) < (*pessoasSizeBuffer); (*iBuffer)++) {
        int* current_min = menuBuffer;
        *current_min = *iBuffer;
        for ((*jBuffer) = (*pessoasSizeBuffer) - 1; (*jBuffer) > (*iBuffer); (*jBuffer)--) {
            if (strcmp(list[*jBuffer].nome, list[*current_min].nome) < 0) 
                *current_min = (*jBuffer);
        }
        swap(&list[(*iBuffer)], &list[*current_min]);
    }
    ordenaPonteiros();
}

void quickSort(contato* list, int lo, int hi) 
{
    if (lo >= hi || lo < 0)
        return;

    int current_pivo_index = lo;

    for ((*jBuffer) = lo; (*jBuffer) < hi; (*jBuffer)++) {
        if (strcmp(list[*jBuffer].nome, list[hi].nome) <= 0) {
            swap(&list[current_pivo_index], &list[*jBuffer]);
            current_pivo_index++;
        }
    }

    swap(&list[current_pivo_index], &list[hi]);

    quickSort(list, lo, current_pivo_index-1);
    quickSort(list, current_pivo_index+1, hi);

    ordenaPonteiros();
}

void bubbleSort()
{
    // if ((*pessoasSizeBuffer) > 2) {
    //     aux = (contato*)(startStringBuffer + 10);
    //     for ((*iBuffer) = 0; (*iBuffer) < (*pessoasSizeBuffer) - 1; (*iBuffer)++) {
    //         for ((*jBuffer) = 0; (*jBuffer) < (*pessoasSizeBuffer) - 1; (*jBuffer)++) {
    //             if (strcmp(aux[(*jBuffer)].nome,aux[(*jBuffer) + 1].nome) > 0) {
    //                 swap(&aux[(*jBuffer)],&aux[(*jBuffer) + 1],(*jBuffer));
    //             }
    //         }
    //     }
    //     ordenaPonteiros();
    // }
}

void swap(contato *a1,contato *a2) {
    contato *temp = malloc(sizeof(contato));

    temp->numero = a1->numero;
    strcpy(temp->nome, a1->nome);

    a1->numero = a2->numero;
    strcpy(a1->nome, a2->nome);

    a2->numero = temp->numero;
    strcpy(a2->nome, temp->nome);
}

void ordenaPonteiros () {
    pessoasSizeBuffer = (int*)startBuffer;
    menuBuffer        = (int*)startBuffer  + 1;
    iBuffer           = (int*)startBuffer  + 2;
    jBuffer           = (int*)startBuffer  + 3;
    startStringBuffer = (char*)((int*)startBuffer + 4);
    endBuffer         = (contato*)(startStringBuffer + 10);
    startList         = (contato*)(startStringBuffer + 10);
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
        printf("Has %d contacts\n",*pessoasSizeBuffer);
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

void encherLista()
{
    for (*iBuffer = 0; *iBuffer <= 100; (*iBuffer) = (*iBuffer) + 1) {
        (*pessoasSizeBuffer)++;
        startBuffer = realloc(startBuffer,(4*sizeof(int)) + (10*sizeof(char)) + ((*pessoasSizeBuffer)*sizeof(contato)));
        ordenaPonteiros();
        endBuffer->nome[0] = (char)(65 + (rand()%25));
        endBuffer->nome[1] = (char)(65 + (rand()%25));
        endBuffer->nome[2] = (char)(65 + (rand()%25));
        endBuffer->nome[3] = (char)(65 + (rand()%25));
        endBuffer->nome[4] = (char)(65 + (rand()%25));
        endBuffer->numero = rand();
    }
}

void menu (void) {
    printf("\n------- MENU ------\n");
    printf("1 - Adicionar Contato\n");
    printf("2 - Remover Contato\n");
    printf("3 - Listar Contatos\n");
    printf("4 - Achar Contato\n");
    printf("5 - Ordenar Contatos\n");
    printf("6 - Encher Lista de Contatos\n");
    printf("0 - Sair do Programa\n");
}
