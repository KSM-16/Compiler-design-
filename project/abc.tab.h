
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HASH = 258,
     SHOW = 259,
     READ = 260,
     MCMNT = 261,
     SCMNT = 262,
     FUNC = 263,
     RETURN = 264,
     FUNCEND = 265,
     QUOTE = 266,
     OPENBR1 = 267,
     CLOSEBR1 = 268,
     OPENBR3 = 269,
     CLOSEBR3 = 270,
     MAIN = 271,
     INCLUDE = 272,
     GREATER = 273,
     LESS = 274,
     GREATEREQ = 275,
     LESSEQ = 276,
     MOD = 277,
     ASIN = 278,
     ACOS = 279,
     ATAN = 280,
     SIN = 281,
     COS = 282,
     TAN = 283,
     SQRT = 284,
     POW = 285,
     BIGM = 286,
     FIBO = 287,
     SQ = 288,
     PRIME = 289,
     ISPRM = 290,
     QUBE = 291,
     GCD = 292,
     LCM = 293,
     DOT = 294,
     PLUS = 295,
     MINUS = 296,
     MUL = 297,
     DIV = 298,
     SEMI = 299,
     COMM = 300,
     EQUAL = 301,
     IF = 302,
     ELSE = 303,
     ELIF = 304,
     ENDIF = 305,
     END = 306,
     LOOP = 307,
     BY = 308,
     IN = 309,
     ENDLOOP = 310,
     WHILE = 311,
     ENDWHILE = 312,
     AND = 313,
     OR = 314,
     NOT = 315,
     COLON = 316,
     NEWLINE = 317,
     STRING = 318,
     HEADFILENAME = 319,
     INT = 320,
     CHAR = 321,
     DOUBLE = 322,
     BOOL = 323,
     PERCENT = 324,
     VARNAME = 325,
     DIGIT = 326,
     FLOATVAL = 327,
     CHARACTER = 328,
     TRUE = 329,
     FALSE = 330,
     BOOLVAL = 331
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 65 "abc.y"

  int ival;
  char cval;
  double fval;
  bool bval;
  char *type,*name;
  char *str;
  char c;


/* Line 1676 of yacc.c  */
#line 75 "abc.y"

  struct{
	int ival;
    double fval;
 	char cval;
  	bool bval;
	char *str;
  }vars;



/* Line 1676 of yacc.c  */
#line 152 "abc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


