
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimb.h"
#include "pilha.h"

int procs;
int receivingByReference;
int newParams;
int num_vars, novas_var, nivel_lexico, deslocamento;
unsigned int temElse, it_temElse;
int RotId = 0;
int lexicalLevel = 0;
char comparacao[100];
pilha_simbolos tabelaSimbolos;
stackNode *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual;
pilhaTipo tabelaTipo;
pilhaRotulo tabelaRotulos;


void setTemElse() {
	temElse = temElse | (1 << it_temElse);
}

int getTemElse() {
	int r = temElse & (1 << it_temElse);
	temElse = temElse & ~(1 << it_temElse); 
	temElse--;
	if (!it_temElse)
		temElse = 0;
	return r;
}

void initTemElse() {
	if (!(temElse & (unsigned int)1)) {
		temElse = 1;
		it_temElse = 0;
	}
	it_temElse++;
}




%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token INTEGER
%token WHILE DO IF THEN ELSE 
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO DIV
%token NUMERO READ WRITE
%token OR AND NOT

%nonassoc NADA


%%

programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
			 parametros_ou_vazio PONTO_E_VIRGULA
             bloco PONTO {
               pop(&tabelaSimbolos, num_vars + procs);
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
;

parametros_ou_vazio:
	parametros
	| comando_vazio
;

parametros:
	ABRE_PARENTESES lista_idents FECHA_PARENTESES
;

tipo:
	INTEGER { setTypes(&tabelaSimbolos, integer, novas_var); }
;



bloco       :
              parte_declara_vars
              {
              }

              comando_composto
              ;

parte_declara_vars:  var {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		geraCodigo(NULL, amem); 
} 
;


var         : VAR declara_vars
            | declara_vars
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : { 
              novas_var = 0; 
}
              lista_id_var DOIS_PONTOS
              tipo
              {
                num_vars += novas_var;
              }
              PONTO_E_VIRGULA
;


lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere �ltima vars na tabela de s�mbolos */ 
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
            | IDENT { /* insere vars na tabela de s�mbolos */
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
;

lista_idents: lista_idents VIRGULA IDENT{
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
   	| IDENT
	{
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
;


comando_composto: 
   T_BEGIN comandos T_END
;

comandos:
	comandos PONTO_E_VIRGULA comando
	| comando
;

comando: 
   	numero_ou_vazio comando_sem_rotulo
;

numero_ou_vazio:
	numero DOIS_PONTOS
	| comando_vazio
;

comando_vazio:;

comando_sem_rotulo:
	variavel atribuicao_procedimento
	| desvio
	| comando_composto
	| comando_condicional
	| comando_repetitivo
	| leitura
	| escrita
;

desvio:
   { }
;

comando_condicional:
	if_then cond_else
	{
		if (!getTemElse()) {
			char rot[100];
			sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
			geraCodigo(NULL, rot); 
		}
		char rot[100];
		sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL, rot); 
		pop_pilhaRotulo(& tabelaRotulos, 2);
	}
;

if_then: 
	IF expressao 
	{  
		initTemElse(); //inicializa se necessario, incrementa o iterador
		// Gera rotulos de entrada e saida do IF
		char *RotIfInicio = geraRotulo(RotId);
		RotId++;
		char *RotIfFim = geraRotulo(RotId);
		RotId++;

		push_pilhaRotulo(&tabelaRotulos, RotIfInicio);
		push_pilhaRotulo(&tabelaRotulos, RotIfFim);
			
		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVF %s", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, rot);
	} THEN comando_sem_rotulo
;

cond_else:
	ELSE
	{
		setTemElse(); //marca pro iterador que a iésima cláusula tem else
		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVS %s", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL, rot);

		// Imprime rotulo de entrada no fim do if
		sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, rot);
	}
	else_multiplo_unico
;

else_multiplo_unico:
	comando_sem_rotulo
;



chama_procedimento:
{}
;

comando_repetitivo:
	WHILE
	{
		char *RotWhileInicio = geraRotulo(RotId);
		RotId++;
		char *RotWhileFim = geraRotulo(RotId);
		RotId++;

		push_pilhaRotulo(&tabelaRotulos, RotWhileInicio);
		push_pilhaRotulo(&tabelaRotulos, RotWhileFim);

		char rot[100];
        sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL,rot); 
	}
	expressao DO
	{
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, dsvf);
	}
	comando_composto
	{ 
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, rot);

		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
;




lista_expressoes: expressao | expressao VIRGULA lista_expressoes;

expressao:
   	{ newParams++; } expressao_simples  relacao_exp_simples_ou_vazio 
;

relacao_exp_simples_ou_vazio:
	relacao expressao_simples
	{ 
		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
	| comando_vazio
;

relacao:
	IGUAL { strcpy(comparacao, "CMIG"); } 
	| DIFERENTE { strcpy(comparacao, "CMDG"); } 
	| MENOR { strcpy(comparacao, "CMME"); } 
	| MENOR_IGUAL { strcpy(comparacao, "CMEG"); } 
	| MAIOR_IGUAL { strcpy(comparacao, "CMAG"); } 
	| MAIOR { strcpy(comparacao, "CMMA"); } 
;

expressao_simples:
   	soma_ou_vazio expressao_lista_termo
;

soma_ou_vazio:
	SOMA| SUBTRACAO | comando_vazio;
;

expressao_lista_termo:
	expressao_lista_termo lista_termo 
	| termo 
;

lista_termo:
	SOMA termo { 
		verifica_tipo(&tabelaTipo, "soma"); 
		geraCodigo(NULL, "SOMA");}
	| SUBTRACAO termo { 
		verifica_tipo(&tabelaTipo, "subtracao"); 
		geraCodigo(NULL, "SUBT");}
	| OR termo { 
		verifica_tipo(&tabelaTipo, "or"); 
		geraCodigo(NULL, "DISJ");}
;

termo:
	termo lista_fator 
	| fator 
;

lista_fator:
	MULTIPLICACAO fator { 
		verifica_tipo(&tabelaTipo, "multiplicacao"); 
		geraCodigo(NULL, "MULT");}
	| DIVISAO fator { 
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
	| DIV fator { 
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
	| AND fator { 
		verifica_tipo(&tabelaTipo, "and"); 
		geraCodigo(NULL, "CONJ"); }
;

fator:
	variavel %prec NADA
	{
		if(variavel_carregada != NULL) {
			if(variavel_carregada->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s,%d", variavel_carregada->rotulo, lexicalLevel);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				sprintf(comando, "CRVL %d,%d", variavel_carregada->lexicalLevel, variavel_carregada->displacement);
				variavel_carregada = NULL;
				geraCodigo(NULL, comando);
			}
		}
		else {
			if(variavelDestino->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavelDestino->rotulo, lexicalLevel);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				sprintf(comando, "CRVL %d,%d", variavelDestino->lexicalLevel, variavelDestino->displacement);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
	| variavel ABRE_PARENTESES
	{
		if(variavel_carregada != NULL) {
			if(variavel_carregada->category == funcao) {
				procedimentoAtual = variavel_carregada;
			}
		}
		else {
			if(variavelDestino->category == funcao) {
				procedimentoAtual = variavelDestino;
			}
		}
	}
	lista_expressoes FECHA_PARENTESES
	{ 
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, lexicalLevel);
		geraCodigo(NULL, chamaProcedure);
	}
	| numero
	| ABRE_PARENTESES expressao FECHA_PARENTESES
	| NOT fator
;

atribuicao_procedimento:
	atribuicao
	| chama_procedimento 
;

atribuicao:
	ATRIBUICAO expressao
	{
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		sprintf(varLexDisp, "ARMZ %d,%d", variavelDestino->lexicalLevel, variavelDestino->displacement);
		geraCodigo(NULL, varLexDisp); 
		variavelDestino = NULL;
	}
;

variavel:
   	IDENT {
		if(variavelDestino == NULL) {
			variavelDestino = search(&tabelaSimbolos, token);
			if(variavelDestino == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilhaTipo(&tabelaTipo, variavelDestino->tipo);
		}
		else { 
			variavel_carregada = search(&tabelaSimbolos, token);
			if(variavel_carregada == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilhaTipo(&tabelaTipo, variavel_carregada->tipo);
		}
   	}
;

numero:
	NUMERO
	{
		push_pilhaTipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars); 
	}
;

// Comandos sem regra --> leitura e escrita
leitura:
  	READ ABRE_PARENTESES lista_leitura FECHA_PARENTESES
;

lista_leitura:
   	lista_leitura VIRGULA simbolo_leitura
   	| simbolo_leitura
;

simbolo_leitura:
	IDENT
	{
		// Codigo leitura
		geraCodigo(NULL, "LEIT");
		
		// Procura por variavel na tabela de simbolos
		variavelDestino = search(&tabelaSimbolos, token);
		if(variavelDestino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

		// Armazena na variavel destino
      char varLexDisp[1000];
		sprintf(varLexDisp, "ARMZ %d,%d ", variavelDestino->lexicalLevel, variavelDestino->displacement);
		geraCodigo(NULL, varLexDisp); 
		variavelDestino = NULL;
	}
;

escrita:
   	WRITE ABRE_PARENTESES lista_escrita FECHA_PARENTESES
;

lista_escrita:
	lista_escrita VIRGULA expressao { geraCodigo (NULL, "IMPR"); }
	| expressao { geraCodigo (NULL, "IMPR"); }
;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   cria_pilha(&tabelaSimbolos);
   cria_pilhaTipo(&tabelaTipo);
   cria_pilhaRotulo(&tabelaRotulos);
   receivingByReference = 0;
   yyin=fp;
   yyparse();

   return 0;
}
