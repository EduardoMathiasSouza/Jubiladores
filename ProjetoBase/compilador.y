
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
char comparacao[100], *cur_func;
pilha_simbolos tabelaSimbolos;
stackNode *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual;
pilhaTipo tabelaTipo;
pilhaRotulo tabelaRotulos;
pilhaNode tabelaNode;
tabelaForward tf;
int num_params_chamada, not_simple;
int declara_proc_func;

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
%token PROCEDURE FUNCTION FORWARD


%%

programa    :{
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = geraRotulo(RotId);
						 RotId++;
						 push_pilhaRotulo(&tabelaRotulos, RotInicioSubrotina);
						 procedimentoAtual = createSimpleProcedureInput("main", RotInicioSubrotina, "", 0, 0);
						 push(&tabelaSimbolos, procedimentoAtual);
						 push_pilhaNode(&tabelaNode, procedimentoAtual);
						}
             PROGRAM IDENT
			 			 parametros_ou_vazio PONTO_E_VIRGULA
             bloco PONTO {
							 procedimentoAtual = pop_pilhaNode(&tabelaNode);
               pop(&tabelaSimbolos, procedimentoAtual->numVars + procedimentoAtual->numProcs);
               char dmem[1000];
							 if (procedimentoAtual->numVars > 0) {
               	sprintf(dmem, "DMEM %d", procedimentoAtual->numVars);
              	geraCodigo(NULL, dmem);
							 }
               geraCodigo (NULL, "PARA");
             }
;

parametros_ou_vazio:
	parametros
	| comando_vazio
;

parametros:
	ABRE_PARENTESES lista_id_ou_vazio FECHA_PARENTESES
;

tipo:
	INTEGER { setTypes(&tabelaSimbolos, integer, novas_var); }
;



bloco       :
        parte_declara_vars 
				{
					printf("GotHere\n");
					char rotsaida[100];
      		sprintf(rotsaida, "DSVS %s", getRotulo(&tabelaRotulos,0));
					geraCodigo(NULL, rotsaida);
				}
			  parte_declara_sub_rotinas
			  {
				char rotsaida[100];
     		sprintf(rotsaida, "%s", getRotulo(&tabelaRotulos,0));
     		geraCodigo(rotsaida, "NADA");
				}
        comando_composto
;

parte_declara_vars:  var {
    char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		updateNumVars(&tabelaSimbolos, num_vars, nivel_lexico);
		geraCodigo(NULL, amem); 
} | comando_vazio 
;

parte_declara_sub_rotinas:
	parte_declara_sub_rotinas {declara_proc_func=0;} opcoes_sub_rotinas
	| comando_vazio
;

opcoes_sub_rotinas:
	header_procedimento forward_or_not
	| header_funcao forward_f_or_not
	| comando_vazio
;

forward_or_not: FORWARD {push_tabelaForward(&tf, procedimentoAtual->identificador);
												 updateNumProcs(&tabelaSimbolos, nivel_lexico+1);} PONTO_E_VIRGULA 
			| { if (update_tabelaForward(&tf, token)) updateNumProcs(&tabelaSimbolos, nivel_lexico);} 
					corpo_procedimento PONTO_E_VIRGULA
;

forward_f_or_not: FORWARD {push_tabelaForward(&tf, procedimentoAtual->identificador);
												 updateNumProcs(&tabelaSimbolos, nivel_lexico+1);} PONTO_E_VIRGULA 
			| { if (update_tabelaForward(&tf, token)) updateNumProcs(&tabelaSimbolos, nivel_lexico);} 
					corpo_funcao PONTO_E_VIRGULA
;

header_procedimento:
	PROCEDURE {EhSubrotina = 1;}
	IDENT {
		nivel_lexico++;
		
		// Se não tiver sido "forwarded"
		if (update_tabelaForward(&tf, token) != 0) {
    	proc_declarados++;
			printf("");		
			// Gera rotulos de entrada e saida
    	char *RotInicioSubrotina = geraRotulo(RotId);
    	RotId++;

    	RotFimSubrotina = geraRotulo(RotId);
    	RotId++;
	
			novaEntrada = createSimpleProcedureInput(token, RotInicioSubrotina, RotFimSubrotina, nivel_lexico, 0);
    	push(&tabelaSimbolos, novaEntrada);
    	procedimentoAtual = novaEntrada;
		} else
			procedimentoAtual = search(&tabelaSimbolos, token);
		novos_param = 0;
	}
	parametros_formais_vazio PONTO_E_VIRGULA {nivel_lexico--;}
;

header_funcao:
  FUNCTION { EhSubrotina = 1; }
  IDENT {
		nivel_lexico++;
		
		if (update_tabelaForward(&tf, token) != 0) {
  		printf("\nInside header func%s\n", token);
	  	proc_declarados++;
    	// Gera rotulos de entrada e saida
    	char *RotInicioSubrotina = geraRotulo(RotId);
    	RotId++;

    	RotFimSubrotina = geraRotulo(RotId);
    	RotId++;

    	novaEntrada = createSimpleFunctionInput(token, RotInicioSubrotina, RotFimSubrotina, nivel_lexico, 0, integer);
    	push(&tabelaSimbolos, novaEntrada);
    	procedimentoAtual = novaEntrada;
		} else {
			procedimentoAtual = search(&tabelaSimbolos, token);
		}
		novos_param = 0;
  }
  parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA {nivel_lexico--;}
;

corpo_funcao:
	{
		nivel_lexico++;
  	push_pilhaNode(&tabelaNode, procedimentoAtual);

  	char * RotInicioSubrotina = procedimentoAtual->rotulo;
  	RotFimSubrotina = procedimentoAtual->rotulo_saida;

  	push_pilhaRotulo(&tabelaRotulos, RotInicioSubrotina);
  	push_pilhaRotulo(&tabelaRotulos, RotFimSubrotina);

  	// Imprime rotulo de entrada da subrotina
 		char rotentrada[100];
  	sprintf(rotentrada, "ENPR %d", nivel_lexico);
    geraCodigo(getRotulo(&tabelaRotulos, 2), rotentrada);
	}
  bloco
  {
    procedimentoAtual = (stackNode*) pop_pilhaNode(&tabelaNode);
    pop(&tabelaSimbolos, procedimentoAtual->numProcs); // Remove procedimentos da tabela de simbolos

    // DMEM nas variaveis do procedimento
    pop(&tabelaSimbolos, procedimentoAtual->numVars);
    char dmem[100];
    sprintf(dmem, "DMEM %d", procedimentoAtual->numVars);
    geraCodigo(NULL, dmem);
    pop(&tabelaSimbolos, procedimentoAtual->numParams); // Remove parametros da tabela de simbolos

    char command[100];
    sprintf(command, "RTPR %d, %d", nivel_lexico, num_params);
    geraCodigo(NULL, command);

    novos_param = 0;
    nivel_lexico--;

    variavelDestino = NULL; // Libera variavel destino
    num_vars = old_var;    // Restabelece numero de variaveis no nivel lexico
    EhSubrotina = 0;
    pop_pilhaRotulo(&tabelaRotulos, 2);
  }
;


corpo_procedimento:
	{
    nivel_lexico++;
		push_pilhaNode(&tabelaNode, procedimentoAtual);

		char * RotInicioSubrotina = procedimentoAtual->rotulo;   
		RotFimSubrotina = procedimentoAtual->rotulo_saida;

		push_pilhaRotulo(&tabelaRotulos, RotInicioSubrotina);
    push_pilhaRotulo(&tabelaRotulos, RotFimSubrotina);   
	
    // Imprime rotulo de entrada da subrotina
    char rotentrada[100];
    sprintf(rotentrada, "ENPR %d", nivel_lexico);
    geraCodigo(getRotulo(&tabelaRotulos, 2), rotentrada);
	}
  bloco
  {
    procedimentoAtual = (stackNode*) pop_pilhaNode(&tabelaNode);
    pop(&tabelaSimbolos, procedimentoAtual->numProcs); // Remove procedimentos da tabela de simbolos

    // DMEM nas variaveis do procedimento
   	if (procedimentoAtual->numVars > 0) {
	 		pop(&tabelaSimbolos, procedimentoAtual->numVars);
    	char dmem[100];
			sprintf(dmem, "DMEM %d", procedimentoAtual->numVars);
    	geraCodigo(NULL, dmem);
		}
    pop(&tabelaSimbolos, procedimentoAtual->numParams); // Remove parametros da tabela de simbolos

    char command[100];
    sprintf(command, "RTPR %d, %d", nivel_lexico, procedimentoAtual->numParams);
    geraCodigo(NULL, command);

    novos_param = 0;
    nivel_lexico--;

    variavelDestino = NULL; // Libera variavel destino
    num_vars = old_var;    // Restabelece numero de variaveis no nivel lexico
    EhSubrotina = 0;
    pop_pilhaRotulo(&tabelaRotulos, 2);
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

lista_id_ou_vazio: lista_idents | comando_vazio;

lista_idents: lista_idents VIRGULA IDENT{
		novas_var++;
		num_params++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
   	| IDENT
	{
		novas_var++;
		num_params++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
;

parametros_formais_vazio:
	parametros_formais
	| comando_vazio;
;

parametros_formais:
ABRE_PARENTESES { num_params = 0; }
	lista_parametros_formais_ou_vazio
	FECHA_PARENTESES
	{
		stackNode * x = getNth(&tabelaSimbolos, num_params);
		printf("\nAS PARAMS %s %d\n\n", x->identificador, num_params);
		updateParams(getNth(&tabelaSimbolos, num_params),
								&tabelaSimbolos, num_params);
	}
;

lista_parametros_formais_ou_vazio:
	lista_parametros_formais | comando_vazio;
;

lista_parametros_formais:
	lista_parametros_formais PONTO_E_VIRGULA secao_parametros_formais
	| { novos_param++; } secao_parametros_formais
;

secao_parametros_formais:
  var_vazio { novas_var = 0; } lista_idents DOIS_PONTOS tipo
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
	| atribuicao_funcao
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
			geraCodigo(getRotulo(&tabelaRotulos, 1), "NADA"); 
		}
		char rot[100];
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
		//push_pilhaRotulo(&tabelaRotulos, RotIfInicio);
			
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
		entra_procedimento = 1;
		//geraCodigo(NULL, chama_proc);
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

chama_funcao:
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimentoAtual = variavelDestino;
    sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
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
		sprintf(rot, "%s", getRotulo(&tabelaRotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
;




lista_expressoes: expressao | expressao {num_params_chamada++;} VIRGULA lista_expressoes;

expressao:
   	{ novos_param++; } expressao_simples  relacao_exp_simples_ou_vazio 
;

relacao_exp_simples_ou_vazio:
	relacao expressao_simples
	{
		not_simple = 1; 
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
				int cur_params = entra_procedimento == 2 ? 
												(procedimentoAtual->numParams - num_params_chamada + 1) : novos_param;
				int pass = entra_procedimento == 0 ? variavel_carregada->pass :
																				 procedimentoAtual->params[procedimentoAtual->numParams - cur_params].pass;
				
				if (pass == valor || (pass == referencia && entra_procedimento == 1 && variavel_carregada->pass == referencia))
					sprintf(comando, "CRVL %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else if (entra_procedimento >= 1 && pass == referencia)
          sprintf(comando, "CREN %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
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
				int pass = entra_procedimento == 0 ? variavelDestino->pass :
									procedimentoAtual->params[procedimentoAtual->numParams - novos_param].pass;
				if (pass == valor || (pass == referencia && entra_procedimento == 1 && variavelDestino->pass == referencia))
					sprintf(comando, "CRVL %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else if (entra_procedimento == 1 && pass == referencia)
					sprintf(comando, "CREN %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
	| variavel ABRE_PARENTESES
	{
		entra_procedimento = 2;
		num_params_chamada = 0;
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
		geraCodigo(NULL, "AMEM 1");
		
	}
	lista_expressoes FECHA_PARENTESES
	{
		entra_procedimento = 0;
		num_params_chamada = 0;
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

atribuicao_funcao:
	atribuicao | chama_funcao
;

atribuicao:
	ATRIBUICAO expressao
	{
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		if (variavelDestino->pass == valor)
			sprintf(varLexDisp, "ARMZ %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		else
			sprintf(varLexDisp, "ARMI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
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
   cria_pilhaNode(&tabelaNode);
	 cria_tabelaForward(&tf);
   cur_func = malloc(100);
   receivingByReference = 0;
   proc_declarados = 0;
   yyin=fp;
   yyparse();

   return 0;
}
