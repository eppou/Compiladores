/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_YY_HH_INCLUDED
# define YY_YY_SINTATICO_YY_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    POW = 262,                     /* POW  */
    PORCENT = 263,                 /* PORCENT  */
    LPAREN = 264,                  /* LPAREN  */
    RPAREN = 265,                  /* RPAREN  */
    COLON = 266,                   /* COLON  */
    EQUALS = 267,                  /* EQUALS  */
    ASSIGN = 268,                  /* ASSIGN  */
    COMMA = 269,                   /* COMMA  */
    SEMICOLON = 270,               /* SEMICOLON  */
    LBRACKET = 271,                /* LBRACKET  */
    RBRACKET = 272,                /* RBRACKET  */
    SEN = 273,                     /* SEN  */
    COS = 274,                     /* COS  */
    TAN = 275,                     /* TAN  */
    ABS = 276,                     /* ABS  */
    PI = 277,                      /* PI  */
    E = 278,                       /* E  */
    ABOUT = 279,                   /* ABOUT  */
    FLOAT = 280,                   /* FLOAT  */
    SETTINGS = 281,                /* SETTINGS  */
    H = 282,                       /* H  */
    VIEW = 283,                    /* VIEW  */
    PLOT = 284,                    /* PLOT  */
    SHOW = 285,                    /* SHOW  */
    AXIS = 286,                    /* AXIS  */
    INTEGRAL = 287,                /* INTEGRAL  */
    STEPS = 288,                   /* STEPS  */
    INTEGRAL_STEPS = 289,          /* INTEGRAL_STEPS  */
    PRECISION = 290,               /* PRECISION  */
    SOLVE = 291,                   /* SOLVE  */
    CONNECT = 292,                 /* CONNECT  */
    DOTS = 293,                    /* DOTS  */
    INTEGRATE = 294,               /* INTEGRATE  */
    QUIT = 295,                    /* QUIT  */
    SUM = 296,                     /* SUM  */
    LINEAR = 297,                  /* LINEAR  */
    SYSTEM = 298,                  /* SYSTEM  */
    LINEAR_SYSTEM = 299,           /* LINEAR_SYSTEM  */
    RESET = 300,                   /* RESET  */
    SYMBOLS = 301,                 /* SYMBOLS  */
    DETERMINANT = 302,             /* DETERMINANT  */
    MATRIX = 303,                  /* MATRIX  */
    RPN = 304,                     /* RPN  */
    OFF = 305,                     /* OFF  */
    V = 306,                       /* V  */
    ERASE = 307,                   /* ERASE  */
    ON = 308,                      /* ON  */
    SET = 309,                     /* SET  */
    X = 310,                       /* X  */
    H_VIEW = 311,                  /* H_VIEW  */
    V_VIEW = 312,                  /* V_VIEW  */
    NUM_INT = 313,                 /* NUM_INT  */
    NUM_REAL = 314,                /* NUM_REAL  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
    EOL = 316,                     /* EOL  */
    EOFF = 317                     /* EOFF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_YY_HH_INCLUDED  */
