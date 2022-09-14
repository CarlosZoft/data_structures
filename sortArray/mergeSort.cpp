void merge(int *arr, int start, int half, int end) {

    int * auxArray = new int[end - start + 1];

    int i = start, 
    j = half + 1, 
    cont = 0; 

    while(i <= half && j <= end)
      (arr[i] < arr[j]) ? 
        auxArray[cont++] = arr[i++] : 
        auxArray[cont++] = arr[j++];
    
    while(i <= half)
        auxArray[cont++] = arr[i++];
    
    while(j <= end) 
        auxArray[cont++] = arr[j++];
    
    for(int i = start ; i <= end; ++i)
        arr[i] = auxArray[i-start];
    
    free(auxArray);
}
void mergeSort(int *arr, int start, int end){
    if (start < end) {
        int half = (end+start)/2;
        mergeSort(arr, start, half);
        mergeSort(arr, half+1, end);
        merge(arr, start, half, end);
    }
}