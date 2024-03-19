%{
#include<stdio.h>
%}

%%

"//".*          
"/*"([^*]|\n)*"*/"   
[^ \t\n]*         { fprintf(yyout, "%s", yytext); }
[ \t\n]            { fprintf(yyout, "%s", yytext); }
%%

int yywrap(){
    return 1;
}

int main(int argc, char **argv){
    yyin=fopen(argv[1],"r");
    yyout=fopen("output.c","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
} 
