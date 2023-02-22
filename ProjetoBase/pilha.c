#include "pilha.h"

void cria_pilhaTipo(pilhaTipo *typesTable){
    typesTable->topo = NULL;
    typesTable->tamanho = 0;
}
void push_pilhaTipo(pilhaTipo *typesTable, tipoPascal type){
    tipoNodo *novo = (tipoNodo*) malloc(sizeof(tipoNodo));
    novo->tipo = type;
    novo->prox = typesTable->topo;
    typesTable->topo = novo;
    typesTable->tamanho++;
}
tipoPascal pop_pilhaTipo(pilhaTipo *typesTable){
    if(typesTable->tamanho == 0){
        printf("Pilha vazia!");
        exit(1);
    }
    tipoNodo *aux = typesTable->topo;
    tipoPascal type = aux->tipo;
    typesTable->topo = aux->prox;
    free(aux);
    typesTable->tamanho--;
    return type;
}

char* define_tipo(tipoPascal type){
    switch(type){
        case integer:
            return "integer";
        case boolean:
            return "real";
        default:
            return "tipo indefinido";
    }
}
void verifica_tipo(pilhaTipo *typesTable, char* operation){
    tipoPascal type1 = pop_pilhaTipo(typesTable);
    tipoPascal type2 = pop_pilhaTipo(typesTable);
    if(type1 != type2){
        printf("Erro de tipos na operacao %s", operation);
        exit(1);
    }
    push_pilhaTipo(typesTable, type1);
}

void print_tabelatipo(pilhaTipo *typesTable){
    tipoNodo *aux = typesTable->topo;
    while(aux != NULL){
        printf("%s ", define_tipo(aux->tipo));
        aux = aux->prox;    
    }
}


char* geraRotulo(int rotId){
    char *rotulo = (char*)malloc(10 * sizeof(char));
    sprintf(rotulo, "R%02d", rotId);
    return rotulo;
}

void cria_pilhaRotulo(pilhaRotulo *tabelaRot){
    tabelaRot->topo = NULL;
    tabelaRot->tamanho = 0;
}

void push_pilhaRotulo(pilhaRotulo *tabelaRot, char *novoRot){
    RotuloNodo *novo = (RotuloNodo*) malloc(sizeof(RotuloNodo));
    novo->rot = (char*)malloc(strlen(novoRot) * sizeof(char));
    strcpy(novo->rot, novoRot);
    novo->prox = tabelaRot->topo;
    tabelaRot->topo = novo;
    tabelaRot->tamanho++;
}

void pop_pilhaRotulo(pilhaRotulo *tabelaRot, int n){
    if(tabelaRot->tamanho == 0){
        printf("Pilha de Rotulos vazia!");
        exit(1);
    }
    RotuloNodo *aux;
    for(int i = 0; i < n; i++){
        aux =  tabelaRot->topo;
        tabelaRot->topo = aux->prox;
        free(aux);
        tabelaRot->tamanho--;
    }
}

char* getRotulo(pilhaRotulo *tabelaRot, int n){
    if(tabelaRot->tamanho == 0){
        printf("Pilha de Rotulos vazia!");
        exit(1);
    }
    RotuloNodo *aux = tabelaRot->topo;
	if (!n){ 
        n++;}
	while (--n){
		aux = aux->prox;}
    return aux->rot;
}


