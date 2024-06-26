%{
%}

%s A B C F

%%
<INITIAL>\n printf("Accepted\n"); BEGIN INITIAL;
<INITIAL>a BEGIN A;
<INITIAL>b BEGIN B;
<INITIAL>[^ab\n] BEGIN F;
<A>a BEGIN INITIAL;
<A>b BEGIN C;
<A>\n BEGIN INITIAL; printf("Not Accepted\n");
<A>[^ab\n] BEGIN F;
<B>a BEGIN C;
<B>b BEGIN INITIAL;
<B>\n BEGIN INITIAL; printf("Not Accepted\n");
<B>[^ab\n] BEGIN F;
<C>a BEGIN B;
<C>b BEGIN A;
<C>\n BEGIN INITIAL; printf("Not Accepted\n");
<C>[^ab\n] BEGIN F;
<F>[^\n] BEGIN F;
<F>[\n] BEGIN INITIAL; printf("Wrong Input\n");
%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter The String\n");
    yylex();
    return 0;
}