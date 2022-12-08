#ifndef __PILHA__
#define __PILHA__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum tipoPascal {
	integer,
	boolean,
	naosei
} tipoPascal;

typedef struct tipoNodo {
	tipoPascal tipo;
	struct tipoNodo *prox;
} tipoNodo;

typedef struct pilhaTipo {
	int tamanho;
	tipoNodo *topo;
} pilhaTipo;

void cria_pilhaTipo(pilhaTipo *typesTable);
void push_pilhaTipo(pilhaTipo *typesTable, tipoPascal type);
tipoPascal pop_pilhaTipo(pilhaTipo *typesTable);
char* define_tipo(tipoPascal type);
void verifica_tipo(pilhaTipo *typesTable, char* operation);
void print_tabelatipo(pilhaTipo *typesTable);

#endif