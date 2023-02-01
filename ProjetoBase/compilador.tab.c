/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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





#line 122 "compilador.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    INTEGER = 270,
    WHILE = 271,
    DO = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    MAIOR = 276,
    MENOR = 277,
    MAIOR_IGUAL = 278,
    MENOR_IGUAL = 279,
    IGUAL = 280,
    DIFERENTE = 281,
    SOMA = 282,
    SUBTRACAO = 283,
    MULTIPLICACAO = 284,
    DIVISAO = 285,
    DIV = 286,
    NUMERO = 287,
    READ = 288,
    WRITE = 289,
    OR = 290,
    AND = 291,
    NOT = 292,
    PROCEDURE = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    72,    87,    88,    92,    96,   104,   102,
     114,   122,   123,   127,   128,   132,   133,   136,   137,   140,
     145,   140,   152,   158,   166,   171,   180,   182,   209,   210,
     180,   247,   248,   252,   252,   262,   263,   263,   267,   267,
     267,   271,   271,   275,   279,   280,   284,   288,   289,   292,
     295,   296,   297,   298,   299,   300,   301,   305,   309,   325,
     324,   345,   344,   360,   366,   373,   376,   366,   383,   383,
     398,   399,   405,   419,   404,   441,   441,   444,   444,   448,
     453,   457,   458,   459,   460,   461,   462,   466,   470,   470,
     470,   474,   475,   479,   482,   485,   491,   492,   496,   499,
     502,   505,   511,   541,   540,   559,   560,   561,   565,   566,
     570,   581,   602,   613,   617,   618,   622,   643,   647,   648
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "INTEGER", "WHILE",
  "DO", "IF", "THEN", "ELSE", "MAIOR", "MENOR", "MAIOR_IGUAL",
  "MENOR_IGUAL", "IGUAL", "DIFERENTE", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "NUMERO", "READ", "WRITE", "OR",
  "AND", "NOT", "PROCEDURE", "$accept", "programa", "$@1",
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
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

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
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    43,    16,    31,    17,    25,
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
       0,    40,    41,     0,     3,    13,     4,    42,    43,    75,
      13,    56,     7,     5,     6,    12,    45,    47,    50,    51,
      52,    53,    13,    51,     9,    48,    75,    52,    13,    55,
      38,    46,    49,    57,    75,     6,     8,    58,    10,    71,
       7,    13,    15,    44,    13,    32,    72,    73,    74,    75,
     109,    54,    59,     7,    11,    13,    16,    18,    33,    34,
      71,    76,    77,    78,    79,    90,   108,   110,   113,     8,
       7,    60,    73,    91,    94,    95,     4,     4,    20,    81,
      14,    84,    85,    88,   106,   107,     4,    62,    63,    75,
      94,    80,    27,    28,    75,    98,    99,    13,   111,   112,
      94,   114,    82,    94,     4,    64,     7,    17,    19,    21,
      22,    23,    24,    25,    26,    75,    96,    97,     4,    37,
     100,   102,   104,   108,   109,     5,     6,     5,     6,    76,
      83,    86,    65,    66,    61,    92,    76,    98,    94,   104,
      27,    28,    35,   101,    29,    30,    31,    36,   103,     4,
     112,    94,    75,    89,    93,    94,     5,     7,    67,    68,
      45,    71,     5,   102,   102,   102,   104,   104,   104,   104,
     105,     5,     6,    67,    12,    70,    75,    93,    87,    93,
      69,     5,    56,     8,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    44,    46,    45,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    53,
      54,    52,    55,    55,    56,    56,    58,    59,    60,    61,
      57,    62,    62,    64,    63,    65,    66,    65,    68,    69,
      67,    70,    70,    71,    72,    72,    73,    74,    74,    75,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    80,
      79,    82,    81,    83,    85,    86,    87,    84,    88,    84,
      89,    89,    91,    92,    90,    93,    93,    95,    94,    96,
      96,    97,    97,    97,    97,    97,    97,    98,    99,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   105,   104,   104,   104,   104,   106,   106,
     107,   108,   109,   110,   111,   111,   112,   113,   114,   114
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 72 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             }
#line 1532 "compilador.tab.c"
    break;

  case 3:
#line 77 "compilador.y"
                         {
               pop(&tabelaSimbolos, num_vars + proc_declarados);
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1544 "compilador.tab.c"
    break;

  case 7:
#line 96 "compilador.y"
                { setTypes(&tabelaSimbolos, integer, novas_var); }
#line 1550 "compilador.tab.c"
    break;

  case 8:
#line 104 "compilador.y"
                          {
				if(proc_declarados > 0 && nivel_lexico == 0) {
					char command[100];
					sprintf(command, "%s: NADA", RotFimSubrotina);
					geraCodigo(NULL, command); 
					}
				}
#line 1562 "compilador.tab.c"
    break;

  case 10:
#line 114 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		geraCodigo(NULL, amem); 
}
#line 1572 "compilador.tab.c"
    break;

  case 19:
#line 140 "compilador.y"
              { 
              novas_var = 0; 
}
#line 1580 "compilador.tab.c"
    break;

  case 20:
#line 145 "compilador.y"
              {
                num_vars += novas_var;
              }
#line 1588 "compilador.tab.c"
    break;

  case 22:
#line 153 "compilador.y"
              { /* insere �ltima vars na tabela de s�mbolos */ 
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
#line 1598 "compilador.tab.c"
    break;

  case 23:
#line 158 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
                novas_var++;
                novaEntrada = createSimpleVarInput(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
#line 1609 "compilador.tab.c"
    break;

  case 24:
#line 166 "compilador.y"
                                        {
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1619 "compilador.tab.c"
    break;

  case 25:
#line 172 "compilador.y"
        {
		novas_var++;
		novaEntrada = createSimpleFormalParameterInput(token, nivel_lexico, 1, receivingByReference ? referencia : valor);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1629 "compilador.tab.c"
    break;

  case 26:
#line 180 "compilador.y"
                  { EhSubrotina = 1; }
#line 1635 "compilador.tab.c"
    break;

  case 27:
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
		sprintf(rotentrada, "%s: ENPR %d", getRotulo(&tabelaRotulos,1), nivel_lexico);
		geraCodigo(NULL, rotentrada); 
	
		novaEntrada = createSimpleProcedureInput(token, RotInicioSubrotina, nivel_lexico, 0);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1667 "compilador.tab.c"
    break;

  case 28:
#line 209 "compilador.y"
        { novos_param = 0; }
#line 1673 "compilador.tab.c"
    break;

  case 29:
#line 210 "compilador.y"
        {
		// Zera para ser utilizado na subrotina
		// Mas salva valor para ser recuperado
		old_var = num_vars;
		num_vars = 0;
		deslocamento = 0;
	}
#line 1685 "compilador.tab.c"
    break;

  case 30:
#line 218 "compilador.y"
        {
		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, num_vars);
		char dmem[100];
		sprintf(dmem, "DMEM %d", num_vars);
		geraCodigo(NULL, dmem);
		
		// Pega procedimento para printar infos da saida dele
		variavelDestino = getNth(&tabelaSimbolos, num_params + 1);
		if(variavelDestino == NULL) {
			printf("Procedimento nao encontrado na tabela de simbolos.\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", variavelDestino->nivel_lexico, variavelDestino->numParams);
		pop(&tabelaSimbolos, num_params); // Remove parametros da tabela de simbolos

		novos_param = 0;
		geraCodigo(NULL, command);
		nivel_lexico--;

		variavelDestino = NULL; // Libera variavel destino
		num_vars = old_var;    // Restabelece numero de variaveis no nivel lexico
		EhSubrotina = 0;
		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
#line 1716 "compilador.tab.c"
    break;

  case 33:
#line 252 "compilador.y"
                { num_params = 0; }
#line 1722 "compilador.tab.c"
    break;

  case 34:
#line 255 "compilador.y"
        {
		updateParams(getNth(&tabelaSimbolos, num_params + 1),
								&tabelaSimbolos, num_params);
	}
#line 1731 "compilador.tab.c"
    break;

  case 36:
#line 263 "compilador.y"
          { novos_param++; }
#line 1737 "compilador.tab.c"
    break;

  case 38:
#line 267 "compilador.y"
        { num_params++; }
#line 1743 "compilador.tab.c"
    break;

  case 39:
#line 267 "compilador.y"
                                    { novas_var = 0; }
#line 1749 "compilador.tab.c"
    break;

  case 41:
#line 271 "compilador.y"
            {receivingByReference = 1; }
#line 1755 "compilador.tab.c"
    break;

  case 57:
#line 305 "compilador.y"
   { }
#line 1761 "compilador.tab.c"
    break;

  case 58:
#line 310 "compilador.y"
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
#line 1777 "compilador.tab.c"
    break;

  case 59:
#line 325 "compilador.y"
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
#line 1798 "compilador.tab.c"
    break;

  case 61:
#line 345 "compilador.y"
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
#line 1814 "compilador.tab.c"
    break;

  case 64:
#line 366 "compilador.y"
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s,%d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
   	}
#line 1826 "compilador.tab.c"
    break;

  case 65:
#line 373 "compilador.y"
                        {  receivingFormalParams = 1; novos_param = 0; }
#line 1832 "compilador.tab.c"
    break;

  case 66:
#line 376 "compilador.y"
        { 
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc); 
		receivingFormalParams = 0;
	}
#line 1842 "compilador.tab.c"
    break;

  case 67:
#line 381 "compilador.y"
        { variavelDestino = NULL; }
#line 1848 "compilador.tab.c"
    break;

  case 68:
#line 383 "compilador.y"
        {
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s,%d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
#line 1862 "compilador.tab.c"
    break;

  case 69:
#line 392 "compilador.y"
        { 
		entra_procedimento = 0;
	}
#line 1870 "compilador.tab.c"
    break;

  case 72:
#line 405 "compilador.y"
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
#line 1888 "compilador.tab.c"
    break;

  case 73:
#line 419 "compilador.y"
        {
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1898 "compilador.tab.c"
    break;

  case 74:
#line 425 "compilador.y"
        { 
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", getRotulo(&tabelaRotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s: NADA", getRotulo(&tabelaRotulos, 1));
		geraCodigo(NULL, rot);

		pop_pilhaRotulo(&tabelaRotulos, 2);
	}
#line 1914 "compilador.tab.c"
    break;

  case 77:
#line 444 "compilador.y"
        { novos_param++; }
#line 1920 "compilador.tab.c"
    break;

  case 79:
#line 449 "compilador.y"
        { 
		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
#line 1929 "compilador.tab.c"
    break;

  case 81:
#line 457 "compilador.y"
              { strcpy(comparacao, "CMIG"); }
#line 1935 "compilador.tab.c"
    break;

  case 82:
#line 458 "compilador.y"
                    { strcpy(comparacao, "CMDG"); }
#line 1941 "compilador.tab.c"
    break;

  case 83:
#line 459 "compilador.y"
                { strcpy(comparacao, "CMME"); }
#line 1947 "compilador.tab.c"
    break;

  case 84:
#line 460 "compilador.y"
                      { strcpy(comparacao, "CMEG"); }
#line 1953 "compilador.tab.c"
    break;

  case 85:
#line 461 "compilador.y"
                      { strcpy(comparacao, "CMAG"); }
#line 1959 "compilador.tab.c"
    break;

  case 86:
#line 462 "compilador.y"
                { strcpy(comparacao, "CMMA"); }
#line 1965 "compilador.tab.c"
    break;

  case 93:
#line 479 "compilador.y"
                   { 
		verifica_tipo(&tabelaTipo, "soma"); 
		geraCodigo(NULL, "SOMA");}
#line 1973 "compilador.tab.c"
    break;

  case 94:
#line 482 "compilador.y"
                          { 
		verifica_tipo(&tabelaTipo, "subtracao"); 
		geraCodigo(NULL, "SUBT");}
#line 1981 "compilador.tab.c"
    break;

  case 95:
#line 485 "compilador.y"
                   { 
		verifica_tipo(&tabelaTipo, "or"); 
		geraCodigo(NULL, "DISJ");}
#line 1989 "compilador.tab.c"
    break;

  case 98:
#line 496 "compilador.y"
                            { 
		verifica_tipo(&tabelaTipo, "multiplicacao"); 
		geraCodigo(NULL, "MULT");}
#line 1997 "compilador.tab.c"
    break;

  case 99:
#line 499 "compilador.y"
                        { 
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 2005 "compilador.tab.c"
    break;

  case 100:
#line 502 "compilador.y"
                    { 
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 2013 "compilador.tab.c"
    break;

  case 101:
#line 505 "compilador.y"
                    { 
		verifica_tipo(&tabelaTipo, "and"); 
		geraCodigo(NULL, "CONJ"); }
#line 2021 "compilador.tab.c"
    break;

  case 102:
#line 512 "compilador.y"
        {
		if(variavel_carregada != NULL) {
			if(variavel_carregada->category == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s,%d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				sprintf(comando, "CRVL %d,%d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
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
				sprintf(comando, "CRVL %d,%d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
#line 2054 "compilador.tab.c"
    break;

  case 103:
#line 541 "compilador.y"
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
#line 2071 "compilador.tab.c"
    break;

  case 104:
#line 554 "compilador.y"
        { 
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
#line 2081 "compilador.tab.c"
    break;

  case 110:
#line 571 "compilador.y"
        {
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		sprintf(varLexDisp, "ARMZ %d,%d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp); 
		variavelDestino = NULL;
	}
#line 2093 "compilador.tab.c"
    break;

  case 111:
#line 581 "compilador.y"
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
#line 2116 "compilador.tab.c"
    break;

  case 112:
#line 603 "compilador.y"
        {
		push_pilhaTipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars); 
	}
#line 2127 "compilador.tab.c"
    break;

  case 116:
#line 623 "compilador.y"
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
		sprintf(varLexDisp, "ARMZ %d,%d ", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp); 
		variavelDestino = NULL;
	}
#line 2149 "compilador.tab.c"
    break;

  case 118:
#line 647 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 2155 "compilador.tab.c"
    break;

  case 119:
#line 648 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 2161 "compilador.tab.c"
    break;


#line 2165 "compilador.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 651 "compilador.y"


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
