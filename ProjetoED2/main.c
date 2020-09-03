#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<time.h>
#include "trab.h"

int *setArrayElements(int length);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcaosort, len;
		int *arrayToSort;
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
			"Sua opção: "
		);

		scanf("%d", &opcaosort);


    switch (opcaosort)
        {
        case 1:
            //len = tamanho do vetor em todos os casos, agora antes de chamar o sort só falta a func q cria o vetor dale
            len = submenu();
						arrayToSort = setArrayElements(len);

            mergeSort(int arr[], int l, int r);
            break;
        case 2:
            len = submenu();
						arrayToSort = setArrayElements(len);
            bead_sort(arrayToSort, len);
            break;
        case 3:
            len = submenu();
						arrayToSort = setArrayElements(len);
            counting_sort(int a[],int n,int max);
            break;
        case 4:
            len = submenu();
						arrayToSort = setArrayElements(len);
            quick_sort(int vetor[], int ini, int fim);
            break;
        case 5:
            len = submenu();
						arrayToSort = setArrayElements(len);
            insertionSort(arrayToSort, len); 
            break;
        case 6:
            len = submenu();
						arrayToSort = setArrayElements(len);
            timSort(int a[], int n);
            break;
        case 7:
            len = submenu();
						arrayToSort = setArrayElements(len);

            selectionSort(arrayToSort, len);
            break;
        case 8:
            len = submenu();
						arrayToSort = setArrayElements(len);

            bubbleSort(arrayToSort, len);
            break;
        case 9:
            len = submenu();
						arrayToSort = setArrayElements(len);

            radixsort(arrayToSort, len);
            break;
        case 10:
            len = submenu();
						arrayToSort = setArrayElements(len);

            HeapSort(arrayToSort, len);
            break;
        case 11:
            len = submenu();
						arrayToSort = setArrayElements(len);

            shellSort(arrayToSort, len);
            break;
        
        default:
            break;
        }
}

int *setArrayElements(int length) {
	int *numbersArray = malloc(length);
	
	if (!numbersArray) return NULL;
	
	srand(time(0)); 

	for (int i = 0; i < length; i++) {
		numbersArray[i] = rand() % 10 + 1;
		printf("%d\n", numbersArray[i]);
	}
    
    return numbersArray; //retorna endereço do array
}