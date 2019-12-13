digit [0-9]+
double [0-9]+[.][0-9]+
string [A-Za-z]+

datatype "int"|"float"|"char"
variable [A-Za-z]+[0-9]*[A-Za-z]*
value {digit}|{string}|{double}|{variable}
array {variable}"["{digit}"]"
frtype "void"|{datatype}
keyword "include"|"while"|"loop"|"if"|"elif"|"else"|"switch"|"return"|{frtype}|"read"|"write"|"func"|"end_func"|"end_if"|"end_main"

operator "+"|"-"|"*"|"/"|"%"|"^"|"&"|"|"
relational "<"|"="|"&&"|"||"|"<"|"<="|">="|"!="
allop {relational}|{operator}

assign {variable}[=]{value}|{variable}[=]{value}{operator}{value}
expr {value}{allop}{value}
condition {expr}[{relational}{expr}]*
identifier {variable}|{array}
coma [,]
space [ ]
parameter {datatype}{space}{variable}({coma}{datatype}{space}{variable})*

%{
#include<string.h>
#include<stdio.h>
int cm=0;
char var[100][100],funct[100][100],op[100][3],arr[100][100],key[100][100],head[100][100];
int varc=0,functc=0,opc=0,arrc=0,keyc=0,headc=0;
int funs=-1;
int iff=-1,eliff=-1,elsef=-1,lop=-1,whl=-1,ms=0;
int iskey(char *c){
    if(strcmp(c,"include")||strcmp(c,"return")||strcmp(c,"int")||strcmp(c,"if")||strcmp(c,"elif")||strcmp(c,"else")||strcmp(c,"float")||
    strcmp(c,"switch")||strcmp(c,"char")||strcmp(c,"while")||strcmp(c,"loop")||strcmp(c,"void")||strcmp(c,"main")||strcmp(c,"func")||
    strcmp(c,"read")||strcmp(c,"write")||strcmp(c,"end_func")||strcmp(c,"end_if")||strcmp(c,"end_main")){
        return 1;
    }
    return 0;
}
%}

%%
"//".* {printf("Single line comment\n");}
"/*".* { if(cm==0){ cm=1; printf("Multi-line comment\n");}}
"*/" {if(cm){ cm=0; printf("multi-line comment ended\n");}
        else{ printf("%s",yytext); }}
"#include"[ ]{keyword}".h;" { if(cm==0) { printf("Error : header file name can't be keyword\n"); } }
"#include"[ ]{string}".h;"  { if(cm==0) { printf("Header file included\n"); headc++; keyc++; } }
"#include".* {if(cm==0) printf("Error : Header file is not included\n");}
"func int main()" { if(cm==0){
        if(ms==0){
            ms=1; keyc+=3;
            printf("Main function starts\n");
        }
        else{  printf("Error: a program can have only one main function\n");} }}
"end_main;" { if(cm==0){
        if(ms==1){ printf("Main function ends\n"); keyc++;}
        else {printf("Main function does not exist\n");} } }
"end_func;" { if(cm==0){
        if(funs==-1){ printf("Error : No function starts\n"); }
        else if(funs==1) {
            funs=-1; keyc++; printf("function ends\n");
        } } }
"func"[ ]{frtype}[ ]{keyword}.* { if(cm==0) {
printf("Error : function name can't be keyword\n"); } }
"func"[ ]{frtype}[ ]{variable}[(]{parameter}?[)] { if(cm==0){
        if(funs==-1){ funs=1; functc++; keyc+=2; printf("Function Declared\n");}
        else{ printf("Error : A function can't be declared inside another function\n");} } }
{variable}"("({value}[","{value}]*)?");" { if(cm==0){
        printf("function called\n"); }  }
"if("{condition}")" { if(cm==0){
        if(iff==-1){
            iff=1; keyc++;
            printf("if clause found\n"); }
        else { printf("Error : nested if is not possible\n"); } }}
"elif("{condition}")" { if(cm==0){
        if(iff==1){ eliff=1; keyc++;
            printf("elif clause found\n");}
        else { printf("No if clause found");} } }}
"else" { if(cm==0){ if(iff==1){ keyc++; printf("else clause found\n"); } } }
"end_if;" { if(cm==0){ if(iff==1){
            iff=-1,eliff=-1; keyc++;
            printf("End of if clause\n"); }
        else { printf("No if clause found");} } }
"end_while;" {if(cm==0){
        if(whl==1){ keyc++; printf("while loop ends\n");}
        else { printf("No while loop declared"); } } }
"while("{condition}")" {if(cm==0){
        if(whl==-1){
        whl=1; keyc++; printf("while loop starts\n");}
        else {  printf("Error: Nested loop is not possible\n"); } }}
"end_loop;" {if(cm==0){
        if(lop==1){ keyc++;lop=-1; printf(""); }
        else {}
        }}
"loop "[{variable}|{digit}]".."[{variable}|{digit}]" by "[{variable}|{digit}] {if(cm==0){
        if(lop==-1){ lop=1;keyc++; printf("Loop found\n");}
        else { printf("Error: Nested loop is not possible\n"); }}}

{datatype}" "{variable}([,]{variable})*";" { if(cm==0){ printf("variable declared\n");keyc++; int i;
for( i=0;i<yyleng;i++){
if(yytext[i]==',' || yytext[i]==';') varc++; } }}

{datatype}" "{array}([,]{array})*";" { if(cm==0){ printf("array declared\n");keyc++; int i;
for( i=0;i<yyleng;i++){
if(yytext[i]==',' || yytext[i]==';') arrc++; } }}

{assign}[;] {if(cm==0){ printf("Value assigned\n"); } }
"return"[ ]{value}[;] {if(cm==0) {printf("Value returned\n"); } }
%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin = freopen("in.txt","r",stdin);
	yyout = freopen("out.txt","w",stdout);
	yylex();
	printf("Count :\n\tHeader : %d\n\tFunction : %d\n\tKeyword : %d\n\tVariable : %d\n\tArray : %d\n",headc,functc,keyc,varc,arrc);
	return 0;
}
