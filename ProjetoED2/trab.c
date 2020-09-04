#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "trab.h"

int submenu(){
    int opcao;
    printf("Escolha o n�mero de elementos que deseja dentro do seu vetor:\n"
            "1- 1.000\n"
            "2- 5.000\n"
            "3- 10.000\n"
            "4- 20.000\n"
            "5- 50.000\n"
            "6- 100.000\n"
            "7- 10\n"
            "Sua op��o: ");
            scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        return 1000;
        break;
    case 2:
        return 5000;
        break;
    case 3:
        return 10000;
        break;
    case 4:
        return 20000;
        break;
    case 5:
        return 50000;
        break;
    case 6:
        return 100000;
        break;
    case 7:
        return 10;
        break;
    default: printf("\n            que?                  \n");
        break;
    }
}

void exibirOrdenado(int *vet, int len){
    int i;
    for(i = 0; i < len; i++){
        printf("%d\n", vet[i]);
    }
}


void printArray(int *v, int len)
{
	int i;
	for (i=0; i < len; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void merge(int *v, int l, int m, int len)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = len - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */

	for (i = 0; i < n1; i++)
		L[i] = v[l + i];
	for (j = 0; j < n2; j++)
		R[j] = v[m + 1+ j];

	i = 0;
	j = 0;
	k = l;


	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{

			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		v[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		v[k] = R[j];
		j++;
		k++;
	}
	
}


void mergeSort(int *v, int l, int len){

	if (l < len)
	{

		int m = l+(len-l)/2;


		mergeSort(v, l, m);
		mergeSort(v, m+1, len);

		merge(v, l, m, len);
	}
	

}



void bead_sort(int *a, int len){

	int i, j, max, sum;
	unsigned char *beads;

#	define BEAD(i, j) beads[i * max + j]

	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];

	beads = calloc(1, max * len);

	/* mark the beads */

	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;

	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */

		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */

		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}
	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
}



void countingSort(int *v, int len){
     int count[50] = {0}, i, j, max;
     max = v[0];
     for (i = 1; i < len; i++){
		if (v[i] > max) max = v[i];
     }
    for(i=0; i<len; ++i){
        count[v[i]]=count[v[i]]+1;
     }

    printf("Com Counting Sort\n");
    for(i=0;i<=max;++i){
        for(j=1;j<=count[i];++j){
       printf("%d \n",i);
       }
    }
}




int particiona(int *v, int ini, int len) {
    int esq, dir, pivo, aux;

    esq = ini;
    dir = len;
    pivo = v[ini];

    while(esq < dir) {
        while(esq <= len && v[esq] <= pivo) {
            esq++;
        }
        while(dir >= 0 && v[dir] > pivo) {
            dir--;
        }

        if(esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;


}


void quick_sort(int *v, int ini, int len){

    int pivo;


    if(ini < len) {
        pivo = particiona(v, ini, len);
        quick_sort(v, ini, pivo - 1);
        quick_sort(v, pivo + 1, len);
    }

}



const int run = 32;

    int minimum(int a, int b)
    {
        if(a<b)
        return a;
        else
        return b;
}

    void insertionSort(int *v, int beg, int len)
    {
        int temp, i, j;
        for (i = beg + 1; i <= len; i++)
        {
            temp = v[i];
            j = i - 1;
            while (v[j] > temp && j >= beg)
            {
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = temp;
        }
    }

    void tim (int *v, int left, int mid, int right)
    {
        int len1 = mid - left + 1, len2 = right - mid;
        int beg[len1], end[len2];
        int i,j,k;
        for (i = 0; i < len1; i++)
            beg[i] = v[left + i];
        for (i = 0; i < len2; i++)
            end[i] = v[mid + 1 + i];

        i = 0;
        j = 0;
        k = left;

        while (i < len1 && j < len2)
        {
            if (beg[i] <= end[j])
            {
                v[k] = beg[i];
                i++;
            }
            else
            {
                v[k] = end[j];
                j++;
            }
            k++;
        }
        while (i < len1)
        {
            v[k] = beg[i];
            k++;
            i++;
        }

        while (j < len2)
        {
            v[k] = end[j];
            k++;
            j++;
        }
    }

    void timSort(int *v, int len)
    {
                int i,size,beg,mid,end;
                for (i = 0; i < len; i+=run)
                    insertionSort(v, i, minimum((i+31), (len-1)));
                for (size = run; size < len; size = 2*size)
                {
                    for (beg = 0; beg < len; beg += 2*size)
                    {
                        mid = beg + size - 1;
                        end = minimum((beg + 2*size - 1), (len-1));

                        tim (v, beg, mid, end);
                    }
                }
    }


void bubbleSort(int *v, int len){
    int i, continua, aux;
    do{
        continua = 0;
        for(i=0; i<len; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        len--;
    }while(continua != 0);
}


void insertion_Sort(int *v, int beg, int len){
    int i, j, aux;
    for(i = 1; i < len; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}

void selectionSort(int *v, int len){
    int i, j, menor, troca;
    for(i = 0; i < len - 1; i++){
        menor = i;
        for(j = i + 1; j < len; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

void radixsort(int *v, int len) {
    int i;
    int *b;
    int maior = v[0];
    int exp = 1;

    b = (int *)calloc(len, sizeof(int));

    for (i = 0; i < len; i++) {
        if (v[i] > maior)
    	    maior = v[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < len; i++)
    	    bucket[(v[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = len - 1; i >= 0; i--)
    	    b[--bucket[(v[i] / exp) % 10]] = v[i];
    	for (i = 0; i < len; i++)
    	    v[i] = b[i];
    	exp *= 10;
    }
    free(b);
}

void HeapSort(int *V, int len){
    int i, aux;

    for(i=(len-1)/2; i>=0; i--){
        CriandoHeap(V, i, len-1);
    }

    for(i=(len-1); i>0; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        CriandoHeap(V, 0, i-1);
    }
}

void CriandoHeap(int *V, int ini, int fim){
    int filho = 2*ini + 1, aux = V[ini], i;

    while(filho <= fim){

        if(filho < fim){
            if(V[filho] < V[filho + 1]){
                filho += 1;
            }
        }

        if(V[filho] > aux){
            V[ini] = V[filho];
            ini = filho;
            filho = ini*2 + 1;
        }else{
            filho = fim + 1;
        }

    }

    V[ini] = aux;
}


void shellSort(int *v, int len)
{
 int i , j , value;
 int gap = 1;

 do {
  gap = 3*gap+1;
 } while(gap < len);

 do {
  gap /= 3;
  for(i = gap; i < len; i++) {
   value = v[i];
   j = i - gap;

   while (j >= 0 && value < v[j]) {
    v[j + gap] = v[j];
    j -= gap;
   }
   v[j + gap] = value;
  }
 }while(gap > 1);
}

