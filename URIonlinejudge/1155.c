#include <stdio.h>
 
int main() {
   double S = 1, t=1;
   for(int i = 2 ; i <= 100 ; i++){
      S += ( t/i );
   }
   printf("%.2lf\n", S);
    return 0;
}