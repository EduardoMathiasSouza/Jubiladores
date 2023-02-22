#ifndef __PILHA_H__
#define __PILHA_H__

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

typedef struct RotuloNodo{
	char *rot;
	struct RotuloNodo *prox;
}RotuloNodo;

typedef struct pilhaRotulo {
	int tamanho;
	RotuloNodo *topo;
}pilhaRotulo;

void cria_pilhaTipo(pilhaTipo *typesTable);
void push_pilhaTipo(pilhaTipo *typesTable, tipoPascal type);
tipoPascal pop_pilhaTipo(pilhaTipo *typesTable);
char* define_tipo(tipoPascal type);
void verifica_tipo(pilhaTipo *typesTable, char* operation);
void print_tabelatipo(pilhaTipo *typesTable);

////////////////////

char* geraRotulo(int rotId);
void cria_pilhaRotulo(pilhaRotulo *tabelaRot);
void push_pilhaRotulo(pilhaRotulo *tabelaRot, char *novoRot);
void pop_pilhaRotulo(pilhaRotulo *tabelaRot, int n);
char* getRotulo(pilhaRotulo *tabelaRot, int n);

#endif
