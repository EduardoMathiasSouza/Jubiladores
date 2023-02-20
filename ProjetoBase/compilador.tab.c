/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "compilador.y"

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
int num_params_chamada;

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





#line 123 "compilador.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ABRE_PARENTESES = 4,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 5,           /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 6,                    /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 7,            /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 8,                /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 9,                      /* PONTO  */
  YYSYMBOL_T_BEGIN = 10,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 14,                /* ATRIBUICAO  */
  YYSYMBOL_INTEGER = 15,                   /* INTEGER  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_MAIOR = 21,                     /* MAIOR  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 23,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 24,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 25,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 26,                 /* DIFERENTE  */
  YYSYMBOL_SOMA = 27,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 28,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 29,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 30,                   /* DIVISAO  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_NUMERO = 32,                    /* NUMERO  */
  YYSYMBOL_READ = 33,                      /* READ  */
  YYSYMBOL_WRITE = 34,                     /* WRITE  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_PROCEDURE = 38,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 39,                  /* FUNCTION  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_programa = 41,                  /* programa  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_parametros_ou_vazio = 43,       /* parametros_ou_vazio  */
  YYSYMBOL_parametros = 44,                /* parametros  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_parte_declara_vars = 48,        /* parte_declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 49, /* parte_declara_sub_rotinas  */
  YYSYMBOL_opcoes_sub_rotinas = 50,        /* opcoes_sub_rotinas  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_declara_vars = 52,              /* declara_vars  */
  YYSYMBOL_declara_var = 53,               /* declara_var  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_lista_id_var = 56,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 57,              /* lista_idents  */
  YYSYMBOL_declaracao_procedimento = 58,   /* declaracao_procedimento  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_parametros_formais_vazio = 63,  /* parametros_formais_vazio  */
  YYSYMBOL_parametros_formais = 64,        /* parametros_formais  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_lista_parametros_formais = 66,  /* lista_parametros_formais  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_secao_parametros_formais = 68,  /* secao_parametros_formais  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_70_12 = 70,                     /* $@12  */
  YYSYMBOL_var_vazio = 71,                 /* var_vazio  */
  YYSYMBOL_comando_composto = 72,          /* comando_composto  */
  YYSYMBOL_comandos = 73,                  /* comandos  */
  YYSYMBOL_comando = 74,                   /* comando  */
  YYSYMBOL_numero_ou_vazio = 75,           /* numero_ou_vazio  */
  YYSYMBOL_comando_vazio = 76,             /* comando_vazio  */
  YYSYMBOL_comando_sem_rotulo = 77,        /* comando_sem_rotulo  */
  YYSYMBOL_desvio = 78,                    /* desvio  */
  YYSYMBOL_comando_condicional = 79,       /* comando_condicional  */
  YYSYMBOL_if_then = 80,                   /* if_then  */
  YYSYMBOL_81_13 = 81,                     /* $@13  */
  YYSYMBOL_cond_else = 82,                 /* cond_else  */
  YYSYMBOL_83_14 = 83,                     /* $@14  */
  YYSYMBOL_else_multiplo_unico = 84,       /* else_multiplo_unico  */
  YYSYMBOL_chama_procedimento = 85,        /* chama_procedimento  */
  YYSYMBOL_86_15 = 86,                     /* $@15  */
  YYSYMBOL_87_16 = 87,                     /* $@16  */
  YYSYMBOL_88_17 = 88,                     /* $@17  */
  YYSYMBOL_89_18 = 89,                     /* $@18  */
  YYSYMBOL_lista_expressoes_ou_vazio = 90, /* lista_expressoes_ou_vazio  */
  YYSYMBOL_comando_repetitivo = 91,        /* comando_repetitivo  */
  YYSYMBOL_92_19 = 92,                     /* $@19  */
  YYSYMBOL_93_20 = 93,                     /* $@20  */
  YYSYMBOL_lista_expressoes = 94,          /* lista_expressoes  */
  YYSYMBOL_expressao = 95,                 /* expressao  */
  YYSYMBOL_96_21 = 96,                     /* $@21  */
  YYSYMBOL_relacao_exp_simples_ou_vazio = 97, /* relacao_exp_simples_ou_vazio  */
  YYSYMBOL_relacao = 98,                   /* relacao  */
  YYSYMBOL_expressao_simples = 99,         /* expressao_simples  */
  YYSYMBOL_soma_ou_vazio = 100,            /* soma_ou_vazio  */
  YYSYMBOL_expressao_lista_termo = 101,    /* expressao_lista_termo  */
  YYSYMBOL_lista_termo = 102,              /* lista_termo  */
  YYSYMBOL_termo = 103,                    /* termo  */
  YYSYMBOL_lista_fator = 104,              /* lista_fator  */
  YYSYMBOL_fator = 105,                    /* fator  */
  YYSYMBOL_106_22 = 106,                   /* $@22  */
  YYSYMBOL_atribuicao_procedimento = 107,  /* atribuicao_procedimento  */
  YYSYMBOL_atribuicao = 108,               /* atribuicao  */
  YYSYMBOL_variavel = 109,                 /* variavel  */
  YYSYMBOL_numero = 110,                   /* numero  */
  YYSYMBOL_leitura = 111,                  /* leitura  */
  YYSYMBOL_lista_leitura = 112,            /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 113,          /* simbolo_leitura  */
  YYSYMBOL_escrita = 114,                  /* escrita  */
  YYSYMBOL_lista_escrita = 115             /* lista_escrita  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    72,    87,    88,    92,    96,   104,   102,
     114,   122,   123,   127,   128,   132,   133,   136,   137,   140,
     145,   140,   152,   158,   166,   171,   180,   182,   209,   210,
     180,   248,   249,   253,   253,   263,   264,   264,   268,   268,
     268,   272,   272,   276,   280,   281,   285,   289,   290,   293,
     296,   297,   298,   299,   300,   301,   302,   306,   310,   326,
     325,   346,   345,   361,   367,   374,   377,   367,   386,   386,
     401,   402,   408,   422,   407,   444,   444,   447,   447,   451,
     456,   460,   461,   462,   463,   464,   465,   469,   473,   473,
     473,   477,   478,   482,   485,   488,   494,   495,   499,   502,
     505,   508,   514,   550,   549,   568,   569,   570,   574,   575,
     579,   590,   611,   622,   626,   627,   631,   652,   656,   657
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "INTEGER", "WHILE", "DO", "IF", "THEN", "ELSE", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "NUMERO", "READ", "WRITE", "OR",
  "AND", "NOT", "PROCEDURE", "FUNCTION", "$accept", "programa", "$@1",
  "parametros_ou_vazio", "parametros", "tipo", "bloco", "$@2",
  "parte_declara_vars", "parte_declara_sub_rotinas", "opcoes_sub_rotinas",
  "var", "declara_vars", "declara_var", "$@3", "$@4", "lista_id_var",
  "lista_idents", "declaracao_procedimento", "$@5", "$@6", "$@7", "$@8",
  "parametros_formais_vazio", "parametros_formais", "$@9",
  "lista_parametros_formais", "$@10", "secao_parametros_formais", "$@11",
  "$@12", "var_vazio", "comando_composto", "comandos", "comando",
  "numero_ou_vazio", "comando_vazio", "comando_sem_rotulo", "desvio",
  "comando_condicional", "if_then", "$@13", "cond_else", "$@14",
  "else_multiplo_unico", "chama_procedimento", "$@15", "$@16", "$@17",
  "$@18", "lista_expressoes_ou_vazio", "comando_repetitivo", "$@19",
  "$@20", "lista_expressoes", "expressao", "$@21",
  "relacao_exp_simples_ou_vazio", "relacao", "expressao_simples",
  "soma_ou_vazio", "expressao_lista_termo", "lista_termo", "termo",
  "lista_fator", "fator", "$@22", "atribuicao_procedimento", "atribuicao",
  "variavel", "numero", "leitura", "lista_leitura", "simbolo_leitura",
  "escrita", "lista_escrita", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -117,    11,    20,  -117,    32,    51,    63,    70,  -117,  -117,
    -117,    29,    67,  -117,    65,  -117,    71,  -117,  -117,    68,
    -117,    72,  -117,    68,  -117,    44,  -117,  -117,  -117,    48,
    -117,    73,  -117,    77,  -117,    74,    76,    75,    57,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,    -1,  -117,     3,  -117,
      78,    85,  -117,    57,  -117,  -117,  -117,  -117,    89,    90,
    -117,  -117,  -117,  -117,    79,  -117,    13,  -117,  -117,  -117,
    -117,    91,  -117,  -117,  -117,    41,    83,  -117,  -117,  -117,
    -117,  -117,    93,  -117,  -117,  -117,  -117,    94,  -117,  -117,
      81,    84,  -117,  -117,  -117,    26,     1,  -117,    66,  -117,
    -117,    69,     3,  -117,  -117,  -117,  -117,  -117,     3,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,    41,  -117,     1,
     -20,    10,  -117,    96,  -117,  -117,    83,  -117,  -117,  -117,
    -117,    97,    54,  -117,    67,    73,  -117,  -117,    99,  -117,
       1,     1,     1,  -117,     1,     1,     1,     1,  -117,  -117,
    -117,  -117,  -117,   101,  -117,   102,  -117,  -117,  -117,    95,
    -117,  -117,  -117,    10,    10,    10,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,   104,  -117,  -117,
      63,  -117,    59,    76,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    49,     0,     0,     4,     5,
      25,     0,    19,     6,     0,    19,     0,    49,    10,    16,
      18,     0,    24,    15,     3,     8,    12,    17,    23,     0,
      26,     0,    11,     0,    14,     0,     0,     0,    49,     9,
      13,    22,     7,    20,    27,   112,     0,    45,    57,    48,
       0,     0,    28,    49,    43,   111,    72,    77,     0,     0,
      52,    46,    51,    53,     0,    54,    68,    55,    56,    47,
      21,    49,    44,    77,    59,    49,     0,    77,    61,    58,
      77,   109,     0,    69,    50,   108,    33,     0,    31,    32,
       0,     0,    88,    89,    90,    49,     0,   116,     0,   115,
     119,     0,    57,   110,    65,    36,    29,    73,    57,    86,
      83,    85,    84,    81,    82,    80,    78,    49,    77,     0,
      87,    92,    97,   102,   105,   113,     0,   117,    77,    63,
      62,    77,     0,    38,    19,     0,    60,    79,     0,   107,
       0,     0,     0,    91,     0,     0,     0,     0,    96,   103,
     114,   118,    71,     0,    70,    75,    34,    38,    37,    49,
      30,    74,   106,    93,    94,    95,    98,    99,   100,   101,
      77,    66,    77,    35,    41,    39,    42,     0,    67,    76,
       0,   104,     0,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,  -117,  -117,  -117,   -73,   -23,  -117,  -117,  -117,
    -117,  -117,    98,    34,  -117,  -117,  -117,   -66,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,   -42,  -117,
    -117,  -117,   -30,  -117,    64,  -117,    -5,   -76,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -110,   -55,  -117,  -117,  -117,     2,
    -117,  -117,  -117,   -98,  -117,  -116,  -117,  -117,  -117,   -44,
     -29,  -117,  -117,   -10,  -117,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    43,    16,    31,    17,    25,
      32,    18,    19,    20,    21,    51,    29,    11,    33,    37,
      52,    71,   134,    87,    88,   105,   132,   133,   158,   159,
     180,   175,    60,    46,    47,    48,    49,    61,    62,    63,
      64,    91,    79,   102,   130,    81,    82,   131,   178,    83,
     153,    65,    73,   135,   154,   155,    75,   116,   117,    95,
      96,   120,   143,   121,   148,   122,   170,    84,    85,   123,
     124,    67,    98,    99,    68,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    39,    74,   139,    66,   118,    53,   140,   141,    50,
      54,     3,    26,    38,    55,   142,    55,   -64,    90,    56,
      34,    57,   100,     4,    50,   103,   129,    80,   166,   167,
     168,   169,   136,    45,    13,    14,    58,    59,   119,   144,
     145,   146,   163,   164,   165,     5,   147,   109,   110,   111,
     112,   113,   114,    27,    35,     6,    36,    27,    66,   156,
     177,   157,   179,   138,    66,    14,    89,   183,    92,    93,
      94,   125,   126,   151,   127,   128,    10,    12,    22,    15,
      24,   -19,    30,    38,    40,    28,    69,    41,    44,    45,
     115,    42,    70,    76,    77,    86,    97,   104,   107,    78,
     149,   106,   -49,   108,   162,   161,   171,   174,   172,   181,
     184,   160,    94,    23,   182,   173,   150,    72,     0,   137,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176
};

static const yytype_int16 yycheck[] =
{
       5,    31,    57,   119,    48,     4,     7,    27,    28,    38,
      11,     0,    17,    10,    13,    35,    13,     4,    73,    16,
      25,    18,    77,     3,    53,    80,   102,    14,   144,   145,
     146,   147,   108,    32,     5,     6,    33,    34,    37,    29,
      30,    31,   140,   141,   142,    13,    36,    21,    22,    23,
      24,    25,    26,    19,     6,     4,     8,    23,   102,     5,
     170,     7,   172,   118,   108,     6,    71,     8,    27,    28,
      75,     5,     6,   128,     5,     6,    13,     7,    13,    12,
       9,    13,    38,    10,     7,    13,     8,    13,    13,    32,
      95,    15,     7,     4,     4,     4,    13,     4,    17,    20,
       4,     7,     5,    19,     5,   135,     5,    12,     6,     5,
     183,   134,   117,    15,   180,   157,   126,    53,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,    13,     4,    43,    44,    76,
      13,    57,     7,     5,     6,    12,    46,    48,    51,    52,
      53,    54,    13,    52,     9,    49,    76,    53,    13,    56,
      38,    47,    50,    58,    76,     6,     8,    59,    10,    72,
       7,    13,    15,    45,    13,    32,    73,    74,    75,    76,
     110,    55,    60,     7,    11,    13,    16,    18,    33,    34,
      72,    77,    78,    79,    80,    91,   109,   111,   114,     8,
       7,    61,    74,    92,    95,    96,     4,     4,    20,    82,
      14,    85,    86,    89,   107,   108,     4,    63,    64,    76,
      95,    81,    27,    28,    76,    99,   100,    13,   112,   113,
      95,   115,    83,    95,     4,    65,     7,    17,    19,    21,
      22,    23,    24,    25,    26,    76,    97,    98,     4,    37,
     101,   103,   105,   109,   110,     5,     6,     5,     6,    77,
      84,    87,    66,    67,    62,    93,    77,    99,    95,   105,
      27,    28,    35,   102,    29,    30,    31,    36,   104,     4,
     113,    95,    76,    90,    94,    95,     5,     7,    68,    69,
      46,    72,     5,   103,   103,   103,   105,   105,   105,   105,
     106,     5,     6,    68,    12,    71,    76,    94,    88,    94,
      70,     5,    57,     8,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    45,    47,    46,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    54,
      55,    53,    56,    56,    57,    57,    59,    60,    61,    62,
      58,    63,    63,    65,    64,    66,    67,    66,    69,    70,
      68,    71,    71,    72,    73,    73,    74,    75,    75,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    79,    81,
      80,    83,    82,    84,    86,    87,    88,    85,    89,    85,
      90,    90,    92,    93,    91,    94,    94,    96,    95,    97,
      97,    98,    98,    98,    98,    98,    98,    99,   100,   100,
     100,   101,   101,   102,   102,   102,   103,   103,   104,   104,
     104,   104,   105,   106,   105,   105,   105,   105,   107,   107,
     108,   109,   110,   111,   112,   112,   113,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     1,     0,     4,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     0,
       0,     6,     3,     1,     3,     1,     0,     0,     0,     0,
       9,     1,     1,     0,     4,     3,     0,     2,     0,     0,
       6,     1,     1,     3,     3,     1,     2,     2,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       5,     0,     3,     1,     0,     0,     0,     6,     0,     1,
       1,     1,     0,     0,     6,     1,     3,     0,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     1,     0,     5,     1,     3,     2,     1,     1,
       2,     1,     1,     4,     3,     1,     1,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 72 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             }
#line 1380 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_vazio PONTO_E_VIRGULA bloco PONTO  */
#line 77 "compilador.y"
                         {
               pop(&tabelaSimbolos, num_vars + proc_declarados);
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1392 "compilador.tab.c"
    break;

  case 7: /* tipo: INTEGER  */
#line 96 "compilador.y"
                { setTypes(&tabelaSimbolos, integer, novas_var); }
#line 1398 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 104 "compilador.y"
                          {
				if(proc_declarados > 0 && nivel_lexico == 0) {
					//char command[100];
					//sprintf(command, "%s: NADA", RotFimSubrotina);
					geraCodigo(RotFimSubrotina, "NADA"); 
					}
				}
#line 1410 "compilador.tab.c"
    break;

  case 10: /* parte_declara_vars: var  */
#line 114 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		geraCodigo(NULL, amem); 
}
#line 1420 "compilador.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 140 "compilador.y"
              { 
              novas_var = 0; 
}
#line 1428 "compilador.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 145 "compilador.y"
              {
                num_vars += novas_var;
              }
#line 1436 "compilador.tab.c"
    break;

  case 22: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 153 "compilador.y"
              { /* insere �ltima vars na tabela de s�mbolos */ 
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
#line 1446 "compilador.tab.c"
    break;

  case 23: /* lista_id_var: IDENT  */
#line 158 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
#line 1457 "compilador.tab.c"
    break;

  case 24: /* lista_idents: lista_idents VIRGULA IDENT  */
#line 166 "compilador.y"
                                        {
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1467 "compilador.tab.c"
    break;

  case 25: /* lista_idents: IDENT  */
#line 172 "compilador.y"
        {
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1477 "compilador.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 180 "compilador.y"
                  { EhSubrotina = 1; }
#line 1483 "compilador.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 182 "compilador.y"
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
#line 1515 "compilador.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 209 "compilador.y"
        { novos_param = 0; }
#line 1521 "compilador.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 210 "compilador.y"
        {
		// Zera para ser utilizado na subrotina
		// Mas salva valor para ser recuperado
		old_var = num_vars;
		num_vars = 0;
		deslocamento = 0;
	}
#line 1533 "compilador.tab.c"
    break;

  case 30: /* declaracao_procedimento: PROCEDURE $@5 IDENT $@6 $@7 parametros_formais_vazio PONTO_E_VIRGULA $@8 bloco  */
#line 218 "compilador.y"
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
#line 1565 "compilador.tab.c"
    break;

  case 33: /* $@9: %empty  */
#line 253 "compilador.y"
                { num_params = 0; }
#line 1571 "compilador.tab.c"
    break;

  case 34: /* parametros_formais: ABRE_PARENTESES $@9 lista_parametros_formais FECHA_PARENTESES  */
#line 256 "compilador.y"
        {
		updateParams(getNth(&tabelaSimbolos, num_params + 1),
								&tabelaSimbolos, num_params);
	}
#line 1580 "compilador.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 264 "compilador.y"
          { novos_param++; }
#line 1586 "compilador.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 268 "compilador.y"
        { num_params++; }
#line 1592 "compilador.tab.c"
    break;

  case 39: /* $@12: %empty  */
#line 268 "compilador.y"
                                    { novas_var = 0; }
#line 1598 "compilador.tab.c"
    break;

  case 41: /* var_vazio: VAR  */
#line 272 "compilador.y"
            {receivingByReference = 1; }
#line 1604 "compilador.tab.c"
    break;

  case 42: /* var_vazio: comando_vazio  */
#line 272 "compilador.y"
                                                         {receivingByReference = 0; }
#line 1610 "compilador.tab.c"
    break;

  case 57: /* desvio: %empty  */
#line 306 "compilador.y"
   { }
#line 1616 "compilador.tab.c"
    break;

  case 58: /* comando_condicional: if_then cond_else  */
#line 311 "compilador.y"
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
#line 1632 "compilador.tab.c"
    break;

  case 59: /* $@13: %empty  */
#line 326 "compilador.y"
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
	}
#line 1653 "compilador.tab.c"
    break;

  case 61: /* $@14: %empty  */
#line 346 "compilador.y"
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
#line 1669 "compilador.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 367 "compilador.y"
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		//geraCodigo(NULL, chama_proc);
   	}
#line 1681 "compilador.tab.c"
    break;

  case 65: /* $@16: %empty  */
#line 374 "compilador.y"
                        {  receivingFormalParams = 1; novos_param = 0; }
#line 1687 "compilador.tab.c"
    break;

  case 66: /* $@17: %empty  */
#line 377 "compilador.y"
        {
		if (novos_param != procedimentoAtual->numParams)
			imprimeErro("Número de parâmetros errado.\n"); 
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc); 
		receivingFormalParams = 0;
	}
#line 1699 "compilador.tab.c"
    break;

  case 67: /* chama_procedimento: $@15 ABRE_PARENTESES $@16 lista_expressoes_ou_vazio FECHA_PARENTESES $@17  */
#line 384 "compilador.y"
        { variavelDestino = NULL; }
#line 1705 "compilador.tab.c"
    break;

  case 68: /* $@18: %empty  */
#line 386 "compilador.y"
        {
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
#line 1719 "compilador.tab.c"
    break;

  case 69: /* chama_procedimento: $@18  */
#line 395 "compilador.y"
        { 
		entra_procedimento = 0;
	}
#line 1727 "compilador.tab.c"
    break;

  case 72: /* $@19: %empty  */
#line 408 "compilador.y"
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
#line 1745 "compilador.tab.c"
    break;

  case 73: /* $@20: %empty  */
#line 422 "compilador.y"
        {
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1755 "compilador.tab.c"
    break;

  case 74: /* comando_repetitivo: WHILE $@19 expressao DO $@20 comando_composto  */
#line 428 "compilador.y"
        { 
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		//sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(getRotulo(&tabelaRotulos, 1), "NADA");

		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
#line 1771 "compilador.tab.c"
    break;

  case 77: /* $@21: %empty  */
#line 447 "compilador.y"
        { novos_param++; }
#line 1777 "compilador.tab.c"
    break;

  case 79: /* relacao_exp_simples_ou_vazio: relacao expressao_simples  */
#line 452 "compilador.y"
        { 
		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
#line 1786 "compilador.tab.c"
    break;

  case 81: /* relacao: IGUAL  */
#line 460 "compilador.y"
              { strcpy(comparacao, "CMIG"); }
#line 1792 "compilador.tab.c"
    break;

  case 82: /* relacao: DIFERENTE  */
#line 461 "compilador.y"
                    { strcpy(comparacao, "CMDG"); }
#line 1798 "compilador.tab.c"
    break;

  case 83: /* relacao: MENOR  */
#line 462 "compilador.y"
                { strcpy(comparacao, "CMME"); }
#line 1804 "compilador.tab.c"
    break;

  case 84: /* relacao: MENOR_IGUAL  */
#line 463 "compilador.y"
                      { strcpy(comparacao, "CMEG"); }
#line 1810 "compilador.tab.c"
    break;

  case 85: /* relacao: MAIOR_IGUAL  */
#line 464 "compilador.y"
                      { strcpy(comparacao, "CMAG"); }
#line 1816 "compilador.tab.c"
    break;

  case 86: /* relacao: MAIOR  */
#line 465 "compilador.y"
                { strcpy(comparacao, "CMMA"); }
#line 1822 "compilador.tab.c"
    break;

  case 93: /* lista_termo: SOMA termo  */
#line 482 "compilador.y"
                   { 
		verifica_tipo(&tabelaTipo, "soma"); 
		geraCodigo(NULL, "SOMA");}
#line 1830 "compilador.tab.c"
    break;

  case 94: /* lista_termo: SUBTRACAO termo  */
#line 485 "compilador.y"
                          { 
		verifica_tipo(&tabelaTipo, "subtracao"); 
		geraCodigo(NULL, "SUBT");}
#line 1838 "compilador.tab.c"
    break;

  case 95: /* lista_termo: OR termo  */
#line 488 "compilador.y"
                   { 
		verifica_tipo(&tabelaTipo, "or"); 
		geraCodigo(NULL, "DISJ");}
#line 1846 "compilador.tab.c"
    break;

  case 98: /* lista_fator: MULTIPLICACAO fator  */
#line 499 "compilador.y"
                            { 
		verifica_tipo(&tabelaTipo, "multiplicacao"); 
		geraCodigo(NULL, "MULT");}
#line 1854 "compilador.tab.c"
    break;

  case 99: /* lista_fator: DIVISAO fator  */
#line 502 "compilador.y"
                        { 
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 1862 "compilador.tab.c"
    break;

  case 100: /* lista_fator: DIV fator  */
#line 505 "compilador.y"
                    { 
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 1870 "compilador.tab.c"
    break;

  case 101: /* lista_fator: AND fator  */
#line 508 "compilador.y"
                    { 
		verifica_tipo(&tabelaTipo, "and"); 
		geraCodigo(NULL, "CONJ"); }
#line 1878 "compilador.tab.c"
    break;

  case 102: /* fator: variavel  */
#line 515 "compilador.y"
        {
		if(variavel_carregada != NULL) {
			if(variavel_carregada->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				if (variavel_carregada->pass == valor)
					sprintf(comando, "CRVL %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
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
				if (variavelDestino->pass == valor)
					sprintf(comando, "CRVL %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
#line 1917 "compilador.tab.c"
    break;

  case 103: /* $@22: %empty  */
#line 550 "compilador.y"
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
#line 1934 "compilador.tab.c"
    break;

  case 104: /* fator: variavel ABRE_PARENTESES $@22 lista_expressoes FECHA_PARENTESES  */
#line 563 "compilador.y"
        { 
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
#line 1944 "compilador.tab.c"
    break;

  case 110: /* atribuicao: ATRIBUICAO expressao  */
#line 580 "compilador.y"
        {
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		sprintf(varLexDisp, "ARMZ %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp); 
		variavelDestino = NULL;
	}
#line 1956 "compilador.tab.c"
    break;

  case 111: /* variavel: IDENT  */
#line 590 "compilador.y"
              {
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
#line 1979 "compilador.tab.c"
    break;

  case 112: /* numero: NUMERO  */
#line 612 "compilador.y"
        {
		push_pilhaTipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars); 
	}
#line 1990 "compilador.tab.c"
    break;

  case 116: /* simbolo_leitura: IDENT  */
#line 632 "compilador.y"
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
#line 2012 "compilador.tab.c"
    break;

  case 118: /* lista_escrita: lista_escrita VIRGULA expressao  */
#line 656 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 2018 "compilador.tab.c"
    break;

  case 119: /* lista_escrita: expressao  */
#line 657 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 2024 "compilador.tab.c"
    break;


#line 2028 "compilador.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 660 "compilador.y"


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
