
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "abc.y"

#include <bits/stdc++.h>
using namespace std;	

extern string yytext;
extern int yylex();
extern int yyparse();
extern FILE *yyin,*yyout;
void yyerror(const char *s);

#define pi acos(-1)
bool isprime[100005];
vector<int>pr;
int currentex = 0;
int ifelfound = 0;
void siv()
{
pr.push_back(2);
for(int i=3;i*i<=100000;i+=2)
	if(isprime[i]==0)
		for(int j=i*i;j<=100000;j+=2*i) isprime[j]=1;
for(int i=3;i<=100000;i+=2)
	if(isprime[i]==0) pr.push_back(i);
}

int bigmod(int a,int b,int c){
	if(b==0) return 1;
	if(b==1) return a%c;
	int x=bigmod(a,b/2,c)%c;
	x=(x*x)%c;
	if(b%2) return (a*x)%c;
	else return x;
}
map<string,int>varmap;
map<string,int>ivar;
map<string,vector<int> >aivar;
map<string,double>dvar;
map<string,vector<double> >advar;
map<string,char>cvar;
map<string,vector<char> >acvar;
map<string,bool>bvar;
map<string,vector<bool> >abvar;
void create_array(string name,int size,int type)
{
	if(type == 6){
		for(int i = 0 ; i < size ; i++)
			aivar[name].push_back(0);
	}
	else if(type == 8){
		for(int i = 0 ; i < size ; i++)
			advar[name].push_back(0.0);
	}
	else if(type == 9){
		for(int i = 0 ; i < size ; i++)
			acvar[name].push_back('#');
	}
	else if(type == 10){
		for(int i = 0 ; i < size ; i++)
			abvar[name].push_back(false);
	}
}



/* Line 189 of yacc.c  */
#line 138 "abc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 65 "abc.y"

  int ival;
  char cval;
  double fval;
  bool bval;
  char *type,*name;
  char *str;
  char c;


/* Line 214 of yacc.c  */
#line 75 "abc.y"

  struct{
	int ival;
    double fval;
 	char cval;
  	bool bval;
	char *str;
  }vars;



/* Line 214 of yacc.c  */
#line 274 "abc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 286 "abc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  318

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    10,    13,    19,    20,    23,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    53,    59,    65,    69,    76,    78,    80,    82,    84,
      86,    91,    97,   106,   112,   113,   115,   117,   122,   124,
     126,   128,   130,   132,   137,   141,   145,   147,   151,   155,
     157,   161,   163,   165,   167,   172,   177,   183,   186,   190,
     194,   196,   201,   206,   210,   214,   218,   222,   226,   228,
     232,   234,   236,   238,   240,   242,   244,   249,   256,   262,
     264,   270,   275,   279,   292,   294,   296,   298,   300,   302,
     307,   312,   314,   316,   318,   319,   322,   332,   333,   335,
     336,   342,   346,   350,   354,   362,   370,   376,   382,   388,
     394,   400,   406,   414,   424,   432,   438,   444,   450,   456,
     462,   468,   470
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      78,     0,    -1,    79,   107,    16,    81,    51,    -1,    -1,
      79,    80,    -1,     3,    17,    19,    64,    18,    -1,    -1,
      81,    82,    -1,    85,    -1,    86,    -1,    83,    -1,    90,
      -1,    94,    -1,    99,    -1,   101,    -1,   103,    -1,   106,
      -1,   104,    -1,   105,    -1,   112,    -1,    89,    70,    46,
      84,    44,    -1,    89,    70,    46,    88,    44,    -1,    89,
      70,    46,    91,    44,    -1,    89,    70,    44,    -1,    89,
      70,    14,    71,    15,    44,    -1,    71,    -1,    72,    -1,
      73,    -1,    76,    -1,    63,    -1,    70,    14,   102,    15,
      -1,     5,    12,    70,    13,    44,    -1,     5,    12,    70,
      14,   102,    15,    13,    44,    -1,     4,    12,    87,    13,
      44,    -1,    -1,    63,    -1,    70,    -1,    70,    14,   102,
      15,    -1,    70,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    70,    46,    91,    44,    -1,    91,    40,    92,
      -1,    91,    41,    92,    -1,    92,    -1,    92,    42,    93,
      -1,    92,    43,    93,    -1,    93,    -1,    12,    91,    13,
      -1,    70,    -1,    71,    -1,    72,    -1,    70,    14,   102,
      15,    -1,    70,    46,    95,    44,    -1,    89,    70,    46,
      95,    44,    -1,    60,    95,    -1,    95,    58,    96,    -1,
      95,    59,    96,    -1,    96,    -1,    96,    46,    46,    97,
      -1,    96,    60,    46,    97,    -1,    96,    18,    97,    -1,
      96,    20,    97,    -1,    96,    19,    97,    -1,    96,    21,
      97,    -1,    12,    95,    13,    -1,    97,    -1,    12,    95,
      13,    -1,    98,    -1,    76,    -1,    71,    -1,    72,    -1,
      70,    -1,    73,    -1,    70,    14,   102,    15,    -1,    47,
      95,    61,    99,   100,    50,    -1,    47,    95,    61,    99,
      50,    -1,    90,    -1,    49,    95,    61,    99,   100,    -1,
      49,    95,    61,    99,    -1,    48,    61,    99,    -1,    52,
      70,    54,   102,    39,    39,   102,    53,   102,    61,    90,
      55,    -1,    70,    -1,    71,    -1,    67,    -1,    73,    -1,
      76,    -1,    70,    14,   102,    15,    -1,    56,    95,    90,
      57,    -1,     7,    -1,     6,    -1,    44,    -1,    -1,   108,
     107,    -1,     8,    89,    70,    12,   110,    13,   109,   111,
      10,    -1,    -1,    90,    -1,    -1,    89,    61,    70,    45,
     110,    -1,    89,    61,    70,    -1,     9,    84,    44,    -1,
       9,    70,    44,    -1,    37,    12,   102,    45,   102,    13,
      44,    -1,    38,    12,   102,    45,   102,    13,    44,    -1,
      29,    12,    72,    13,    44,    -1,    33,    12,    72,    13,
      44,    -1,    36,    12,    72,    13,    44,    -1,    35,    12,
     102,    13,    44,    -1,    34,    12,   102,    13,    44,    -1,
      32,    12,   102,    13,    44,    -1,    30,    12,   113,    45,
     113,    13,    44,    -1,    31,    12,   102,    45,   102,    45,
     102,    13,    44,    -1,    22,    12,   102,    45,   102,    13,
      44,    -1,    26,    12,    72,    13,    44,    -1,    27,    12,
      72,    13,    44,    -1,    28,    12,    72,    13,    44,    -1,
      23,    12,    72,    13,    44,    -1,    24,    12,    72,    13,
      44,    -1,    25,    12,    72,    13,    44,    -1,    71,    -1,
      72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   122,   123,   125,   127,   128,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     144,   152,   161,   169,   177,   186,   187,   188,   189,   190,
     191,   200,   208,   216,   218,   219,   220,   228,   236,   245,
     246,   247,   248,   251,   259,   260,   261,   263,   264,   265,
     267,   268,   275,   276,   277,   284,   289,   294,   295,   296,
     297,   299,   300,   301,   302,   303,   304,   305,   306,   308,
     309,   311,   312,   313,   314,   321,   322,   330,   331,   332,
     334,   335,   336,   338,   351,   356,   357,   358,   359,   360,
     366,   370,   372,   374,   376,   377,   379,   381,   382,   384,
     385,   390,   397,   398,   401,   402,   403,   404,   405,   406,
     408,   409,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   421,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "SHOW", "READ", "MCMNT", "SCMNT",
  "FUNC", "RETURN", "FUNCEND", "QUOTE", "OPENBR1", "CLOSEBR1", "OPENBR3",
  "CLOSEBR3", "MAIN", "INCLUDE", "GREATER", "LESS", "GREATEREQ", "LESSEQ",
  "MOD", "ASIN", "ACOS", "ATAN", "SIN", "COS", "TAN", "SQRT", "POW",
  "BIGM", "FIBO", "SQ", "PRIME", "ISPRM", "QUBE", "GCD", "LCM", "DOT",
  "PLUS", "MINUS", "MUL", "DIV", "SEMI", "COMM", "EQUAL", "IF", "ELSE",
  "ELIF", "ENDIF", "END", "LOOP", "BY", "IN", "ENDLOOP", "WHILE",
  "ENDWHILE", "AND", "OR", "NOT", "COLON", "NEWLINE", "STRING",
  "HEADFILENAME", "INT", "CHAR", "DOUBLE", "BOOL", "PERCENT", "VARNAME",
  "DIGIT", "FLOATVAL", "CHARACTER", "TRUE", "FALSE", "BOOLVAL", "$accept",
  "START", "hdrs", "header", "LINE", "ST", "VD", "VALUE", "read", "show",
  "SHOWSTR", "VARIABLE", "TYPE", "EXP", "EX", "T", "F", "condx", "CONDX",
  "A", "B", "C", "IFELSE", "else", "FL", "NUMVALUE", "WH", "singlecomment",
  "multicomment", "empty", "funcs", "func", "exp", "PARAMLIST", "returns",
  "fcall", "NUMV", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    87,    87,    87,    87,    88,    89,
      89,    89,    89,    90,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   100,   101,   102,   102,   102,   102,   102,   102,
     103,   104,   105,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     5,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     3,     6,     1,     1,     1,     1,     1,
       4,     5,     8,     5,     0,     1,     1,     4,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     4,     4,     5,     2,     3,     3,
       1,     4,     4,     3,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     6,     5,     1,
       5,     4,     3,    12,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     0,     2,     9,     0,     1,     0,
       5,     3,     3,     3,     7,     7,     5,     5,     5,     5,
       5,     5,     7,     9,     7,     5,     5,     5,     5,     5,
       5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    94,     1,     0,     0,     4,     0,    94,     0,
      39,    40,    41,    42,     0,     6,    95,     0,     0,     0,
       0,    99,     0,     0,    92,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     2,     0,     0,     0,     7,
      10,     8,     9,     0,    11,    12,    13,    14,    15,    17,
      18,    16,    19,     5,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    72,    73,
      75,    71,     0,    60,    68,    70,     0,     0,     0,     0,
       0,    97,    35,    36,     0,     0,    86,    84,    85,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    72,    73,     0,
      46,    49,     0,     0,    23,     0,   101,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    58,    59,    79,     0,     0,    63,    65,
      64,    66,     0,     0,     0,     0,    90,     0,     0,     0,
       0,    43,     0,     0,    55,     0,    29,    74,    72,    73,
      75,    71,     0,     0,     0,     0,    99,     0,     0,     0,
      33,    31,     0,     0,     0,   118,   119,   120,   115,   116,
     117,   106,     0,     0,   111,   107,   110,   109,   108,     0,
       0,    76,     0,     0,    78,     0,     0,    61,    62,     0,
       0,    51,    52,    53,    50,     0,    44,    45,    47,    48,
       0,     0,    20,    21,    22,    56,   100,     0,    25,    26,
      27,    28,     0,    96,    37,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    77,    69,     0,     0,    76,    24,
       0,     0,   103,   102,     0,   114,   112,     0,   104,   105,
      82,     0,     0,     0,    76,     0,    32,     0,    81,     0,
      54,    30,   113,    80,     0,     0,     0,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    19,    49,    50,   212,    51,    52,
     104,   213,    64,   185,   149,   150,   151,    55,   130,    93,
      94,    95,    56,   245,    57,   111,    58,    59,    60,    61,
       7,     8,   158,    65,   218,    62,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
    -136,    30,    25,  -136,    15,   139,  -136,    39,    50,    41,
    -136,  -136,  -136,  -136,    -5,  -136,  -136,    12,    97,   101,
      99,   139,   135,   146,  -136,  -136,   172,   184,   197,   202,
     209,   231,   234,   237,   251,   252,   253,   254,   255,   256,
     257,   258,   259,  -136,    19,  -136,    81,    19,   142,  -136,
    -136,  -136,  -136,   203,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,   211,   261,   -29,   205,   177,   204,
     206,   207,   208,   210,   212,   213,    13,   177,   177,   215,
     177,   177,   216,   177,   177,    19,    19,   263,  -136,  -136,
    -136,  -136,    35,    -6,  -136,  -136,   227,   -21,    40,     2,
     219,   220,  -136,   269,   273,   136,  -136,   277,  -136,  -136,
    -136,   247,   280,   281,   282,   284,   285,   286,   287,  -136,
    -136,   260,   262,   288,   289,   290,   291,   293,   264,   265,
       5,    96,   177,    89,    89,   -28,   106,   106,   106,   106,
     266,   267,   177,   268,   270,    40,   150,   157,   176,    33,
     144,  -136,   -23,   240,  -136,    -1,   271,  -136,   299,   177,
     274,   275,   177,   177,   177,   276,   278,   279,   292,   294,
     295,   296,    13,   177,   297,   298,   300,   301,   302,   177,
     177,  -136,   306,    -6,    -6,  -136,   124,    19,  -136,  -136,
    -136,  -136,   106,   106,   304,    49,  -136,    10,   177,    49,
      49,  -136,    49,    49,  -136,   309,  -136,   194,   100,   187,
     303,   305,   307,   308,    58,   -15,   139,   169,   315,   311,
    -136,  -136,   313,   314,   317,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   318,   272,  -136,  -136,  -136,  -136,  -136,   319,
     320,  -136,   310,    19,  -136,   312,     9,  -136,  -136,   316,
      49,   321,  -136,  -136,  -136,   322,   144,   144,  -136,  -136,
     323,   177,  -136,  -136,  -136,  -136,  -136,     3,  -136,  -136,
    -136,  -136,   324,  -136,  -136,   335,  -136,   325,   326,   177,
     328,   329,   -28,   122,  -136,  -136,   177,   177,   182,  -136,
     338,   177,  -136,  -136,   330,  -136,  -136,   337,  -136,  -136,
    -136,   -28,   327,   339,   214,   341,  -136,   331,   164,   177,
    -136,  -136,  -136,  -136,   332,   220,   333,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,  -136,  -136,    98,  -136,  -136,
    -136,  -136,    34,   -19,  -135,    52,    57,  -136,   -41,   128,
    -112,  -136,  -126,    26,  -136,   -76,  -136,  -136,  -136,  -136,
     349,  -136,  -136,   143,  -136,  -136,   186
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      54,   122,   123,    92,   125,   126,    97,   128,   129,   186,
     197,   145,   136,   137,   138,   139,   153,   291,   181,    44,
     214,   204,   285,   254,   188,   189,   190,   191,     4,   265,
       3,    85,     9,     5,   102,   133,   134,   133,   134,    14,
     140,   103,   143,   133,   134,   131,   154,   292,   155,   143,
     199,   200,   145,    53,   141,    15,   182,   152,     5,    86,
      17,   250,   206,   133,   134,    18,   194,   133,   134,   207,
     208,   209,   210,   199,   200,   211,    20,   201,   144,    86,
     247,   248,   157,   219,   119,   120,   222,   223,   224,    87,
      88,    89,    90,   133,   134,    91,   135,   233,   199,   200,
      86,    85,   264,   239,   240,    22,    23,    24,    25,    21,
     146,   147,   148,    90,   215,   197,    91,    63,   187,   251,
     252,   253,   255,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     -52,   -52,   -52,   -52,   -25,    43,   246,    66,    44,   161,
     162,    96,    45,    46,   133,   134,   300,    47,    67,    87,
      88,    89,    90,   -51,   198,    91,    10,    11,    12,    13,
     -52,    48,   242,   243,   244,   308,    87,    88,    89,    90,
     133,   134,    91,   301,    68,   290,   202,   203,    98,   -53,
     -51,   -51,   -51,   -51,   -51,   -54,    69,   -52,   -52,   -52,
     -52,   -52,   283,   297,    10,    11,    12,    13,   261,    70,
     302,   303,   242,   243,    71,   305,   -53,   -53,   -53,   -53,
     -53,    72,   -54,   -54,   -54,   -54,   -54,   -53,   -53,   -53,
     -53,   -26,   206,   314,   -51,   -51,   -51,   -51,   -38,   267,
     268,   269,   270,    73,   106,   271,    74,   107,   108,    75,
     109,   256,   257,   110,   -54,   -54,   -54,   -54,   -30,   258,
     259,   183,   184,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   100,    99,   101,   105,   112,   132,   113,   114,
     115,   142,   116,   159,   117,   118,   160,   124,   127,   156,
     143,   163,   164,   165,   166,   167,   316,   168,   169,   170,
     171,   174,   175,   176,   177,   172,   178,   173,   217,   179,
     180,   205,   192,   193,   195,   272,   216,   279,   220,   221,
     225,   241,   226,   227,   260,   273,   274,   196,   275,   276,
     277,   278,   280,   281,   313,   287,   228,   288,   229,   230,
     231,   234,   235,   249,   236,   237,   238,   -27,   294,   -28,
     307,   262,   263,   304,   310,   286,   311,    16,   232,   266,
       0,     0,   284,     0,     0,     0,     0,   289,   293,   295,
     296,   282,   298,   299,   306,   312,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,   317,     0,
       0,     0,     0,   315
};

static const yytype_int16 yycheck[] =
{
      19,    77,    78,    44,    80,    81,    47,    83,    84,   135,
     145,    12,    18,    19,    20,    21,    14,    14,    13,    47,
     155,    44,    13,    13,   136,   137,   138,   139,     3,    44,
       0,    12,    17,     8,    63,    58,    59,    58,    59,     5,
      46,    70,    70,    58,    59,    86,    44,    44,    46,    70,
      40,    41,    12,    19,    60,    16,   132,    98,     8,    60,
      19,    12,    63,    58,    59,    70,   142,    58,    59,    70,
      71,    72,    73,    40,    41,    76,    64,    44,    97,    60,
     192,   193,   101,   159,    71,    72,   162,   163,   164,    70,
      71,    72,    73,    58,    59,    76,    61,   173,    40,    41,
      60,    12,    44,   179,   180,     4,     5,     6,     7,    12,
      70,    71,    72,    73,   155,   250,    76,    18,    12,    70,
      71,    72,   198,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      40,    41,    42,    43,    44,    44,   187,    12,    47,    13,
      14,    70,    51,    52,    58,    59,   282,    56,    12,    70,
      71,    72,    73,    13,    14,    76,    65,    66,    67,    68,
      13,    70,    48,    49,    50,   301,    70,    71,    72,    73,
      58,    59,    76,    61,    12,   261,    42,    43,    46,    13,
      40,    41,    42,    43,    44,    13,    12,    40,    41,    42,
      43,    44,   243,   279,    65,    66,    67,    68,    14,    12,
     286,   287,    48,    49,    12,   291,    40,    41,    42,    43,
      44,    12,    40,    41,    42,    43,    44,    40,    41,    42,
      43,    44,    63,   309,    40,    41,    42,    43,    44,    70,
      71,    72,    73,    12,    67,    76,    12,    70,    71,    12,
      73,   199,   200,    76,    40,    41,    42,    43,    44,   202,
     203,   133,   134,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    61,    70,    13,    70,    72,    14,    72,    72,
      72,    54,    72,    14,    72,    72,    13,    72,    72,    70,
      70,    14,    45,    13,    13,    13,   315,    13,    13,    13,
      13,    13,    13,    13,    13,    45,    13,    45,     9,    45,
      45,    71,    46,    46,    46,   217,    45,    45,    44,    44,
      44,    15,    44,    44,    15,    10,    15,    57,    15,    15,
      13,    13,    13,    13,   308,    14,    44,    15,    44,    44,
      44,    44,    44,    39,    44,    44,    44,    44,    13,    44,
      13,    44,    44,    15,    15,    39,    15,     8,   172,   216,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    44,    44,    44,
      44,    61,    44,    44,    44,    44,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,    79,     0,     3,     8,    80,   107,   108,    17,
      65,    66,    67,    68,    89,    16,   107,    19,    70,    81,
      64,    12,     4,     5,     6,     7,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    44,    47,    51,    52,    56,    70,    82,
      83,    85,    86,    89,    90,    94,    99,   101,   103,   104,
     105,   106,   112,    18,    89,   110,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    60,    70,    71,    72,
      73,    76,    95,    96,    97,    98,    70,    95,    46,    70,
      61,    13,    63,    70,    87,    70,    67,    70,    71,    73,
      76,   102,    72,    72,    72,    72,    72,    72,    72,    71,
      72,   113,   102,   102,    72,   102,   102,    72,   102,   102,
      95,    95,    14,    58,    59,    61,    18,    19,    20,    21,
      46,    60,    54,    70,    90,    12,    70,    71,    72,    91,
      92,    93,    95,    14,    44,    46,    70,    90,   109,    14,
      13,    13,    14,    14,    45,    13,    13,    13,    13,    13,
      13,    13,    45,    45,    13,    13,    13,    13,    13,    45,
      45,    13,   102,    96,    96,    90,    99,    12,    97,    97,
      97,    97,    46,    46,   102,    46,    57,    91,    14,    40,
      41,    44,    42,    43,    44,    71,    63,    70,    71,    72,
      73,    76,    84,    88,    91,    95,    45,     9,   111,   102,
      44,    44,   102,   102,   102,    44,    44,    44,    44,    44,
      44,    44,   113,   102,    44,    44,    44,    44,    44,   102,
     102,    15,    48,    49,    50,   100,    95,    97,    97,    39,
      12,    70,    71,    72,    13,   102,    92,    92,    93,    93,
      15,    14,    44,    44,    44,    44,   110,    70,    71,    72,
      73,    76,    84,    10,    15,    15,    15,    13,    13,    45,
      13,    13,    61,    95,    50,    13,    39,    14,    15,    44,
     102,    14,    44,    44,    13,    44,    44,   102,    44,    44,
      99,    61,   102,   102,    15,   102,    44,    13,    99,    53,
      15,    15,    44,   100,   102,    61,    90,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 120 "abc.y"
    {  cout << "//Main function executed successfully" << endl; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "abc.y"
    { cout << "//Header file " << (yyvsp[(4) - (5)].str) << " included" << endl; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 132 "abc.y"
    {cout<<endl;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 133 "abc.y"
    { cout << endl; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 134 "abc.y"
    { cout << "Result of expression = " << (yyvsp[(1) - (1)].fval) << endl; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 136 "abc.y"
    { cout << "//Value of if-else block : " << (yyvsp[(1) - (1)].fval) << endl; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 144 "abc.y"
    { if( varmap.find((yyvsp[(2) - (5)].name)) == varmap.end() ){
						if(strcmp((yyvsp[(1) - (5)].type),"int") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with " << (yyvsp[(4) - (5)].vars).ival ; varmap[(yyvsp[(2) - (5)].name)] = 1; ivar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).ival; } 
						else if(strcmp((yyvsp[(1) - (5)].type),"double") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).fval ; varmap[(yyvsp[(2) - (5)].name)] = 3; dvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).fval; }
						else if(strcmp((yyvsp[(1) - (5)].type),"char") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).cval ; varmap[(yyvsp[(2) - (5)].name)] = 4; cvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).cval;  }
						else if(strcmp((yyvsp[(1) - (5)].type),"bool") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).bval ; varmap[(yyvsp[(2) - (5)].name)] = 5; bvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).bval; }
						}
						else { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (5)].name)); yyerror(" previously declared"); exit(-1); }
						;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "abc.y"
    { if( varmap.find((yyvsp[(2) - (5)].name)) == varmap.end() )
						{
						if(strcmp((yyvsp[(1) - (5)].type),"int") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).ival ; varmap[(yyvsp[(2) - (5)].name)] = 1; ivar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).ival;  } 
						else if(strcmp((yyvsp[(1) - (5)].type),"double") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).fval ; varmap[(yyvsp[(2) - (5)].name)] = 3; dvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).fval; }
						else if(strcmp((yyvsp[(1) - (5)].type),"char") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).cval ; varmap[(yyvsp[(2) - (5)].name)] = 4; cvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).cval; }
						else if(strcmp((yyvsp[(1) - (5)].type),"bool") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).bval ; varmap[(yyvsp[(2) - (5)].name)] = 5; bvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).bval; }
						}
						else { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (5)].name)); yyerror(" previously declared");  exit(-1);}
						;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 161 "abc.y"
    { if( varmap.find((yyvsp[(2) - (5)].name)) == varmap.end() ){
						if(strcmp((yyvsp[(1) - (5)].type),"int") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).ival ; varmap[(yyvsp[(2) - (5)].name)] = 1; ivar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).ival; } 
						else if(strcmp((yyvsp[(1) - (5)].type),"double") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).fval ; varmap[(yyvsp[(2) - (5)].name)] = 3; dvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).fval; }
						else if(strcmp((yyvsp[(1) - (5)].type),"char") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).cval ; varmap[(yyvsp[(2) - (5)].name)] = 4; cvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).cval; }
						else if(strcmp((yyvsp[(1) - (5)].type),"bool") == 0) {cout << "//"<<(yyvsp[(1) - (5)].type)<<" Variable " << (yyvsp[(2) - (5)].name)  << " is initialized with "<< (yyvsp[(4) - (5)].vars).bval ; varmap[(yyvsp[(2) - (5)].name)] = 5; bvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].vars).bval; }
						}
						else { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (5)].name)); yyerror(" previously declared"); exit(-1); }
						;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 169 "abc.y"
    { if( varmap.find((yyvsp[(2) - (3)].name)) == varmap.end() ){
						if(strcmp((yyvsp[(1) - (3)].type),"int") == 0) {cout << "//"<<(yyvsp[(1) - (3)].type)<<" Variable " << (yyvsp[(2) - (3)].name)  << " is initialized with "<< 0 ; varmap[(yyvsp[(2) - (3)].name)] = 1; ivar[(yyvsp[(2) - (3)].name)] = 0; } 
						else if(strcmp((yyvsp[(1) - (3)].type),"double") == 0) {cout << "//"<<(yyvsp[(1) - (3)].type)<<" Variable " << (yyvsp[(2) - (3)].name)  << " is initialized with "<< 0.0 ; varmap[(yyvsp[(2) - (3)].name)] = 3; dvar[(yyvsp[(2) - (3)].name)] = 0.0; }
						else if(strcmp((yyvsp[(1) - (3)].type),"char") == 0) {cout << "//"<<(yyvsp[(1) - (3)].type)<<" Variable " << (yyvsp[(2) - (3)].name)  << " is initialized with #" ; varmap[(yyvsp[(2) - (3)].name)] = 4; cvar[(yyvsp[(2) - (3)].name)] = '#';}
						else if(strcmp((yyvsp[(1) - (3)].type),"bool") == 0) {cout << "//"<<(yyvsp[(1) - (3)].type)<<" Variable " << (yyvsp[(2) - (3)].name)  << " is initialized with false" ; varmap[(yyvsp[(2) - (3)].name)] = 5; bvar[(yyvsp[(2) - (3)].name)] = false; }
						}
						else { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (3)].name)); yyerror(" previously declared"); exit(-1); }
						;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 177 "abc.y"
    { if( varmap.find((yyvsp[(2) - (6)].name)) == varmap.end() ){
							if(strcmp((yyvsp[(1) - (6)].type),"int") == 0) { cout <<"//"<<(yyvsp[(1) - (6)].type)<<" Array " << (yyvsp[(2) - (6)].name) << " of size " <<(yyvsp[(4) - (6)].ival)<<" is declared." ; varmap[(yyvsp[(2) - (6)].name)] = 6;  create_array((yyvsp[(2) - (6)].name),(yyvsp[(4) - (6)].ival),6); } 
							else if(strcmp((yyvsp[(1) - (6)].type),"double") == 0) { cout <<"//"<<(yyvsp[(1) - (6)].type)<<" Array " << (yyvsp[(2) - (6)].name) << " of size " <<(yyvsp[(4) - (6)].ival)<<" is declared." ; varmap[(yyvsp[(2) - (6)].name)] = 8;  create_array((yyvsp[(2) - (6)].name),(yyvsp[(4) - (6)].ival),8);}
							else if(strcmp((yyvsp[(1) - (6)].type),"char") == 0) { cout <<"//"<<(yyvsp[(1) - (6)].type)<<" Array " << (yyvsp[(2) - (6)].name) << " of size " <<(yyvsp[(4) - (6)].ival)<<" is declared." ; varmap[(yyvsp[(2) - (6)].name)] = 9;  create_array((yyvsp[(2) - (6)].name),(yyvsp[(4) - (6)].ival),9);}
							else if(strcmp((yyvsp[(1) - (6)].type),"bool") == 0) { cout <<"//"<<(yyvsp[(1) - (6)].type)<<" Array " << (yyvsp[(2) - (6)].name) << " of size " <<(yyvsp[(4) - (6)].ival)<<" is declared." ; varmap[(yyvsp[(2) - (6)].name)] = 10; create_array((yyvsp[(2) - (6)].name),(yyvsp[(4) - (6)].ival),10);}
							}
							else { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (6)].name)); yyerror(" previously declared");  exit(-1); }
							;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 186 "abc.y"
    {(yyval.vars).ival = (yyvsp[(1) - (1)].ival); currentex = 1;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "abc.y"
    {(yyval.vars).fval = (yyvsp[(1) - (1)].fval); currentex = 2;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 188 "abc.y"
    {(yyval.vars).cval = (yyvsp[(1) - (1)].cval); currentex = 4;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 189 "abc.y"
    {(yyval.vars).bval = (yyvsp[(1) - (1)].bval); currentex = 5;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 190 "abc.y"
    {(yyval.vars).str = (yyvsp[(1) - (1)].str);  currentex = 0;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 191 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[(yyvsp[(1) - (4)].name)] == 6) { if( (yyvsp[(3) - (4)].ival) <= aivar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).ival = aivar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 8) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).fval = advar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 9) { if( (yyvsp[(3) - (4)].ival) <= acvar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).cval = acvar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 10) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).bval = abvar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
							};}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 200 "abc.y"
    {
									if(varmap.find((yyvsp[(3) - (5)].name)) == varmap.end()) { yyerror("Error : Variable "); cout << (yyvsp[(3) - (5)].name) ; yyerror(" not declared\n"); exit(-1);}
			  		  				else {
										if(varmap[(yyvsp[(3) - (5)].name)] == 1) { if(currentex == 1) { int a; scanf("%d",&a); ivar[(yyvsp[(3) - (5)].name)] = a;cout <<"Value of "<<(yyvsp[(3) - (5)].name)<< " read as " <<a<< endl;}  } 								
										else if(varmap[(yyvsp[(3) - (5)].name)] == 3) { if(currentex == 2) {double a; scanf("lf",&a); dvar[(yyvsp[(3) - (5)].name)] = a;cout <<"Value of "<<(yyvsp[(3) - (5)].name)<<" read as "<<a<<endl; } } 
										else if(varmap[(yyvsp[(3) - (5)].name)] == 4) { if(currentex == 4) {char a; scanf("%c",&a); cvar[(yyvsp[(3) - (5)].name)] = a;cout <<"Value of "<<(yyvsp[(3) - (5)].name)<<" read as "<<a<< endl; } } 
									}
									;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 208 "abc.y"
    { 
							if(varmap.find((yyvsp[(3) - (8)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(3) - (8)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[(yyvsp[(3) - (8)].name)] == 6) { if( (yyvsp[(5) - (8)].ival) <= aivar[(yyvsp[(3) - (8)].name)].size()){  int a; scanf("%d",&a); aivar[(yyvsp[(3) - (8)].name)][(yyvsp[(5) - (8)].ival)] = a; cout << "Value of " << (yyvsp[(3) - (8)].name) << "[" << (yyvsp[(5) - (8)].ival) << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(3) - (8)].name)] == 8) { if( (yyvsp[(5) - (8)].ival) <= advar[(yyvsp[(3) - (8)].name)].size()){ double a; scanf("lf",&a); advar[(yyvsp[(3) - (8)].name)][(yyvsp[(5) - (8)].ival)] = a; cout << "Value of " << (yyvsp[(3) - (8)].name) << "[" << (yyvsp[(5) - (8)].ival) << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(3) - (8)].name)] == 9) { if( (yyvsp[(5) - (8)].ival) <= acvar[(yyvsp[(3) - (8)].name)].size()){ char a; scanf("%c",&a); acvar[(yyvsp[(3) - (8)].name)][(yyvsp[(5) - (8)].ival)] =  a; cout << "Value of " << (yyvsp[(3) - (8)].name) << "[" << (yyvsp[(5) - (8)].ival) << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
							};}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 216 "abc.y"
    {cout << endl; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 219 "abc.y"
    { cout << (yyvsp[(1) - (1)].str) ; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 220 "abc.y"
    { if(varmap.find((yyvsp[(1) - (1)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (1)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  else {
						if(varmap[(yyvsp[(1) - (1)].name)] == 1) { cout << ivar[(yyvsp[(1) - (1)].name)]; }
			  	  		else if(varmap[(yyvsp[(1) - (1)].name)] == 3) { cout << dvar[(yyvsp[(1) - (1)].name)]; }
			  	  		else if(varmap[(yyvsp[(1) - (1)].name)] == 4) { cout << cvar[(yyvsp[(1) - (1)].name)];  }
     			   	  	else if(varmap[(yyvsp[(1) - (1)].name)] == 5) { cout << bvar[(yyvsp[(1) - (1)].name)]; }
					}
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 228 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[(yyvsp[(1) - (4)].name)] == 6) { if( (yyvsp[(3) - (4)].ival) <= aivar[(yyvsp[(1) - (4)].name)].size()){cout << aivar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} }  
								else if(varmap[(yyvsp[(1) - (4)].name)] == 8) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){cout << advar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 9) { if( (yyvsp[(3) - (4)].ival) <= acvar[(yyvsp[(1) - (4)].name)].size()){cout << acvar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 10) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){cout << abvar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
							};}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 236 "abc.y"
    { if(varmap.find((yyvsp[(1) - (1)].name)) == varmap.end()) { yyerror("Error  : Variable "); yyerror((yyvsp[(1) - (1)].name)); yyerror(" not declared\n"); exit(-1);}
			  else {	 
			 if(varmap[(yyvsp[(1) - (1)].name)] == 1) {  (yyval.vars).ival = ivar[(yyvsp[(1) - (1)].name)]; }
			  else if(varmap[(yyvsp[(1) - (1)].name)] == 3) { (yyval.vars).fval = dvar[(yyvsp[(1) - (1)].name)]; }
			  else if(varmap[(yyvsp[(1) - (1)].name)] == 4) { (yyval.vars).cval = cvar[(yyvsp[(1) - (1)].name)];  }
     			  else if(varmap[(yyvsp[(1) - (1)].name)] == 5) { (yyval.vars).bval = bvar[(yyvsp[(1) - (1)].name)]; }
			}
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 245 "abc.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 246 "abc.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 247 "abc.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 248 "abc.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 251 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1);}
			  		else {
						if(varmap[(yyvsp[(1) - (4)].name)] == 1) { currentex = 1; ivar[(yyvsp[(1) - (4)].name)] = (yyvsp[(3) - (4)].vars).ival; (yyval.fval) = (double)((yyvsp[(3) - (4)].vars).ival); }
			  			else if(varmap[(yyvsp[(1) - (4)].name)] == 3) { currentex = 2; dvar[(yyvsp[(1) - (4)].name)] = (yyvsp[(3) - (4)].vars).fval; (yyval.fval) = (yyvsp[(3) - (4)].vars).fval; } 
					}
					;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 259 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (3)].vars).ival + (yyvsp[(3) - (3)].vars).ival; } else { (yyval.vars).fval = (yyvsp[(1) - (3)].vars).fval + (yyvsp[(3) - (3)].vars).fval; } ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 260 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (3)].vars).ival - (yyvsp[(3) - (3)].vars).ival; } else { (yyval.vars).fval = (yyvsp[(1) - (3)].vars).fval - (yyvsp[(3) - (3)].vars).fval; } ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 261 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (1)].vars).ival ; } else { (yyval.vars).fval = (yyvsp[(1) - (1)].vars).fval ; } ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 263 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (3)].vars).ival * (yyvsp[(3) - (3)].vars).ival; } else { (yyval.vars).fval = (yyvsp[(1) - (3)].vars).fval * (yyvsp[(3) - (3)].vars).fval ; } ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 264 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (3)].vars).ival / (yyvsp[(3) - (3)].vars).ival ;} else { (yyval.vars).fval = (yyvsp[(1) - (3)].vars).fval / (yyvsp[(3) - (3)].vars).fval;  } ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 265 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(1) - (1)].vars).ival ; } else { (yyval.vars).fval = (yyvsp[(1) - (1)].vars).fval ; } ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 267 "abc.y"
    { if(currentex == 1) { (yyval.vars).ival = (yyvsp[(2) - (3)].vars).ival; } else { (yyval.vars).fval = (yyvsp[(2) - (3)].vars).fval; } ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 268 "abc.y"
    { if(varmap.find((yyvsp[(1) - (1)].name)) == varmap.end()) { yyerror("Error  : Variable "); yyerror((yyvsp[(1) - (1)].name)); yyerror(" not declared\n"); }
			  		  else {
						if(varmap[(yyvsp[(1) - (1)].name)] == 1) { (yyval.vars).ival = ivar[(yyvsp[(1) - (1)].name)]; currentex = 1;}
						else if(varmap[(yyvsp[(1) - (1)].name)] == 3) { (yyval.vars).fval = dvar[(yyvsp[(1) - (1)].name)]; currentex = 3;}
						else { yyerror("Error : Expected an integer or double"); }
					  }
					;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 275 "abc.y"
    { (yyval.vars).ival = (yyvsp[(1) - (1)].ival); currentex = 1;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 276 "abc.y"
    { (yyval.vars).fval = (yyvsp[(1) - (1)].fval); currentex = 2; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 277 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[(yyvsp[(1) - (4)].name)] == 6) { if( (yyvsp[(3) - (4)].ival) <= aivar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).ival = aivar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 8) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){(yyval.vars).fval = advar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range");} } 
								else { yyerror("Error : Expected an integer or float or double"); }
							};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 284 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1);}
			  		  else { if(varmap[(yyvsp[(1) - (4)].name)] == 5) { bvar[(yyvsp[(1) - (4)].name)] = (yyvsp[(3) - (4)].bval);}
					    	else { yyerror("Error : Expected bool");}
					  }
			  		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 289 "abc.y"
    { 
					  if(strcmp((yyvsp[(1) - (5)].type),"bool") != 0) { yyerror("Error : A boolean expression must be placed in a variable of type bool not "); yyerror((yyvsp[(1) - (5)].type)); yyerror("\n"); exit(-1);}
			  		  else bvar[(yyvsp[(2) - (5)].name)] = (yyvsp[(4) - (5)].bval);
			  		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 294 "abc.y"
    { (yyval.bval) = !((yyvsp[(2) - (2)].bval)) ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 295 "abc.y"
    { (yyval.bval) = ((yyvsp[(1) - (3)].bval) and (yyvsp[(3) - (3)].vars).bval); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 296 "abc.y"
    { (yyval.bval) = ((yyvsp[(1) - (3)].bval) or (yyvsp[(3) - (3)].vars).bval); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 297 "abc.y"
    { (yyval.bval) = (yyvsp[(1) - (1)].vars).bval; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 299 "abc.y"
    { if((yyvsp[(1) - (4)].vars).fval == (yyvsp[(4) - (4)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 300 "abc.y"
    { if((yyvsp[(1) - (4)].vars).fval != (yyvsp[(4) - (4)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 301 "abc.y"
    { if((yyvsp[(1) - (3)].vars).fval > (yyvsp[(3) - (3)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 302 "abc.y"
    { if((yyvsp[(1) - (3)].vars).fval >= (yyvsp[(3) - (3)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 303 "abc.y"
    { if((yyvsp[(1) - (3)].vars).fval < (yyvsp[(3) - (3)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 304 "abc.y"
    { if((yyvsp[(1) - (3)].vars).fval <= (yyvsp[(3) - (3)].fval)) { (yyval.vars).bval = true; } else { (yyval.vars).bval = false; } ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 305 "abc.y"
    { (yyval.vars).bval = (yyvsp[(2) - (3)].bval); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 306 "abc.y"
    { (yyval.vars).fval = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 308 "abc.y"
    { (yyval.fval) = (yyvsp[(2) - (3)].bval); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 309 "abc.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 311 "abc.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].bval);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 312 "abc.y"
    { (yyval.fval) = (float) ((yyvsp[(1) - (1)].ival));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 313 "abc.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 314 "abc.y"
    { if(varmap.find((yyvsp[(1) - (1)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (1)].name)); yyerror(" not declared\n");exit(-1);} 
			          else {
					if(varmap[(yyvsp[(1) - (1)].name)] == 1) { (yyval.fval) = (float) (ivar[(yyvsp[(1) - (1)].name)]); }
				   	else if(varmap[(yyvsp[(1) - (1)].name)] == 3) { currentex = 2; (yyval.fval) = dvar[(yyvsp[(1) - (1)].name)];}
				   	else if(varmap[(yyvsp[(1) - (1)].name)] == 4) { currentex = 2; (yyval.fval) = (float) (cvar[(yyvsp[(1) - (1)].name)]);}
				  }
				;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 321 "abc.y"
    { (yyval.fval) = (float)((yyvsp[(1) - (1)].cval)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 322 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n"); exit(-1); }
			  		  		else {
								if(varmap[(yyvsp[(1) - (4)].name)] == 6) { if( (yyvsp[(3) - (4)].ival) <= aivar[(yyvsp[(1) - (4)].name)].size()){(yyval.fval) = (float)(aivar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)]);} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 8) { if( (yyvsp[(3) - (4)].ival) <= advar[(yyvsp[(1) - (4)].name)].size()){(yyval.fval) = advar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else if(varmap[(yyvsp[(1) - (4)].name)] == 9) { if( (yyvsp[(3) - (4)].ival) <= acvar[(yyvsp[(1) - (4)].name)].size()){(yyval.fval) = (float)(acvar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)]);} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else { yyerror("Error : Expected an integer or float or double"); }
							};}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 330 "abc.y"
    {  ifelfound = 0; if((yyvsp[(2) - (6)].bval) == true) (yyval.fval) = (yyvsp[(4) - (6)].fval); else (yyval.fval) = (yyvsp[(5) - (6)].fval); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 331 "abc.y"
    { ifelfound = 0; if((yyvsp[(2) - (5)].bval) == true) (yyval.fval) = (yyvsp[(4) - (5)].fval); else (yyval.fval) = -100;       ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 332 "abc.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 334 "abc.y"
    { if((yyvsp[(2) - (5)].bval) == true){ (yyval.fval) = (yyvsp[(4) - (5)].fval); ifelfound = 1;}  else{(yyval.fval) = (yyvsp[(5) - (5)].fval);} ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 335 "abc.y"
    { if((yyvsp[(2) - (4)].bval) == true){ (yyval.fval) = (yyvsp[(4) - (4)].fval); ifelfound = 1;}	else{(yyval.fval) = -100;}	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 336 "abc.y"
    { if(ifelfound == 0) (yyval.fval)= (yyvsp[(3) - (3)].fval); else (yyval.fval) = -100; ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 338 "abc.y"
    { if(varmap.find((yyvsp[(2) - (12)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(2) - (12)].name)); yyerror(" not declared\n"); exit(-1); }
														  if(varmap[(yyvsp[(2) - (12)].name)] != 1) { yyerror("Error : Expected an integer in "); yyerror((yyvsp[(2) - (12)].name)); yyerror("\n");}
														  cout << "//For loop detected\n";
														  if((yyvsp[(4) - (12)].ival)<=(yyvsp[(7) - (12)].ival)){
														  for(ivar[(yyvsp[(2) - (12)].name)] = (yyvsp[(4) - (12)].ival); ivar[(yyvsp[(2) - (12)].name)] <= (yyvsp[(7) - (12)].ival) ; ivar[(yyvsp[(2) - (12)].name)] = ivar[(yyvsp[(2) - (12)].name)] + (yyvsp[(9) - (12)].ival)){
															cout << "//Value of expression : " << (yyvsp[(11) - (12)].fval) << endl;}
														  }
														  else{
															for(ivar[(yyvsp[(2) - (12)].name)] = (yyvsp[(4) - (12)].ival); ivar[(yyvsp[(2) - (12)].name)] >= (yyvsp[(7) - (12)].ival) ; ivar[(yyvsp[(2) - (12)].name)] = ivar[(yyvsp[(2) - (12)].name)] - (yyvsp[(9) - (12)].ival)){
																cout << "//Value of expression : " << (yyvsp[(11) - (12)].fval) << endl;}
														  }
														  cout << endl;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 351 "abc.y"
    { if(varmap.find((yyvsp[(1) - (1)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (1)].name)); yyerror(" not declared\n");  exit(-1);}
			         else { if(varmap[(yyvsp[(1) - (1)].name)] != 1 ) { yyerror("Error : Expected an integer variable in "); yyerror((yyvsp[(1) - (1)].name)); yyerror("\n"); }
					 else { (yyval.ival) = ivar[(yyvsp[(1) - (1)].name)]; }
				  }
				;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 356 "abc.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 357 "abc.y"
    { yyerror("Error : Expected an integer"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 358 "abc.y"
    { yyerror("Error : Expected an integer"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 359 "abc.y"
    { yyerror("Error : Expected an integer"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 360 "abc.y"
    { if(varmap.find((yyvsp[(1) - (4)].name)) == varmap.end()) { yyerror("Error : Variable "); yyerror((yyvsp[(1) - (4)].name)); yyerror(" not declared\n");  exit(-1);}
			  		  		else {
								if(varmap[(yyvsp[(1) - (4)].name)] == 6) { if( (yyvsp[(3) - (4)].ival) <= aivar[(yyvsp[(1) - (4)].name)].size()){(yyval.ival) = aivar[(yyvsp[(1) - (4)].name)][(yyvsp[(3) - (4)].ival)];} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else { yyerror("Error : Expected an integer"); }
							};}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 366 "abc.y"
    { cout << "//while loop found." << endl;
											//	 while($2==true) {cout<< "//Value of expression : "<<$3<<endl; }
												  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 370 "abc.y"
    { cout << "//Single line comment" << endl; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 372 "abc.y"
    { cout << "//Multiple line comment" << endl; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 374 "abc.y"
    { cout<<"//empty statement"<<endl;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 379 "abc.y"
    { cout << "//Function " << (yyvsp[(3) - (9)].name) << " declared." << endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 382 "abc.y"
    {cout<<"exp";;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 385 "abc.y"
    { if(strcmp((yyvsp[(1) - (5)].type),"int") == 0) { varmap[(yyvsp[(3) - (5)].name)] = 1; ivar[(yyvsp[(3) - (5)].name)] = 0; } 
										else if(strcmp((yyvsp[(1) - (5)].type),"double") == 0) {varmap[(yyvsp[(3) - (5)].name)] = 3; dvar[(yyvsp[(3) - (5)].name)] = 0.0; }
										else if(strcmp((yyvsp[(1) - (5)].type),"char") == 0) {varmap[(yyvsp[(3) - (5)].name)] = 4; cvar[(yyvsp[(3) - (5)].name)] = '#'; }
										else if(strcmp((yyvsp[(1) - (5)].type),"bool") == 0) {varmap[(yyvsp[(3) - (5)].name)] = 5; bvar[(yyvsp[(3) - (5)].name)] = true; }
										;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 390 "abc.y"
    {  if(strcmp((yyvsp[(1) - (3)].type),"int") == 0) {varmap[(yyvsp[(3) - (3)].name)] = 1; ivar[(yyvsp[(3) - (3)].name)] = 0; } 
						else if(strcmp((yyvsp[(1) - (3)].type),"double") == 0) {varmap[(yyvsp[(3) - (3)].name)] = 3; dvar[(yyvsp[(3) - (3)].name)] = 0.0; }
						else if(strcmp((yyvsp[(1) - (3)].type),"char") == 0) {varmap[(yyvsp[(3) - (3)].name)] = 4; cvar[(yyvsp[(3) - (3)].name)] = '#'; }
						else if(strcmp((yyvsp[(1) - (3)].type),"bool") == 0) {varmap[(yyvsp[(3) - (3)].name)] = 5; bvar[(yyvsp[(3) - (3)].name)] = true; }
						cout<<varmap[(yyvsp[(3) - (3)].name)]<<endl;
						;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 398 "abc.y"
    { if(varmap[(yyvsp[(2) - (3)].name)]==0){ //if( varmap.find($2) == varmap.end()) { 
			yyerror("Error : Variable "); yyerror((yyvsp[(2) - (3)].name)); yyerror(" not declared\n"); };}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 401 "abc.y"
    { cout<<"GCD : "<< __gcd((yyvsp[(3) - (7)].ival),(yyvsp[(5) - (7)].ival)) <<endl; ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 402 "abc.y"
    { cout<<"LCM : "<<(((yyvsp[(3) - (7)].ival))*(((yyvsp[(5) - (7)].ival))/__gcd((yyvsp[(3) - (7)].ival),(yyvsp[(5) - (7)].ival))))<<endl;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 403 "abc.y"
    { cout<<"Square root of value : "<<sqrt((yyvsp[(3) - (5)].fval))<<endl; ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 404 "abc.y"
    {cout<<"Square of value :"<<(yyvsp[(3) - (5)].fval)*(yyvsp[(3) - (5)].fval)<<endl;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 405 "abc.y"
    {cout<<"Qube of value :"<<(yyvsp[(3) - (5)].fval)*(yyvsp[(3) - (5)].fval)*(yyvsp[(3) - (5)].fval)<<endl;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 406 "abc.y"
    {siv(); if(((yyvsp[(3) - (5)].ival) % 2 == 1 && isprime[(yyvsp[(3) - (5)].ival)]==0 ) || (yyvsp[(3) - (5)].ival) == 2)cout<<(yyvsp[(3) - (5)].ival)<<" is prime."<<endl;
												else cout<<(yyvsp[(3) - (5)].ival)<<" is not a prime."<<endl; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 408 "abc.y"
    {siv(); cout<<(yyvsp[(3) - (5)].ival)<<" th prime number is : "<<pr[(yyvsp[(3) - (5)].ival) - 1 ]<<endl;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 409 "abc.y"
    { if((yyvsp[(3) - (5)].ival)<3) cout<<"1st Fibonacci number is 1"<<endl;
								else{ int x=1,y=1,z;for(int i=0;i< (yyvsp[(3) - (5)].ival) - 2 ;i++){ z=x+y; x=y;y=z; } cout<<(yyvsp[(3) - (5)].ival)<<" th Fibonacci number is : "<<z<<endl;} ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 411 "abc.y"
    { cout<<(yyvsp[(3) - (7)].fval)<<" to the power "<<(yyvsp[(5) - (7)].fval)<<" is : "<<powl((yyvsp[(3) - (7)].fval),(yyvsp[(5) - (7)].fval))<<endl; ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 412 "abc.y"
    {cout<<"Bigmod value : "<<bigmod((yyvsp[(3) - (9)].ival),(yyvsp[(5) - (9)].ival),(yyvsp[(7) - (9)].ival))<<endl;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 413 "abc.y"
    { cout<<"Modulus Result : "<<(yyvsp[(3) - (7)].ival) % (yyvsp[(5) - (7)].ival)<<endl;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 414 "abc.y"
    { double x=pi/180.0; cout<<"Sin"<<(yyvsp[(3) - (5)].fval)<<" is : "<<sin((yyvsp[(3) - (5)].fval) * x)<<endl; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 415 "abc.y"
    { double x=pi/180.0; cout<<"Cos"<<(yyvsp[(3) - (5)].fval)<<" is : "<<cos((yyvsp[(3) - (5)].fval))<<endl; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 416 "abc.y"
    { double x=pi/180.0; cout<<"Tan"<<(yyvsp[(3) - (5)].fval)<<" is : "<<tan((yyvsp[(3) - (5)].fval) * x)<<endl; ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 417 "abc.y"
    { cout<<"Sin invers "<<(yyvsp[(3) - (5)].fval)<<" is : "<<asin((yyvsp[(3) - (5)].fval))/pi*180.0<<endl; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 418 "abc.y"
    { cout<<"Cos invers "<<(yyvsp[(3) - (5)].fval)<<" is : "<<acos((yyvsp[(3) - (5)].fval))/pi*180.0<<endl; ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 419 "abc.y"
    { cout<<"Tan invers "<<(yyvsp[(3) - (5)].fval)<<" is : "<<atan((yyvsp[(3) - (5)].fval))/pi*180.0<<endl; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 421 "abc.y"
    {(yyval.fval) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 422 "abc.y"
    {(yyval.fval) = (yyvsp[(1) - (1)].fval);;}
    break;



/* Line 1455 of yacc.c  */
#line 2627 "abc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 424 "abc.y"


int main() {
  yyin = fopen("cmpin.txt","r");
  yyout = freopen("cmpout.txt","w",stdout);
  yyparse();
}
void yyerror(const char *s) {
  cout << s ;
}


