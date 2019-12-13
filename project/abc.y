%{
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

%}

%union {
  int ival;
  char cval;
  double fval;
  bool bval;
  char *type,*name;
  char *str;
  char c;
}

%union {
  struct{
	int ival;
    double fval;
 	char cval;
  	bool bval;
	char *str;
  }vars;
}

%token HASH SHOW READ MCMNT SCMNT FUNC RETURN FUNCEND QUOTE OPENBR1 CLOSEBR1 OPENBR3 CLOSEBR3 MAIN INCLUDE GREATER LESS GREATEREQ LESSEQ MOD ASIN ACOS ATAN SIN COS TAN SQRT POW BIGM FIBO SQ PRIME ISPRM QUBE GCD LCM DOT PLUS MINUS MUL DIV SEMI COMM EQUAL IF ELSE ELIF ENDIF END LOOP BY IN ENDLOOP WHILE ENDWHILE AND OR NOT COLON
%token NEWLINE
%token <str> STRING
%token <str> HEADFILENAME
%token <type> INT
%token <type> CHAR
%token <type> DOUBLE
%token <type> BOOL
%token <c> PERCENT
%token <name> VARNAME
%token <ival> DIGIT
%token <fval> FLOATVAL
%token <cval> CHARACTER
%token <bval> TRUE
%token <bval> FALSE
%token <bval> BOOLVAL
%type <vars> VARIABLE
%type <vars> VALUE
%type <type> TYPE
%type <vars> EX
%type <vars> F
%type <vars> T
%type <bval> condx
%type <bval> CONDX
%type <vars> A
%type <fval> B
%type <fval> C
%type <ival> NUMVALUE
%type <fval> else
%type <fval> NUMV
%type <fval> EXP
%type <fval> IFELSE
%start START

%%
START: hdrs funcs MAIN LINE END		{  cout << "//Main function executed successfully" << endl; }
;
hdrs:
		|hdrs header
;
header:		HASH INCLUDE LESS HEADFILENAME GREATER		{ cout << "//Header file " << $4 << " included" << endl; }
;
LINE :
	|LINE ST				 				
;

ST : read					
	|show			{cout<<endl;}
    |VD				{ cout << endl; }			
	|EXP		    { cout << "Result of expression = " << $1 << endl; }					
	|condx					
	|IFELSE			{ cout << "//Value of if-else block : " << $1 << endl; }				
	|FL					
	|WH
	|empty	
	|singlecomment
	|multicomment	
	|fcall			
;
VD:	TYPE VARNAME EQUAL VALUE SEMI		{ if( varmap.find($2) == varmap.end() ){
						if(strcmp($1,"int") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with " << $4.ival ; varmap[$2] = 1; ivar[$2] = $4.ival; } 
						else if(strcmp($1,"double") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.fval ; varmap[$2] = 3; dvar[$2] = $4.fval; }
						else if(strcmp($1,"char") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.cval ; varmap[$2] = 4; cvar[$2] = $4.cval;  }
						else if(strcmp($1,"bool") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.bval ; varmap[$2] = 5; bvar[$2] = $4.bval; }
						}
						else { yyerror("Error : Variable "); yyerror($2); yyerror(" previously declared"); exit(-1); }
						}
	|TYPE VARNAME EQUAL VARIABLE SEMI	{ if( varmap.find($2) == varmap.end() )
						{
						if(strcmp($1,"int") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.ival ; varmap[$2] = 1; ivar[$2] = $4.ival;  } 
						else if(strcmp($1,"double") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.fval ; varmap[$2] = 3; dvar[$2] = $4.fval; }
						else if(strcmp($1,"char") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.cval ; varmap[$2] = 4; cvar[$2] = $4.cval; }
						else if(strcmp($1,"bool") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.bval ; varmap[$2] = 5; bvar[$2] = $4.bval; }
						}
						else { yyerror("Error : Variable "); yyerror($2); yyerror(" previously declared");  exit(-1);}
						}
	|TYPE VARNAME EQUAL EX SEMI		{ if( varmap.find($2) == varmap.end() ){
						if(strcmp($1,"int") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.ival ; varmap[$2] = 1; ivar[$2] = $4.ival; } 
						else if(strcmp($1,"double") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.fval ; varmap[$2] = 3; dvar[$2] = $4.fval; }
						else if(strcmp($1,"char") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.cval ; varmap[$2] = 4; cvar[$2] = $4.cval; }
						else if(strcmp($1,"bool") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< $4.bval ; varmap[$2] = 5; bvar[$2] = $4.bval; }
						}
						else { yyerror("Error : Variable "); yyerror($2); yyerror(" previously declared"); exit(-1); }
						}
	|TYPE VARNAME SEMI			{ if( varmap.find($2) == varmap.end() ){
						if(strcmp($1,"int") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< 0 ; varmap[$2] = 1; ivar[$2] = 0; } 
						else if(strcmp($1,"double") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with "<< 0.0 ; varmap[$2] = 3; dvar[$2] = 0.0; }
						else if(strcmp($1,"char") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with #" ; varmap[$2] = 4; cvar[$2] = '#';}
						else if(strcmp($1,"bool") == 0) {cout << "//"<<$1<<" Variable " << $2  << " is initialized with false" ; varmap[$2] = 5; bvar[$2] = false; }
						}
						else { yyerror("Error : Variable "); yyerror($2); yyerror(" previously declared"); exit(-1); }
						}
	|TYPE VARNAME OPENBR3 DIGIT CLOSEBR3 SEMI { if( varmap.find($2) == varmap.end() ){
							if(strcmp($1,"int") == 0) { cout <<"//"<<$1<<" Array " << $2 << " of size " <<$4<<" is declared." ; varmap[$2] = 6;  create_array($2,$4,6); } 
							else if(strcmp($1,"double") == 0) { cout <<"//"<<$1<<" Array " << $2 << " of size " <<$4<<" is declared." ; varmap[$2] = 8;  create_array($2,$4,8);}
							else if(strcmp($1,"char") == 0) { cout <<"//"<<$1<<" Array " << $2 << " of size " <<$4<<" is declared." ; varmap[$2] = 9;  create_array($2,$4,9);}
							else if(strcmp($1,"bool") == 0) { cout <<"//"<<$1<<" Array " << $2 << " of size " <<$4<<" is declared." ; varmap[$2] = 10; create_array($2,$4,10);}
							}
							else { yyerror("Error : Variable "); yyerror($2); yyerror(" previously declared");  exit(-1); }
							}
;
VALUE:	DIGIT				{$$.ival = $1; currentex = 1}
		|FLOATVAL			{$$.fval = $1; currentex = 2}
		|CHARACTER			{$$.cval = $1; currentex = 4}
		|BOOLVAL			{$$.bval = $1; currentex = 5}
		|STRING				{$$.str = $1;  currentex = 0;}
		|VARNAME OPENBR3 NUMVALUE CLOSEBR3	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[$1] == 6) { if( $3 <= aivar[$1].size()){$$.ival = aivar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 8) { if( $3 <= advar[$1].size()){$$.fval = advar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 9) { if( $3 <= acvar[$1].size()){$$.cval = acvar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 10) { if( $3 <= advar[$1].size()){$$.bval = abvar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
							}}
;					

read:		READ OPENBR1 VARNAME CLOSEBR1 SEMI		{
									if(varmap.find($3) == varmap.end()) { yyerror("Error : Variable "); cout << $3 ; yyerror(" not declared\n"); exit(-1);}
			  		  				else {
										if(varmap[$3] == 1) { if(currentex == 1) { int a; scanf("%d",&a); ivar[$3] = a;cout <<"Value of "<<$3<< " read as " <<a<< endl;}  } 								
										else if(varmap[$3] == 3) { if(currentex == 2) {double a; scanf("lf",&a); dvar[$3] = a;cout <<"Value of "<<$3<<" read as "<<a<<endl; } } 
										else if(varmap[$3] == 4) { if(currentex == 4) {char a; scanf("%c",&a); cvar[$3] = a;cout <<"Value of "<<$3<<" read as "<<a<< endl; } } 
									}
									}
		|READ OPENBR1 VARNAME OPENBR3 NUMVALUE CLOSEBR3 CLOSEBR1 SEMI		{ 
							if(varmap.find($3) == varmap.end()) { yyerror("Error : Variable "); yyerror($3); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[$3] == 6) { if( $5 <= aivar[$3].size()){  int a; scanf("%d",&a); aivar[$3][$5] = a; cout << "Value of " << $3 << "[" << $5 << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$3] == 8) { if( $5 <= advar[$3].size()){ double a; scanf("lf",&a); advar[$3][$5] = a; cout << "Value of " << $3 << "[" << $5 << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$3] == 9) { if( $5 <= acvar[$3].size()){ char a; scanf("%c",&a); acvar[$3][$5] =  a; cout << "Value of " << $3 << "[" << $5 << "]" << " read as " << a << endl;} else {yyerror("Error : Array index out of range");} } 
							}}
;
show:		SHOW OPENBR1 SHOWSTR CLOSEBR1 SEMI {cout << endl; }			
;
SHOWSTR:
		|STRING			{ cout << $1 ; }
		|VARNAME		{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		  else {
						if(varmap[$1] == 1) { cout << ivar[$1]; }
			  	  		else if(varmap[$1] == 3) { cout << dvar[$1]; }
			  	  		else if(varmap[$1] == 4) { cout << cvar[$1];  }
     			   	  	else if(varmap[$1] == 5) { cout << bvar[$1]; }
					}
					}
		|VARNAME OPENBR3 NUMVALUE CLOSEBR3	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[$1] == 6) { if( $3 <= aivar[$1].size()){cout << aivar[$1][$3];} else {yyerror("Error : Array index out of range");} }  
								else if(varmap[$1] == 8) { if( $3 <= advar[$1].size()){cout << advar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 9) { if( $3 <= acvar[$1].size()){cout << acvar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 10) { if( $3 <= advar[$1].size()){cout << abvar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
							}}
;
VARIABLE:	VARNAME	{ if(varmap.find($1) == varmap.end()) { yyerror("Error  : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  else {	 
			 if(varmap[$1] == 1) {  $$.ival = ivar[$1]; }
			  else if(varmap[$1] == 3) { $$.fval = dvar[$1]; }
			  else if(varmap[$1] == 4) { $$.cval = cvar[$1];  }
     			  else if(varmap[$1] == 5) { $$.bval = bvar[$1]; }
			}
		}
;
TYPE: INT		{$$ = $1;}
	|CHAR		{$$ = $1;}
	|DOUBLE		{$$ = $1;}
	|BOOL		{$$ = $1;}
;

EXP:	VARNAME EQUAL EX SEMI		{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		else {
						if(varmap[$1] == 1) { currentex = 1; ivar[$1] = $3.ival; $$ = (double)($3.ival); }
			  			else if(varmap[$1] == 3) { currentex = 2; dvar[$1] = $3.fval; $$ = $3.fval; } 
					}
					}
;

EX:	EX PLUS T			{ if(currentex == 1) { $$.ival = $1.ival + $3.ival; } else { $$.fval = $1.fval + $3.fval; } }
	|EX MINUS T			{ if(currentex == 1) { $$.ival = $1.ival - $3.ival; } else { $$.fval = $1.fval - $3.fval; } }
	|T				{ if(currentex == 1) { $$.ival = $1.ival ; } else { $$.fval = $1.fval ; } }
;
T:	T MUL F			{ if(currentex == 1) { $$.ival = $1.ival * $3.ival; } else { $$.fval = $1.fval * $3.fval ; } } 
	|T DIV F			{ if(currentex == 1) { $$.ival = $1.ival / $3.ival ;} else { $$.fval = $1.fval / $3.fval;  } } 	
	|F				{ if(currentex == 1) { $$.ival = $1.ival ; } else { $$.fval = $1.fval ; } } 
;
F:	 OPENBR1 EX CLOSEBR1		{ if(currentex == 1) { $$.ival = $2.ival; } else { $$.fval = $2.fval; } } 		
	|VARNAME			{ if(varmap.find($1) == varmap.end()) { yyerror("Error  : Variable "); yyerror($1); yyerror(" not declared\n"); }
			  		  else {
						if(varmap[$1] == 1) { $$.ival = ivar[$1]; currentex = 1;}
						else if(varmap[$1] == 3) { $$.fval = dvar[$1]; currentex = 3;}
						else { yyerror("Error : Expected an integer or double"); }
					  }
					}	
	|DIGIT				{ $$.ival = $1; currentex = 1;}
	|FLOATVAL			{ $$.fval = $1; currentex = 2; }
	|VARNAME OPENBR3 NUMVALUE CLOSEBR3	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		  		else {
								if(varmap[$1] == 6) { if( $3 <= aivar[$1].size()){$$.ival = aivar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else if(varmap[$1] == 8) { if( $3 <= advar[$1].size()){$$.fval = advar[$1][$3];} else {yyerror("Error : Array index out of range");} } 
								else { yyerror("Error : Expected an integer or float or double"); }
							}}
;
condx:	VARNAME EQUAL CONDX SEMI	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1);}
			  		  else { if(varmap[$1] == 5) { bvar[$1] = $3;}
					    	else { yyerror("Error : Expected bool");}
					  }
			  		}
	|TYPE VARNAME EQUAL CONDX SEMI	{ 
					  if(strcmp($1,"bool") != 0) { yyerror("Error : A boolean expression must be placed in a variable of type bool not "); yyerror($1); yyerror("\n"); exit(-1);}
			  		  else bvar[$2] = $4;
			  		}
;
CONDX:	NOT CONDX		{ $$ = !($2) }
	|CONDX AND A		{ $$ = ($1 and $3.bval); }
	|CONDX OR A		{ $$ = ($1 or $3.bval); }
	|A			{ $$ = $1.bval; }
;
A:	A EQUAL EQUAL B		{ if($1.fval == $4) { $$.bval = true; } else { $$.bval = false; } }
	|A NOT EQUAL B		{ if($1.fval != $4) { $$.bval = true; } else { $$.bval = false; } }
	|A GREATER B		{ if($1.fval > $3) { $$.bval = true; } else { $$.bval = false; } }
	|A GREATEREQ B		{ if($1.fval >= $3) { $$.bval = true; } else { $$.bval = false; } }
	|A LESS B		{ if($1.fval < $3) { $$.bval = true; } else { $$.bval = false; } }
	|A LESSEQ B		{ if($1.fval <= $3) { $$.bval = true; } else { $$.bval = false; } }
	|OPENBR1 CONDX CLOSEBR1	{ $$.bval = $2; }
	|B			{ $$.fval = $1; }
;
B:	OPENBR1 CONDX CLOSEBR1  { $$ = $2; }
	|C			{ $$ = $1; }
;
C:	BOOLVAL			{ $$ = $1;}
	|DIGIT			{ $$ = (float) ($1);}
	|FLOATVAL		{ $$ = $1;} 
	|VARNAME		{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n");exit(-1);} 
			          else {
					if(varmap[$1] == 1) { $$ = (float) (ivar[$1]); }
				   	else if(varmap[$1] == 3) { currentex = 2; $$ = dvar[$1];}
				   	else if(varmap[$1] == 4) { currentex = 2; $$ = (float) (cvar[$1]);}
				  }
				}
	|CHARACTER		{ $$ = (float)($1); }
	|VARNAME OPENBR3 NUMVALUE CLOSEBR3	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n"); exit(-1); }
			  		  		else {
								if(varmap[$1] == 6) { if( $3 <= aivar[$1].size()){$$ = (float)(aivar[$1][$3]);} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else if(varmap[$1] == 8) { if( $3 <= advar[$1].size()){$$ = advar[$1][$3];} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else if(varmap[$1] == 9) { if( $3 <= acvar[$1].size()){$$ = (float)(acvar[$1][$3]);} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else { yyerror("Error : Expected an integer or float or double"); }
							}}	
;
IFELSE:	IF CONDX COLON IFELSE else ENDIF	{  ifelfound = 0; if($2 == true) $$ = $4; else $$ = $5; }						
		|IF CONDX COLON IFELSE ENDIF { ifelfound = 0; if($2 == true) $$ = $4; else $$ = -100;       }
	  	|EXP				{ $$ = $1; }
;
else:	ELIF CONDX COLON IFELSE else { if($2 == true){ $$ = $4; ifelfound = 1;}  else{$$ = $5;} }
		|ELIF CONDX COLON IFELSE { if($2 == true){ $$ = $4; ifelfound = 1;}	else{$$ = -100;}	}
		|ELSE COLON IFELSE { if(ifelfound == 0) $$= $3; else $$ = -100; }
;
FL:	LOOP VARNAME IN NUMVALUE DOT DOT NUMVALUE BY NUMVALUE COLON EXP ENDLOOP	{ if(varmap.find($2) == varmap.end()) { yyerror("Error : Variable "); yyerror($2); yyerror(" not declared\n"); exit(-1); }
														  if(varmap[$2] != 1) { yyerror("Error : Expected an integer in "); yyerror($2); yyerror("\n");}
														  cout << "//For loop detected\n";
														  if($4<=$7){
														  for(ivar[$2] = $4; ivar[$2] <= $7 ; ivar[$2] = ivar[$2] + $9){
															cout << "//Value of expression : " << $11 << endl;}
														  }
														  else{
															for(ivar[$2] = $4; ivar[$2] >= $7 ; ivar[$2] = ivar[$2] - $9){
																cout << "//Value of expression : " << $11 << endl;}
														  }
														  cout << endl;}
;
NUMVALUE:	VARNAME { if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n");  exit(-1);}
			         else { if(varmap[$1] != 1 ) { yyerror("Error : Expected an integer variable in "); yyerror($1); yyerror("\n"); }
					 else { $$ = ivar[$1]; }
				  }
				}
		|DIGIT          { $$ = $1; }
		|DOUBLE		{ yyerror("Error : Expected an integer"); }
		|CHARACTER	{ yyerror("Error : Expected an integer"); }
		|BOOLVAL	{ yyerror("Error : Expected an integer"); }
		|VARNAME OPENBR3 NUMVALUE CLOSEBR3	{ if(varmap.find($1) == varmap.end()) { yyerror("Error : Variable "); yyerror($1); yyerror(" not declared\n");  exit(-1);}
			  		  		else {
								if(varmap[$1] == 6) { if( $3 <= aivar[$1].size()){$$ = aivar[$1][$3];} else {yyerror("Error : Array index out of range"); exit(-1);} } 
								else { yyerror("Error : Expected an integer"); }
							}}
;
WH :		WHILE CONDX EXP ENDWHILE			{ cout << "//while loop found." << endl;
											//	 while($2==true) {cout<< "//Value of expression : "<<$3<<endl; }
												  }
;
singlecomment:	SCMNT 				{ cout << "//Single line comment" << endl; }
;
multicomment:	MCMNT 				{ cout << "//Multiple line comment" << endl; }
;
empty:	SEMI					{ cout<<"//empty statement"<<endl;}
;
funcs :	
		|func funcs
;
func :	FUNC TYPE VARNAME OPENBR1 PARAMLIST CLOSEBR1 exp returns FUNCEND  { cout << "//Function " << $3 << " declared." << endl; }
;
exp :	
		|EXP {cout<<"exp";}
;
PARAMLIST :
		|TYPE COLON VARNAME COMM PARAMLIST   { if(strcmp($1,"int") == 0) { varmap[$3] = 1; ivar[$3] = 0; } 
										else if(strcmp($1,"double") == 0) {varmap[$3] = 3; dvar[$3] = 0.0; }
										else if(strcmp($1,"char") == 0) {varmap[$3] = 4; cvar[$3] = '#'; }
										else if(strcmp($1,"bool") == 0) {varmap[$3] = 5; bvar[$3] = true; }
										}
		|TYPE COLON VARNAME	{  if(strcmp($1,"int") == 0) {varmap[$3] = 1; ivar[$3] = 0; } 
						else if(strcmp($1,"double") == 0) {varmap[$3] = 3; dvar[$3] = 0.0; }
						else if(strcmp($1,"char") == 0) {varmap[$3] = 4; cvar[$3] = '#'; }
						else if(strcmp($1,"bool") == 0) {varmap[$3] = 5; bvar[$3] = true; }
						cout<<varmap[$3]<<endl;
						}
;
returns:	RETURN VALUE SEMI
		|RETURN VARNAME SEMI 			{ if(varmap[$2]==0){ //if( varmap.find($2) == varmap.end()) { 
			yyerror("Error : Variable "); yyerror($2); yyerror(" not declared\n"); }}
;	
fcall : GCD OPENBR1 NUMVALUE COMM NUMVALUE CLOSEBR1 SEMI { cout<<"GCD : "<< __gcd($3,$5) <<endl; }
		| LCM OPENBR1 NUMVALUE COMM NUMVALUE CLOSEBR1 SEMI { cout<<"LCM : "<<(($3)*(($5)/__gcd($3,$5)))<<endl;}
		| SQRT OPENBR1 FLOATVAL CLOSEBR1 SEMI { cout<<"Square root of value : "<<sqrt($3)<<endl; }
		| SQ OPENBR1 FLOATVAL CLOSEBR1 SEMI {cout<<"Square of value :"<<$3*$3<<endl;}
		| QUBE OPENBR1 FLOATVAL CLOSEBR1 SEMI  {cout<<"Qube of value :"<<$3*$3*$3<<endl;}
		| ISPRM OPENBR1 NUMVALUE CLOSEBR1 SEMI {siv(); if(($3 % 2 == 1 && isprime[$3]==0 ) || $3 == 2)cout<<$3<<" is prime."<<endl;
												else cout<<$3<<" is not a prime."<<endl; }
		| PRIME OPENBR1 NUMVALUE CLOSEBR1 SEMI {siv(); cout<<$3<<" th prime number is : "<<pr[$3 - 1 ]<<endl;}
		| FIBO OPENBR1 NUMVALUE CLOSEBR1 SEMI { if($3<3) cout<<"1st Fibonacci number is 1"<<endl;
								else{ int x=1,y=1,z;for(int i=0;i< $3 - 2 ;i++){ z=x+y; x=y;y=z; } cout<<$3<<" th Fibonacci number is : "<<z<<endl;} }
		| POW OPENBR1 NUMV COMM NUMV CLOSEBR1 SEMI { cout<<$3<<" to the power "<<$5<<" is : "<<powl($3,$5)<<endl; }
		| BIGM OPENBR1 NUMVALUE COMM NUMVALUE COMM NUMVALUE CLOSEBR1 SEMI {cout<<"Bigmod value : "<<bigmod($3,$5,$7)<<endl;}
		| MOD OPENBR1 NUMVALUE COMM NUMVALUE CLOSEBR1 SEMI { cout<<"Modulus Result : "<<$3 % $5<<endl;}
		| SIN OPENBR1 FLOATVAL CLOSEBR1 SEMI { double x=pi/180.0; cout<<"Sin"<<$3<<" is : "<<sin($3 * x)<<endl; }
		| COS OPENBR1 FLOATVAL CLOSEBR1 SEMI { double x=pi/180.0; cout<<"Cos"<<$3<<" is : "<<cos($3)<<endl; }
		| TAN OPENBR1 FLOATVAL CLOSEBR1 SEMI { double x=pi/180.0; cout<<"Tan"<<$3<<" is : "<<tan($3 * x)<<endl; }
		| ASIN OPENBR1 FLOATVAL CLOSEBR1 SEMI { cout<<"Sin invers "<<$3<<" is : "<<asin($3)/pi*180.0<<endl; }
		| ACOS OPENBR1 FLOATVAL CLOSEBR1 SEMI { cout<<"Cos invers "<<$3<<" is : "<<acos($3)/pi*180.0<<endl; }
		| ATAN OPENBR1 FLOATVAL CLOSEBR1 SEMI { cout<<"Tan invers "<<$3<<" is : "<<atan($3)/pi*180.0<<endl; }
;
NUMV : DIGIT	{$$ = $1;}
	   | FLOATVAL {$$ = $1;}
;
%%

int main() {
  yyin = fopen("cmpin.txt","r");
  yyout = freopen("cmpout.txt","w",stdout);
  yyparse();
}
void yyerror(const char *s) {
  cout << s ;
}

