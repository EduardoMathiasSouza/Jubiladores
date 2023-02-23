#ifndef __TABELASIMB_H__
#define __TABELASIMB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

typedef enum tipoCategoria {
	Variavel_simples,
	Parametro_formal,
	procedimento,
	funcao,
} tipoCategoria;

typedef enum tipo_passado {
	valor,
	referencia
} tipo_passado;

typedef struct paramDesc {
	char *identificador;
	tipoPascal tipo;
	tipo_passado pass;
} paramDesc;

typedef struct stackNode {
	char *identificador, *rotulo;
	tipoCategoria category;
	int nivel_lexico, deslocamento, numParams, numProcs, numVars;
	tipoPascal tipo;
	tipo_passado pass;
	paramDesc *params;
	struct stackNode *prox;
} stackNode;

typedef struct pilha_simbolos {
	int tamanho;
	stackNode *topo;
} pilha_simbolos;

typedef struct tabelaForward {
	int max, int topo;
	int *declared;
	char ** idents;
} tabelaForward;

typedef struct pilhaNode {
	int max, topo;
	stackNode ** p;
} pilhaNode;

void cria_pilha(pilha_simbolos *symbolsTable);
void push(pilha_simbolos *symbolsTable, stackNode *newSymbol);
stackNode* getTop(pilha_simbolos *symbolsTable);
stackNode* getNth(pilha_simbolos *symbolsTable, int n);
stackNode* search(pilha_simbolos *symbolsTable, char *identifier);
void pop(pilha_simbolos *symbolsTable, int n);
stackNode* createSimpleVarInput(char *identifier, int lexicalLevel, int displacement);
stackNode* createSimpleFunctionInput(char *identifier, char *rotulo, int lexicalLevel, int numParams, tipoPascal returnType);
stackNode* createSimpleProcedureInput(char *identifier, char *rotulo, int lexicalLevel, int numParams);
stackNode* createSimpleFormalParameterInput(char *identifier, int lexicalLevel, int displacement, tipo_passado pass);
void setTypes(pilha_simbolos *symbolsTable, tipoPascal type, int n);

int lastLexicalLevel(pilha_simbolos *symbolsTable);
int hasNext(pilha_simbolos *symbolsTable, const char * ident);

void printTable(pilha_simbolos *symbolsTable);

void updateParams(stackNode *p, pilha_simbolos *symbolsTable, int parameterCount);
void updateNumProcs(pilha_simbolos *p, int nivlex);
void updateNumVars(pilha_simbolos *p, int vars, int nivlex);

void cria_pilhaNode(pilhaNode * p);
void * pop_pilhaNode(pilhaNode * p);
void push_pilhaNode(pilhaNode * p, stackNode * x);

void cria_tabelaForward(tabelaForward * tf);
int push_tabelaForward(tabelaForward * tf, char * ident);
int update_tabelaForward(tabelaForward * tf, char * ident);
int anyLeft_tabelaForward(tabelaForward * tf);

#endif
