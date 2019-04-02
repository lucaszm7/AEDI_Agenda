#include <stdio.h>
#include <stdlib.h>
//typedef struct contato {
//    int numero;
//    char nome;
//}



void *addContato (void *buffer, int *ntotal) {
	void *aux;
	int count = 0;
	(*ntotal)++;
	aux = buffer;
	if((*ntotal) == 1) {
		*(int*)buffer = 123456789;
		(int*)buffer++;
		*(char*)buffer = 'a';
		return aux;
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


int main(int argc, char **argv) {
	
	void *buffer = malloc(2*sizeof(int)+sizeof(char));
	int ntotal = 0;
	buffer = addContato (buffer,&ntotal);
	mostraContatos(buffer,ntotal);
	buffer = addContato (buffer,&ntotal);
	mostraContatos(buffer,ntotal);
	return 0;
}

