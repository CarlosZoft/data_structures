#include <stdio.h>
#include <string.h>

int main()
{
  int i=0,n,tam,j=0,num_led=0;
  char v[100000];

  scanf("%d", &n);

  for(i=0;i<n;i++){
    scanf("%s", v);
    tam = (int)strlen(v);

    for(j=0;j<tam;j++){
      if(v[j]=='0'){
        num_led=num_led+6;
      }
      else if(v[j]=='1'){
        num_led=num_led+2;
      }
      else if(v[j]=='2'){
        num_led=num_led+5;
      }
      else if(v[j]=='3'){
        num_led=num_led+5;
      }
      else if(v[j]=='4'){
        num_led=num_led+4;
      }
      else if(v[j]=='5'){
        num_led=num_led+5;
      }
      else if(v[j]=='6'){
        num_led=num_led+6;
      }
      else if(v[j]=='7'){
        num_led=num_led+3;
      }
      else if(v[j]=='8'){
        num_led=num_led+7;
      }
      else  if(v[j]=='9'){
        num_led=num_led+6;
      }
    }

    printf("%d leds\n", num_led);
    num_led=0;
  }



  return 0;
}
