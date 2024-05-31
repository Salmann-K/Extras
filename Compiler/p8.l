%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
"<"[^>]*> { fprintf(yyout,"%s",yytext); } 
.    ;
%%

int yywrap(){
     return 1;
}
int main(){
    extern FILE *yyin,*yyout; 
    yyin=fopen("abc.txt","r"); 
    yyout=fopen("Output.txt","w");
     yylex();
}
