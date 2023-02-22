#include "tabelaSimb.h"

void cria_pilha(pilha_simbolos *symbolsTable){
    symbolsTable->topo = NULL;
    symbolsTable->tamanho = 0;
}

void push(pilha_simbolos *symbolsTable, stackNode *newSymbol){
    newSymbol->prox = symbolsTable->topo;
    symbolsTable->topo = newSymbol;
    symbolsTable->tamanho++;
    printf("Pushed %s", newSymbol->identificador);
    printf("Tamanho: %d",symbolsTable->tamanho);
}
stackNode* getTop(pilha_simbolos *symbolsTable){
    if(symbolsTable->tamanho == 0){
        printf("Pilha vazia!");
        return NULL;
    }
    return symbolsTable->topo;
}
stackNode* getNth(pilha_simbolos *symbolsTable, int n){
    if(symbolsTable->tamanho == 0){
        printf("Pilha vazia!");
        return NULL;
    }
    stackNode *aux = symbolsTable->topo;
    for(int i = 0; i < n; i++){
        aux = aux->prox;
    }
    return aux;
}
stackNode* search(pilha_simbolos *symbolsTable, char *identificador){
    stackNode *aux = symbolsTable->topo;
    while(aux != NULL){
        if(strcmp(aux->identificador, identificador) == 0){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void pop(pilha_simbolos *symbolsTable, int n){
    if(symbolsTable->tamanho == 0){
        printf("Pilha vazia!");
        exit(1);}
    stackNode *aux;
    for(int i = 0; i < n; i++){
        aux = symbolsTable->topo;
        symbolsTable->topo = aux->prox;
        free(aux);
        symbolsTable->tamanho--;
    }
}
stackNode* createSimpleVarInput(char *identificador, int lexicalLevel, int displacement){
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));

    newNode->identificador = (char*)malloc((strlen(identificador)+1) * sizeof(char));
    strcpy(newNode->identificador, identificador);
    
    newNode->category = Variavel_simples;
    newNode->nivel_lexico = lexicalLevel;
    newNode->deslocamento = displacement;
    newNode->tipo = naosei;

    return newNode;
}

stackNode* createSimpleFunctionInput(char *identificador, char *rotulo, int lexicalLevel, int numParams, tipoPascal returnType){
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));

    newNode->identificador = (char*)malloc((strlen(identificador)+1) * sizeof(char));
    strcpy(newNode->identificador, identificador);
    
    newNode->category = funcao;
    newNode->nivel_lexico = lexicalLevel;
    newNode->deslocamento = -4-numParams;
    newNode->params = NULL;
    newNode->tipo = returnType;
    newNode->rotulo = (char*)malloc(strlen(rotulo) * sizeof(char));
    strcpy(newNode->rotulo, rotulo);
    newNode->numParams = numParams;
    newNode->numProcs = 0;
    newNode->numVars = 0;

    return newNode;
}
stackNode* createSimpleProcedureInput(char *identificador, char *rotulo, int lexicalLevel, int numParams){
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));

    newNode->identificador = (char*)malloc((strlen(identificador)+1) * sizeof(char));
    strcpy(newNode->identificador, identificador);
    
    newNode->category = procedimento;
    newNode->nivel_lexico = lexicalLevel;
    newNode->numParams = numParams;
    newNode->numVars = 0;
    newNode->numProcs = 0;
    newNode->params = NULL;
    newNode->rotulo = (char*)malloc(strlen(rotulo) * sizeof(char));
    strcpy(newNode->rotulo, rotulo);


    return newNode;
}
stackNode* createSimpleFormalParameterInput(char *identificador, int lexicalLevel, int displacement, tipo_passado pass){
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));

    newNode->identificador = (char*)malloc(strlen(identificador) * sizeof(char));
    strcpy(newNode->identificador, identificador);
    
    newNode->category = Parametro_formal;
    newNode->nivel_lexico = lexicalLevel;
    newNode->deslocamento = displacement;
    newNode->tipo = naosei;
    newNode->pass = pass;

    return newNode;
}
void setTypes(pilha_simbolos *symbolsTable, tipoPascal tipo, int n){
    if(symbolsTable->tamanho == 0){
        printf("Pilha vazia!");
        exit(1);
    }
    int i = 0;
    stackNode *aux = symbolsTable->topo;
    while((i < n) && (aux != NULL)){
        aux->tipo = tipo;
        aux = aux->prox;
        i++;
    }
}

int lastLexicalLevel(pilha_simbolos * symbolsTable) {
		stackNode * aux = symbolsTable->topo;
		while (aux != NULL) {
				if (aux->category == procedimento || aux->category == funcao)
						return aux->nivel_lexico;
				aux = aux->prox;
		}
		return -1;
}

int hasNext(pilha_simbolos * symbolsTable, const char * ident) {
    stackNode * aux = symbolsTable->topo;
		while (aux != NULL && strcmp(ident, aux->identificador) != 0) {
				if (aux->category == procedimento || aux->category == funcao)
						return 1;
				aux = aux->prox;
		}
		return 0;
}

void printTable(pilha_simbolos *symbolsTable){
    stackNode *aux = symbolsTable->topo;
    while(aux != NULL){
        printf("identificador: %s | ", aux->identificador);
        printf("Category: %d | ", aux->category);
        printf("Lexical Level: %d | ", aux->nivel_lexico);
        printf("Displacement: %d | ", aux->deslocamento);
        printf("Type: %d | ", aux->tipo);
        printf("Rotulo: %s | ", aux->rotulo);
        printf("Num Params: %d | ", aux->numParams);
        printf("Pass: %d | ", aux->pass);
        aux = aux->prox;
    		printf("\n");
		}
    printf("\n");
}
void updateParams(stackNode *p, pilha_simbolos *symbolsTable, int parameterCount){
  if (symbolsTable->tamanho < parameterCount)
		puts("Pilha não tem elementos o suficiente");
	p->numParams = parameterCount;
	p->params = (paramDesc*)malloc(parameterCount * sizeof(paramDesc));
	stackNode *aux = symbolsTable->topo;
	for (int i = 0; i < parameterCount; i++) {
		p->params[i].identificador = (char*)malloc((strlen(aux->identificador)+1)*sizeof(char));
		strcpy(p->params[i].identificador, aux->identificador);
		p->params[i].tipo = aux->tipo;
		p->params[i].pass = aux->pass;
		aux->deslocamento = -4-i;
		aux = aux->prox;
	}
	if (p->category == funcao)
		aux->deslocamento -= 2;
	aux->numParams = parameterCount;
}

void updateNumProcs(pilha_simbolos *p, int nivlex) {
	stackNode * aux = p->topo;
  while (aux->nivel_lexico != nivlex)
    aux = aux->prox;
  while (aux->category != funcao && aux->category != procedimento)
    aux = aux->prox;	
	aux->numProcs++;
}

void updateNumVars(pilha_simbolos *p, int vars, int nivlex) {
  stackNode * aux = p->topo;
	while (aux->nivel_lexico != nivlex)
		aux = aux->prox;
  while (aux->category != funcao && aux->category != procedimento)
    aux = aux->prox;
	aux->numVars = vars;
}

void cria_pilhaNode(pilhaNode * p) {
  p->max = 8;
  p->p = malloc(sizeof(stackNode*)*p->max);
  p->topo = 0;
}

void * pop_pilhaNode(pilhaNode * p) {
  p->topo--;
  return(p->p[p->topo+1]);
}

void push_pilhaNode(pilhaNode * p, stackNode * x) {
  if (p->topo == p->max-1) {
    p->max*=2;
    p->p = realloc(p->p, sizeof(stackNode*)*p->max);
  }
  p->topo++;
  p->p[p->topo] = x;
}

 
