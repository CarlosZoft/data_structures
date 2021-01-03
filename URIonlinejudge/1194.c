#include<stdio.h>
int main (){
 int entrada, i=1;
 int qtd, somacoelho=0,somarato=0,somasapo=0;
 double somatotal=0;
 char cobaia;
 scanf("%d", &entrada);
 while(i<=entrada){
    scanf("%d %c", &qtd, &cobaia);
    if(cobaia=='C'){
        somacoelho+=qtd;
    }
    else if(cobaia=='R'){
        somarato+=qtd;
    }
    else if(cobaia=='S'){
        somasapo+=qtd;
    }
    somatotal+=qtd;
 i++;
 }
 double porcentagem;
 printf("Total: %.0lf cobaias\n", somatotal);
 printf("Total de coelhos: %d\n",somacoelho);
 printf("Total de ratos: %d\n", somarato);
 printf("Total de sapos: %d\n", somasapo);
 porcentagem=(somacoelho/somatotal)*100;
 printf("Percentual de coelhos: %.2lf %\n", porcentagem);
 porcentagem=(somarato/somatotal)*100;
 printf("Percentual de ratos: %.2lf %\n", porcentagem);
 porcentagem=(somasapo/somatotal)*100;
 printf("Percentual de sapos: %.2lf %\n", porcentagem);


return 0;
}
