#include<stdlib.h>
#include<stdio.h>

void mergeSort(int arr[], int a,int esq, int dir);
void merge(int arr[], int esq, int meio, int dir);

int main(){

}

void merge(int arr[], int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int E[n1], D[n2];

    for (i = 0; i < n1; i++)
        E[i] = arr[esq + i];

    for (j = 0; j < n2; j++)
        D[j] = arr[meio+1 + j];

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2){
        if (E[i] <= D[j]){
            arr[k] = E[i];
            i++;
        }else{
            arr[k] = D[j];
            j++;
        }

        k++;
    }

    while (i < n1){
        arr[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int a[], int esq, int dir){
    if (esq < dir){
        int meio = esq + (dir - esq)/2;
        mergeSort(arr, a, esq, meio);
        mergeSort(arr, a, meio+1, dir);
        if(arr[meio] < arr[meio+1]) return;
        merge(arr, esq, meio, dir);
    }
}
