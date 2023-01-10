
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
int lexicalLevel = 0;
char comparacao[100];
pilha_simbolos tabelaSimbolos;
stackNode *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual;
pilhaTipo tabelaTipo;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token WHILE DO IF THEN ELSE 
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO
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

tipo        : IDENT
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

comando_composto:
{}
;

comando_condicional:
{}
;

comando_repetitivo:
{}
;

chama_procedimento:
{}
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
	| AND fator { 
		verifica_tipo(&tabelaTipo, "and"); 
		geraCodigo(NULL, "CONJ"); }
;

fator:
	variavel
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
		//verifica_tipo(&tabelaTipo, "atribuicao");
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
		printf("ENTREI");
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
   receivingByReference = 0;
   yyin=fp;
   yyparse();

   return 0;
}
