#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trab.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcaosort, len, *v;
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
            "11- Shell Sort\n"
            "Sua opção: ");
    switch (opcaosort)
    {
    case 1:
        //len = tamanho do vetor em todos os casos, agora antes de chamar o sort só falta a func q cria o vetor dale
        len = submenu();
        mergeSort(int arr[], int l, int r);
        break;
    case 2:
        len = submenu();
        bead_sort(*v, len);
        break;
    case 3:
        len = submenu();
        counting_sort(int a[],int n,int max);
        break;
    case 4:
        len = submenu();
        quick_sort(int vetor[], int ini, int fim);
        break;
    case 5:
        len = submenu();
        insertionSort(*v, 0, len); 
        break;
    case 6:
        len = submenu();
        timSort(int a[], int n);
        break;
    case 7:
        len = submenu();
        *v = /*func da elo*/;
        selectionSort(*v, len);
        break;
    case 8:
        len = submenu();
        *v = /*func da elo*/;
        bubbleSort(*v, len);
        break;
    case 9:
        len = submenu();
        *v = /*func da elo*/;
        radixsort(*v, len);
        break;
    case 10:
        len = submenu();
        *v = /*func da elo*/;
        HeapSort(*v, len);
        break;
    case 11:
        len = submenu();
        *v = /*func da elo*/;
        shellSort(*v, len);
        break;
    
    default:
        break;
    }
}





