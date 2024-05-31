%{
#include<stdio.h>
#include<stdlib.h>
#include"p12.tab.h"
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