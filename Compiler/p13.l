%{
#include<stdlib.h>
int yylval;
#include "p13.tab.h"
%}

%%
[0-9]+ {yylval = atoi(yytext); return digit;}
[-+*/\n]    return *yytext;
. ;
%%

int yywrap(void)
{
    return 1;
}