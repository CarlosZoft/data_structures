#include <stdio.h>
#include <string.h>


int main()
{
  int n;
  char  a[]="tesoura", b[]="papel", c[]="pedra", d[]="lagarto", e[]="Spock";
  char l[10],k[10];
  
  scanf("%d", &n);

  for(int p = 1; p<=n ; p++){
    scanf("%s%s", l, k);
   


    if (0==strcmp(l,k))
    printf("Caso #%d: De novo!\n",p);





else if(0==strcmp(l,a)){
     if ((0==strcmp(k,b)) || (0==strcmp(k,d)))
        printf("Caso #%d: Bazinga!\n",p);
    else  if ((0==strcmp(k,c))|| (0==strcmp(k,e)))
        printf("Caso #%d: Raj trapaceou!\n",p);
    }

else if(0==strcmp(l,b)){

      if ((0==strcmp(k,c)) || (0==strcmp(k,e)))
        printf("Caso #%d: Bazinga!\n",p);
     else if ((0==strcmp(k,a))|| (0==strcmp(k,d)))
        printf("Caso #%d: Raj trapaceou!\n",p);
    }
 else if(0==strcmp(l,c)){

      if ((0==strcmp(k,a)) || (0==strcmp(k,d)))
        printf("Caso #%d: Bazinga!\n",p);
     else if ((0==strcmp(k,b))|| (0==strcmp(k,e)))
        printf("Caso #%d: Raj trapaceou!\n",p);
    }
 else if(0==strcmp(l,d)){

      if ((0==strcmp(k,b)) || (0==strcmp(k,e)))
        printf("Caso #%d: Bazinga!\n",p);
     else if ((0==strcmp(k,c))|| (0==strcmp(k,a)))
        printf("Caso #%d: Raj trapaceou!\n",p);
    }
 else if(0==strcmp(l,e)){

      if ((0==strcmp(k,a)) || (0==strcmp(k,c)))
            
                printf("Caso #%d: Bazinga!\n",p);
            
     
     else if ((0==strcmp(k,b))|| (0==strcmp(k,d)))
        printf("Caso #%d: Raj trapaceou!\n",p);
    }
   
  }
return 0;
  }