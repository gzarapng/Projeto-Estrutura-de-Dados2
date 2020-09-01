#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trab.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcaosort, opcaoNvet;
    printf("Organização de vetores usando sorts - DEFININDO A COMPLEXIDADE\n\n\n"
            "Escolha o sort que deseja usar para organizar seu vetor:\n"
            "1- Merge Sort\n"
            "2- Bead Sort\n"
            "3- Counting Sort\n"
            "4- Quick Sort\n"
            "5- Insertion Sort\n"
            "6- Tim Sort\n"
            "7- Selection Sort\n"
            "8 -Bubble Sort\n"
            "9- Radix Sort\n"
            "10- Heap Sort\n"
            "11- \n"
            "Sua opção: ");
    switch (opcaosort)
    {
    case 1:
        void mergeSort(int arr[], int l, int r);
        break;
    case 2:
        void bead_sort(int *a, int len);
        break;
    case 3:
        void counting_sort(int a[],int n,int max);
        break;
    case 4:
        void quick_sort(int vetor[], int ini, int fim);
        break;
    case 5:
        void insertionSort(int a[], int beg, int end); 

        break;
    case 6:
        void timSort(int a[], int n);
        break;
    case 7:
        void Ordena_selectionSort(int *v, int n);
        break;
    case 8:
        void Ordena_bubbleSort(int *v, int n);
        break;
    case 9:
        void radixsort(int vetor[], int tamanho);
        break;
    case 10:
        void HeapSort(int *V, int n);
        break;
    case 11:
        void shellSort(int *vet, int size);
        break;
    
    default:
        break;
    }
}





