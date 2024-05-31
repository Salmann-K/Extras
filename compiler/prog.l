%{
#include<stdio.h>
#include<stdlib.h>
#include"prog.tab.h"
%}

%%
[0-9]+ {yylval = atoi(yytext);return digit;}
[-+*/\n] return *yytext;
. ; 
%%

int yywrap(void)
{
    return 1;
}