/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gramatico.y"

    //libs de c

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    //libs de c++
    #include <iostream>
    #include <unordered_map>
    #include <string>
    #include <vector>

    //libs minhas
    #include "defines.hpp"
    #include "comandos.cpp"
    
    //variaveis usadas nos trabalhos anteriores ou importadas do flex
    extern int yylex();
    extern char* yytext;
    extern int yychar;
	extern int last_line;
	extern int n_linhas;
	extern int n_colunas;
    extern "C" void yyerror(const char* s);

    //variaveis usadas para o dcmat propriamente
    bool ender_flag = false;



    //-----------------------------------------------------CODIGO EM SI-----------------------------------------------------//

    //estrutura de dados para a analise semantica
    

    struct MatrizDinamica {
        std::vector<std::vector<int>> dados; // Usando vector para representar a matriz
        int linhas;
        int colunas;
    };

    typedef struct id{
        int type; //0 = int, 1 = real, 2 = matrix
        int value;
        double real_value;
        //armazena a struct de matriz
        MatrizDinamica matrix;
    } id_struct;

    std::unordered_map<std::string, id_struct> symbol_table;

    std::string extrairParteAntesDoCaractere(const std::string& str, char caractere) {
        size_t pos = str.find_first_of(caractere);

        if (pos != std::string::npos) {
            return str.substr(0, pos);
        }else{
            // Retorna uma string vazia se o caractere não for encontrado
            return "";
        }
    }
    

#line 136 "sintatico.yy.cc"

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

#include "sintatico.yy.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_POW = 7,                        /* POW  */
  YYSYMBOL_PORCENT = 8,                    /* PORCENT  */
  YYSYMBOL_LPAREN = 9,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 10,                    /* RPAREN  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 14,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_LBRACKET = 16,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 17,                  /* RBRACKET  */
  YYSYMBOL_SEN = 18,                       /* SEN  */
  YYSYMBOL_COS = 19,                       /* COS  */
  YYSYMBOL_TAN = 20,                       /* TAN  */
  YYSYMBOL_ABS = 21,                       /* ABS  */
  YYSYMBOL_PI = 22,                        /* PI  */
  YYSYMBOL_E = 23,                         /* E  */
  YYSYMBOL_ABOUT = 24,                     /* ABOUT  */
  YYSYMBOL_FLOAT = 25,                     /* FLOAT  */
  YYSYMBOL_SETTINGS = 26,                  /* SETTINGS  */
  YYSYMBOL_H = 27,                         /* H  */
  YYSYMBOL_VIEW = 28,                      /* VIEW  */
  YYSYMBOL_PLOT = 29,                      /* PLOT  */
  YYSYMBOL_SHOW = 30,                      /* SHOW  */
  YYSYMBOL_AXIS = 31,                      /* AXIS  */
  YYSYMBOL_INTEGRAL = 32,                  /* INTEGRAL  */
  YYSYMBOL_STEPS = 33,                     /* STEPS  */
  YYSYMBOL_INTEGRAL_STEPS = 34,            /* INTEGRAL_STEPS  */
  YYSYMBOL_PRECISION = 35,                 /* PRECISION  */
  YYSYMBOL_SOLVE = 36,                     /* SOLVE  */
  YYSYMBOL_CONNECT = 37,                   /* CONNECT  */
  YYSYMBOL_DOTS = 38,                      /* DOTS  */
  YYSYMBOL_INTEGRATE = 39,                 /* INTEGRATE  */
  YYSYMBOL_QUIT = 40,                      /* QUIT  */
  YYSYMBOL_SUM = 41,                       /* SUM  */
  YYSYMBOL_LINEAR = 42,                    /* LINEAR  */
  YYSYMBOL_SYSTEM = 43,                    /* SYSTEM  */
  YYSYMBOL_LINEAR_SYSTEM = 44,             /* LINEAR_SYSTEM  */
  YYSYMBOL_RESET = 45,                     /* RESET  */
  YYSYMBOL_SYMBOLS = 46,                   /* SYMBOLS  */
  YYSYMBOL_DETERMINANT = 47,               /* DETERMINANT  */
  YYSYMBOL_MATRIX = 48,                    /* MATRIX  */
  YYSYMBOL_RPN = 49,                       /* RPN  */
  YYSYMBOL_OFF = 50,                       /* OFF  */
  YYSYMBOL_V = 51,                         /* V  */
  YYSYMBOL_ERASE = 52,                     /* ERASE  */
  YYSYMBOL_ON = 53,                        /* ON  */
  YYSYMBOL_SET = 54,                       /* SET  */
  YYSYMBOL_X = 55,                         /* X  */
  YYSYMBOL_H_VIEW = 56,                    /* H_VIEW  */
  YYSYMBOL_V_VIEW = 57,                    /* V_VIEW  */
  YYSYMBOL_NUM_INT = 58,                   /* NUM_INT  */
  YYSYMBOL_NUM_REAL = 59,                  /* NUM_REAL  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_EOL = 61,                       /* EOL  */
  YYSYMBOL_EOFF = 62,                      /* EOFF  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_S = 64,                         /* S  */
  YYSYMBOL_attribution = 65,               /* attribution  */
  YYSYMBOL_command = 66,                   /* command  */
  YYSYMBOL_solver = 67,                    /* solver  */
  YYSYMBOL_matrix = 68,                    /* matrix  */
  YYSYMBOL_loop_num = 69,                  /* loop_num  */
  YYSYMBOL_loop_matrix = 70,               /* loop_matrix  */
  YYSYMBOL_preSettings = 71,               /* preSettings  */
  YYSYMBOL_posSet = 72,                    /* posSet  */
  YYSYMBOL_plot = 73,                      /* plot  */
  YYSYMBOL_rpn = 74,                       /* rpn  */
  YYSYMBOL_integrate = 75,                 /* integrate  */
  YYSYMBOL_sum = 76,                       /* sum  */
  YYSYMBOL_function = 77,                  /* function  */
  YYSYMBOL_operator = 78,                  /* operator  */
  YYSYMBOL_num = 79,                       /* num  */
  YYSYMBOL_binary = 80                     /* binary  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   131,   131,   132,   133,   134,   135,   136,   137,   138,
     141,   142,   143,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   159,   160,   163,   166,   167,   170,
     171,   174,   175,   178,   179,   180,   181,   182,   183,   184,
     188,   189,   192,   193,   196,   199,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   216,   217,
     218,   219,   220,   221,   224,   225,   228,   229
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS", "MUL",
  "DIV", "POW", "PORCENT", "LPAREN", "RPAREN", "COLON", "EQUALS", "ASSIGN",
  "COMMA", "SEMICOLON", "LBRACKET", "RBRACKET", "SEN", "COS", "TAN", "ABS",
  "PI", "E", "ABOUT", "FLOAT", "SETTINGS", "H", "VIEW", "PLOT", "SHOW",
  "AXIS", "INTEGRAL", "STEPS", "INTEGRAL_STEPS", "PRECISION", "SOLVE",
  "CONNECT", "DOTS", "INTEGRATE", "QUIT", "SUM", "LINEAR", "SYSTEM",
  "LINEAR_SYSTEM", "RESET", "SYMBOLS", "DETERMINANT", "MATRIX", "RPN",
  "OFF", "V", "ERASE", "ON", "SET", "X", "H_VIEW", "V_VIEW", "NUM_INT",
  "NUM_REAL", "IDENTIFIER", "EOL", "EOFF", "$accept", "S", "attribution",
  "command", "solver", "matrix", "loop_num", "loop_matrix", "preSettings",
  "posSet", "plot", "rpn", "integrate", "sum", "function", "operator",
  "num", "binary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,   105,   105,    -2,    15,    20,    23,  -108,  -108,  -108,
      27,   -40,   -21,    38,  -108,    40,  -108,    39,    45,    -4,
    -108,  -108,  -108,    22,  -108,  -108,    55,    43,    44,  -108,
      34,  -108,  -108,  -108,  -108,     6,  -108,    12,   129,   105,
     105,   105,   105,   105,    47,  -108,  -108,  -108,   -15,     3,
      52,   105,    35,   -25,   -15,    53,   -15,   -15,  -108,   -13,
       8,  -108,    13,    24,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,   105,  -108,  -108,   137,   145,   163,   171,   179,
      28,  -108,  -108,    72,    70,    74,  -108,   187,    30,  -108,
    -108,  -108,   -19,    80,    81,  -108,  -108,  -108,  -108,  -108,
    -108,   211,  -108,  -108,  -108,  -108,  -108,  -108,   -15,   -15,
      36,  -108,  -108,  -108,  -108,  -108,   -15,   -15,    85,    84,
      86,  -108,  -108,   105,   -15,    46,    90,   195,    87,    86,
      89,  -108,   105,  -108,    92,  -108,   203,    51,  -108,    96,
      86,   103,    89,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    56,    57,    16,
      40,    31,     0,     0,    14,     0,    32,     0,    42,     0,
      55,    53,    54,    46,     8,     9,     0,     0,     0,    23,
       0,    17,    18,    19,    20,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     1,     0,     0,    13,    58,    59,    60,    61,    62,
      63,     6,     0,     7,    51,     0,     0,     0,     0,     0,
       0,    64,    65,     0,     0,     0,    21,     0,     0,    36,
      35,    38,     0,     0,     0,    10,    11,    12,     4,     3,
       2,    52,    47,    48,    49,    50,    41,     5,     0,     0,
       0,    43,    39,    67,    66,    37,     0,     0,     0,     0,
      28,    33,    34,     0,     0,     0,     0,     0,     0,    28,
      30,    44,     0,    27,     0,    26,     0,     0,    45,     0,
      28,     0,    30,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,    54,  -107,   -12,  -108,  -108,
    -108,  -108,  -108,  -108,    -1,  -108,   -52,  -108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    28,    29,    86,   126,   135,    30,    58,
      31,    32,    33,    34,    35,    72,    83,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    38,    91,    85,    93,    94,    44,    39,    45,    65,
      66,    67,    68,    69,    70,    65,    66,    67,    68,    69,
      70,    52,   133,    46,    40,    89,    47,    53,    90,    41,
      54,   113,    42,   141,   114,    59,    43,    60,    75,    76,
      77,    78,    79,    81,    82,    95,    96,    48,    55,    49,
      87,    50,    56,    57,    51,    61,   118,   119,    62,    63,
      64,     1,    80,    84,   121,   122,     2,    71,    85,    98,
      88,   101,   128,    73,    99,     3,     4,     5,     6,     7,
       8,     9,    92,   108,   109,   100,    10,    11,   112,   107,
     110,   116,   117,    12,   120,   124,    13,    14,    15,   123,
     125,   132,    16,   134,   129,    17,    18,   130,   137,   139,
     140,    19,    20,    97,     2,    21,    22,    23,    24,    25,
     142,     0,   127,     3,     4,     5,     6,     7,     8,     0,
     143,   136,    65,    66,    67,    68,    69,    70,     0,    74,
      65,    66,    67,    68,    69,    70,     0,   102,    65,    66,
      67,    68,    69,    70,     0,   103,     0,     0,     0,     0,
      20,     0,     0,    21,    22,    36,    65,    66,    67,    68,
      69,    70,     0,   104,    65,    66,    67,    68,    69,    70,
       0,   105,    65,    66,    67,    68,    69,    70,     0,   106,
      65,    66,    67,    68,    69,    70,     0,   111,    65,    66,
      67,    68,    69,    70,     0,   131,    65,    66,    67,    68,
      69,    70,     0,   138,    65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
       1,     2,    54,    16,    56,    57,    46,     9,    48,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    25,   129,    44,     9,    50,    47,    31,    53,     9,
      34,    50,     9,   140,    53,    13,     9,    15,    39,    40,
      41,    42,    43,    58,    59,    58,    59,     9,    52,     9,
      51,    12,    56,    57,     9,     0,   108,   109,    15,    15,
      26,     4,    15,    60,   116,   117,     9,    61,    16,    61,
      35,    72,   124,    61,    61,    18,    19,    20,    21,    22,
      23,    24,    29,    11,    14,    61,    29,    30,    58,    61,
      16,    11,    11,    36,    58,    11,    39,    40,    41,    14,
      14,    14,    45,    14,    58,    48,    49,    17,    16,    58,
      14,    54,    55,    59,     9,    58,    59,    60,    61,    62,
      17,    -1,   123,    18,    19,    20,    21,    22,    23,    -1,
     142,   132,     3,     4,     5,     6,     7,     8,    -1,    10,
       3,     4,     5,     6,     7,     8,    -1,    10,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    59,    60,     3,     4,     5,     6,
       7,     8,    -1,    10,     3,     4,     5,     6,     7,     8,
      -1,    10,     3,     4,     5,     6,     7,     8,    -1,    10,
       3,     4,     5,     6,     7,     8,    -1,    10,     3,     4,
       5,     6,     7,     8,    -1,    10,     3,     4,     5,     6,
       7,     8,    -1,    10,     3,     4,     5,     6,     7,     8
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     9,    18,    19,    20,    21,    22,    23,    24,
      29,    30,    36,    39,    40,    41,    45,    48,    49,    54,
      55,    58,    59,    60,    61,    62,    64,    65,    66,    67,
      71,    73,    74,    75,    76,    77,    60,    77,    77,     9,
       9,     9,     9,     9,    46,    48,    44,    47,     9,     9,
      12,     9,    25,    31,    34,    52,    56,    57,    72,    13,
      15,     0,    15,    15,    26,     3,     4,     5,     6,     7,
       8,    61,    78,    61,    10,    77,    77,    77,    77,    77,
      15,    58,    59,    79,    60,    16,    68,    77,    35,    50,
      53,    79,    29,    79,    79,    58,    59,    68,    61,    61,
      61,    77,    10,    10,    10,    10,    10,    61,    11,    14,
      16,    10,    58,    50,    53,    80,    11,    11,    79,    79,
      58,    79,    79,    14,    11,    14,    69,    77,    79,    58,
      17,    10,    14,    69,    14,    70,    77,    16,    10,    58,
      14,    69,    17,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     4,     2,     3,     1,     1,
       3,     3,     3,     2,     1,     2,     1,     1,     1,     1,
       1,     3,     2,     1,     2,     2,     6,     3,     0,     7,
       0,     1,     1,     4,     4,     2,     2,     3,     2,     3,
       1,     4,     1,     4,     8,    10,     1,     4,     4,     4,
       4,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* S: command SEMICOLON EOL  */
#line 131 "gramatico.y"
                               {return ENDL;}
#line 1309 "sintatico.yy.cc"
    break;

  case 3: /* S: attribution SEMICOLON EOL  */
#line 132 "gramatico.y"
                                   {return ENDL;}
#line 1315 "sintatico.yy.cc"
    break;

  case 4: /* S: IDENTIFIER SEMICOLON EOL  */
#line 133 "gramatico.y"
                                  {return ENDL;}
#line 1321 "sintatico.yy.cc"
    break;

  case 5: /* S: SHOW SYMBOLS SEMICOLON EOL  */
#line 134 "gramatico.y"
                                    {return ENDL;}
#line 1327 "sintatico.yy.cc"
    break;

  case 6: /* S: function EOL  */
#line 135 "gramatico.y"
                      {return ENDL;}
#line 1333 "sintatico.yy.cc"
    break;

  case 7: /* S: MINUS function EOL  */
#line 136 "gramatico.y"
                            {return ENDL;}
#line 1339 "sintatico.yy.cc"
    break;

  case 8: /* S: EOL  */
#line 137 "gramatico.y"
             {return ENDL;}
#line 1345 "sintatico.yy.cc"
    break;

  case 9: /* S: EOFF  */
#line 138 "gramatico.y"
              {return ENDL;}
#line 1351 "sintatico.yy.cc"
    break;

  case 10: /* attribution: IDENTIFIER ASSIGN NUM_INT  */
#line 141 "gramatico.y"
                                    {id_struct aux; aux.type = 0; aux.value = atoi(yytext); symbol_table[extrairParteAntesDoCaractere(saver,':')] = aux;}
#line 1357 "sintatico.yy.cc"
    break;

  case 11: /* attribution: IDENTIFIER ASSIGN NUM_REAL  */
#line 142 "gramatico.y"
                                     {id_struct aux; aux.type = 1; aux.real_value = atof(yytext); symbol_table[extrairParteAntesDoCaractere(saver,':')] = aux;}
#line 1363 "sintatico.yy.cc"
    break;

  case 12: /* attribution: IDENTIFIER ASSIGN matrix  */
#line 143 "gramatico.y"
                                   {  }
#line 1369 "sintatico.yy.cc"
    break;

  case 13: /* command: preSettings SETTINGS  */
#line 146 "gramatico.y"
                              {}
#line 1375 "sintatico.yy.cc"
    break;

  case 14: /* command: QUIT  */
#line 147 "gramatico.y"
              {return QUITER;}
#line 1381 "sintatico.yy.cc"
    break;

  case 15: /* command: SET posSet  */
#line 148 "gramatico.y"
                    {}
#line 1387 "sintatico.yy.cc"
    break;

  case 16: /* command: ABOUT  */
#line 149 "gramatico.y"
               {about();}
#line 1393 "sintatico.yy.cc"
    break;

  case 17: /* command: plot  */
#line 150 "gramatico.y"
              {}
#line 1399 "sintatico.yy.cc"
    break;

  case 18: /* command: rpn  */
#line 151 "gramatico.y"
             {}
#line 1405 "sintatico.yy.cc"
    break;

  case 19: /* command: integrate  */
#line 152 "gramatico.y"
                  {}
#line 1411 "sintatico.yy.cc"
    break;

  case 20: /* command: sum  */
#line 153 "gramatico.y"
            {}
#line 1417 "sintatico.yy.cc"
    break;

  case 21: /* command: MATRIX EQUALS matrix  */
#line 154 "gramatico.y"
                             {}
#line 1423 "sintatico.yy.cc"
    break;

  case 22: /* command: SHOW MATRIX  */
#line 155 "gramatico.y"
                    {}
#line 1429 "sintatico.yy.cc"
    break;

  case 23: /* command: solver  */
#line 156 "gramatico.y"
               {}
#line 1435 "sintatico.yy.cc"
    break;

  case 24: /* solver: SOLVE LINEAR_SYSTEM  */
#line 159 "gramatico.y"
                            {}
#line 1441 "sintatico.yy.cc"
    break;

  case 25: /* solver: SOLVE DETERMINANT  */
#line 160 "gramatico.y"
                          {}
#line 1447 "sintatico.yy.cc"
    break;

  case 27: /* loop_num: COMMA NUM_INT loop_num  */
#line 166 "gramatico.y"
                               {}
#line 1453 "sintatico.yy.cc"
    break;

  case 28: /* loop_num: %empty  */
#line 167 "gramatico.y"
         {}
#line 1459 "sintatico.yy.cc"
    break;

  case 29: /* loop_matrix: COMMA LBRACKET NUM_INT COMMA loop_num RBRACKET loop_matrix  */
#line 170 "gramatico.y"
                                                                   {}
#line 1465 "sintatico.yy.cc"
    break;

  case 30: /* loop_matrix: %empty  */
#line 171 "gramatico.y"
         {}
#line 1471 "sintatico.yy.cc"
    break;

  case 31: /* preSettings: SHOW  */
#line 174 "gramatico.y"
              {show_settings();}
#line 1477 "sintatico.yy.cc"
    break;

  case 32: /* preSettings: RESET  */
#line 175 "gramatico.y"
               {reset_settings();}
#line 1483 "sintatico.yy.cc"
    break;

  case 33: /* posSet: H_VIEW num COLON num  */
#line 178 "gramatico.y"
                              {set_h_view(saver);}
#line 1489 "sintatico.yy.cc"
    break;

  case 34: /* posSet: V_VIEW num COLON num  */
#line 179 "gramatico.y"
                              {set_v_view(saver);}
#line 1495 "sintatico.yy.cc"
    break;

  case 35: /* posSet: AXIS ON  */
#line 180 "gramatico.y"
                {set_axis_on();}
#line 1501 "sintatico.yy.cc"
    break;

  case 36: /* posSet: AXIS OFF  */
#line 181 "gramatico.y"
                 {set_axis_off();}
#line 1507 "sintatico.yy.cc"
    break;

  case 37: /* posSet: ERASE PLOT binary  */
#line 182 "gramatico.y"
                          {}
#line 1513 "sintatico.yy.cc"
    break;

  case 38: /* posSet: INTEGRAL_STEPS num  */
#line 183 "gramatico.y"
                           {set_integral_steps(saver);}
#line 1519 "sintatico.yy.cc"
    break;

  case 39: /* posSet: FLOAT PRECISION NUM_INT  */
#line 184 "gramatico.y"
                                {}
#line 1525 "sintatico.yy.cc"
    break;

  case 40: /* plot: PLOT  */
#line 188 "gramatico.y"
             {}
#line 1531 "sintatico.yy.cc"
    break;

  case 41: /* plot: PLOT LPAREN function RPAREN  */
#line 189 "gramatico.y"
                                    {}
#line 1537 "sintatico.yy.cc"
    break;

  case 42: /* rpn: RPN  */
#line 192 "gramatico.y"
            {}
#line 1543 "sintatico.yy.cc"
    break;

  case 43: /* rpn: RPN LPAREN function RPAREN  */
#line 193 "gramatico.y"
                                   {}
#line 1549 "sintatico.yy.cc"
    break;

  case 44: /* integrate: INTEGRATE LPAREN num COLON num COMMA function RPAREN  */
#line 196 "gramatico.y"
                                                             {}
#line 1555 "sintatico.yy.cc"
    break;

  case 45: /* sum: SUM LPAREN IDENTIFIER COMMA num COLON num COMMA function RPAREN  */
#line 199 "gramatico.y"
                                                                        {}
#line 1561 "sintatico.yy.cc"
    break;

  case 46: /* function: IDENTIFIER  */
#line 202 "gramatico.y"
                   {}
#line 1567 "sintatico.yy.cc"
    break;

  case 47: /* function: SEN LPAREN function RPAREN  */
#line 203 "gramatico.y"
                                   {}
#line 1573 "sintatico.yy.cc"
    break;

  case 48: /* function: COS LPAREN function RPAREN  */
#line 204 "gramatico.y"
                                   {}
#line 1579 "sintatico.yy.cc"
    break;

  case 49: /* function: TAN LPAREN function RPAREN  */
#line 205 "gramatico.y"
                                   {}
#line 1585 "sintatico.yy.cc"
    break;

  case 50: /* function: ABS LPAREN function RPAREN  */
#line 206 "gramatico.y"
                                   {}
#line 1591 "sintatico.yy.cc"
    break;

  case 51: /* function: LPAREN function RPAREN  */
#line 207 "gramatico.y"
                               {}
#line 1597 "sintatico.yy.cc"
    break;

  case 52: /* function: function operator function  */
#line 208 "gramatico.y"
                                   {}
#line 1603 "sintatico.yy.cc"
    break;

  case 53: /* function: NUM_INT  */
#line 209 "gramatico.y"
                {}
#line 1609 "sintatico.yy.cc"
    break;

  case 54: /* function: NUM_REAL  */
#line 210 "gramatico.y"
                 {}
#line 1615 "sintatico.yy.cc"
    break;

  case 55: /* function: X  */
#line 211 "gramatico.y"
          {}
#line 1621 "sintatico.yy.cc"
    break;

  case 56: /* function: PI  */
#line 212 "gramatico.y"
           {}
#line 1627 "sintatico.yy.cc"
    break;

  case 57: /* function: E  */
#line 213 "gramatico.y"
          {}
#line 1633 "sintatico.yy.cc"
    break;

  case 58: /* operator: PLUS  */
#line 216 "gramatico.y"
             {}
#line 1639 "sintatico.yy.cc"
    break;

  case 59: /* operator: MINUS  */
#line 217 "gramatico.y"
              {}
#line 1645 "sintatico.yy.cc"
    break;

  case 60: /* operator: MUL  */
#line 218 "gramatico.y"
            {}
#line 1651 "sintatico.yy.cc"
    break;

  case 61: /* operator: DIV  */
#line 219 "gramatico.y"
            {}
#line 1657 "sintatico.yy.cc"
    break;

  case 62: /* operator: POW  */
#line 220 "gramatico.y"
            {}
#line 1663 "sintatico.yy.cc"
    break;

  case 63: /* operator: PORCENT  */
#line 221 "gramatico.y"
                {}
#line 1669 "sintatico.yy.cc"
    break;

  case 64: /* num: NUM_INT  */
#line 224 "gramatico.y"
                 {}
#line 1675 "sintatico.yy.cc"
    break;

  case 65: /* num: NUM_REAL  */
#line 225 "gramatico.y"
                  {}
#line 1681 "sintatico.yy.cc"
    break;

  case 66: /* binary: ON  */
#line 228 "gramatico.y"
            {set_erase_on();}
#line 1687 "sintatico.yy.cc"
    break;

  case 67: /* binary: OFF  */
#line 229 "gramatico.y"
             {set_erase_off();}
#line 1693 "sintatico.yy.cc"
    break;


#line 1697 "sintatico.yy.cc"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 231 "gramatico.y"



extern "C" void yyerror(const char *s) {
    std::cerr << "SYNTAX ERROR: [;]\n";
}

int main(int argc, char **argv) {
    int col = 1;
    while(col != QUITER){
        if (col == ENDL || col != QUITER)
            printf(">");
        col = yyparse();
        saver.clear();
    }

}
