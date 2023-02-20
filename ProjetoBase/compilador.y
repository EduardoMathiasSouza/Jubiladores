
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

int receivingByReference;
int receivingFormalParams; 
int proc_declarados;
int num_vars, num_params, old_var, novas_var, novos_param, nivel_lexico, deslocamento;
unsigned int temElse, it_temElse;
int entra_procedimento;
char chama_proc[100];
char *RotFimSubrotina;
int RotId = 0;
int EhSubrotina = 0;
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
%token PROCEDURE FUNCTION


%%

programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
			 parametros_ou_vazio PONTO_E_VIRGULA
             bloco PONTO {
               pop(&tabelaSimbolos, num_vars + proc_declarados);
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
			  parte_declara_sub_rotinas
			  {
				if(proc_declarados > 0 && nivel_lexico == 0) {
					//char command[100];
					//sprintf(command, "%s: NADA", RotFimSubrotina);
					geraCodigo(RotFimSubrotina, "NADA"); 
					}
				}
              comando_composto
;

parte_declara_vars:  var {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		geraCodigo(NULL, amem); 
} 
;

parte_declara_sub_rotinas:
	parte_declara_sub_rotinas opcoes_sub_rotinas
	| comando_vazio
;

opcoes_sub_rotinas:
	declaracao_procedimento PONTO_E_VIRGULA
	| comando_vazio
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

declaracao_procedimento:
	PROCEDURE { EhSubrotina = 1; }
	IDENT
	{
		proc_declarados++;
		// Gera rotulos de entrada e saida
		RotFimSubrotina = geraRotulo(RotId);
		RotId++;
		char *RotInicioSubrotina = geraRotulo(RotId);
		RotId++;
		push_pilhaRotulo(&tabelaRotulos, RotFimSubrotina);
		push_pilhaRotulo(&tabelaRotulos, RotInicioSubrotina);

		// Soh imprime no primeiro pois desvia pra main
		if(proc_declarados == 1) {
			// Imprime rotulo de saida da subrotina
			char rotsaida[100];
			sprintf(rotsaida, "DSVS %s", getRotulo(&tabelaRotulos,2));
			geraCodigo(NULL, rotsaida);
		}

		// Imprime rotulo de entrada da subrotina
		char rotentrada[100];
		nivel_lexico++;
		sprintf(rotentrada, "ENPR %d", nivel_lexico);
		geraCodigo(getRotulo(&tabelaRotulos, 1), rotentrada); 
	
		novaEntrada = createSimpleProcedureInput(token, RotInicioSubrotina, nivel_lexico, 0);
		push(&tabelaSimbolos, novaEntrada);
	}
	{ novos_param = 0; } parametros_formais_vazio PONTO_E_VIRGULA
	{
		// Zera para ser utilizado na subrotina
		// Mas salva valor para ser recuperado
		old_var = num_vars;
		num_vars = 0;
		deslocamento = 0;
	}
	bloco
	{
		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, num_vars);
		char dmem[100];
		sprintf(dmem, "DMEM %d", num_vars);
		geraCodigo(NULL, dmem);
		
		// Pega procedimento para printar infos da saida dele
		variavelDestino = getNth(&tabelaSimbolos, num_params);
		if(variavelDestino == NULL) {
			printf("Procedimento nao encontrado na tabela de simbolos.\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", variavelDestino->nivel_lexico, variavelDestino->numParams);
		geraCodigo(NULL, command);
		pop(&tabelaSimbolos, num_params); // Remove parametros da tabela de simbolos

		novos_param = 0;
		//geraCodigo(NULL, command);
		nivel_lexico--;

		variavelDestino = NULL; // Libera variavel destino
		num_vars = old_var;    // Restabelece numero de variaveis no nivel lexico
		EhSubrotina = 0;
		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
;

parametros_formais_vazio:
	parametros_formais
	| comando_vazio;
;

parametros_formais:
ABRE_PARENTESES { num_params = 0; }
	lista_parametros_formais
	FECHA_PARENTESES
	{
		updateParams(getNth(&tabelaSimbolos, num_params + 1),
								&tabelaSimbolos, num_params);
	}
;

lista_parametros_formais:
	lista_parametros_formais PONTO_E_VIRGULA secao_parametros_formais
	| { novos_param++; } secao_parametros_formais
;

secao_parametros_formais:
   	{ num_params++; } var_vazio { novas_var = 0; } lista_idents DOIS_PONTOS tipo
;

var_vazio:
	VAR {receivingByReference = 1; } | comando_vazio {receivingByReference = 0; }
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
			//sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
			geraCodigo(getRotulo(&tabelaRotulos, 1), "NADA"); 
		}
		char rot[100];
		//sprintf(rot, "NADA", getRotulo(&tabelaRotulos, 2));
		geraCodigo(getRotulo(&tabelaRotulos, 2), "NADA"); 
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
		//sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(getRotulo(&tabelaRotulos, 1), "NADA");
	}
	else_multiplo_unico
;

else_multiplo_unico:
	comando_sem_rotulo
;



chama_procedimento:
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
   	}
	ABRE_PARENTESES {  receivingFormalParams = 1; novos_param = 0; }
	lista_expressoes_ou_vazio
	FECHA_PARENTESES
	{ 
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc); 
		receivingFormalParams = 0;
	}
	{ variavelDestino = NULL; }
	|
	{
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
	{ 
		entra_procedimento = 0;
	}
;

lista_expressoes_ou_vazio:
	lista_expressoes
	| comando_vazio
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
    //sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 2));
		geraCodigo(getRotulo(&tabelaRotulos, 2), "NADA"); 
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
		//sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(getRotulo(&tabelaRotulos, 1), "NADA");

		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
;




lista_expressoes: expressao | expressao VIRGULA lista_expressoes;

expressao:
   	{ novos_param++; } expressao_simples  relacao_exp_simples_ou_vazio 
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
	variavel
	{
		if(variavel_carregada != NULL) {
			if(variavel_carregada->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				sprintf(comando, "CRVL %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				variavel_carregada = NULL;
				geraCodigo(NULL, comando);
			}
		}
		else {
			if(variavelDestino->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				sprintf(comando, "CRVL %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
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
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
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
		sprintf(varLexDisp, "ARMZ %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
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
		sprintf(varLexDisp, "ARMZ %d, %d ", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
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
   proc_declarados = 0;
   yyin=fp;
   yyparse();

   return 0;
}
