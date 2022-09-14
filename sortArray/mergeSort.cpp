void merge(int *vetor, int start, int half, int end) {

    int * auxArray = new int[end - start + 1];

    int i = start, 
    j = half + 1, 
    cont = 0; 

    while(i <= half && j <= end)
      (vetor[i] < vetor[j]) ? 
        auxArray[cont++] = vetor[i++] : 
        auxArray[cont++] = vetor[j++];
    
    while(i <= half)
        auxArray[cont++] = vetor[i++];
    
    while(j <= end) 
        auxArray[cont++] = vetor[j++];
    
    for(int i = start ; i <= end; ++i)
        vetor[i] = auxArray[i-start];
    
    free(auxArray);
}
void mergeSort(int *vetor, int start, int end){
    if (start < end) {
        int half = (end+start)/2;
        mergeSort(vetor, start, half);
        mergeSort(vetor, half+1, end);
        merge(vetor, start, half, end);
    }
}