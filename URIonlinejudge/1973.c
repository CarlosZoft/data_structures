#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int arr[1000010];
    int count[1000010] = {0};
    long long int soma = 0;
    int contador = 0;

    scanf("%d", &n);
    for (int i=0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int j = 0;
    while(1){
        if ((arr[j] % 2) != 0) {
            if (arr[j] > 0){
                arr[j]--;
                if(count[j] == 0){
                    count[j]++;
                }
            }
            j++;
            if (j >= n){
                break;
            }
        } else {
            if (arr[j] > 0){
                arr[j]--;
                if(count[j] == 0){
                    count[j]++;
                }
            }
            j--;
            if (j < 0){
                break;
            }
        }
        
    }
    

    for (int i=0; i < n; i++){
        soma += arr[i];
        contador += count[i];
    }

    printf("%d %lld\n", contador,soma);
    

    return 0;
}