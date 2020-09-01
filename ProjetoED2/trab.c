
#include<stdlib.h>
#include<stdio.h>

//FUNÇÃO QUE VAI FAZER O SUBMENU QUE PEDE PRA ESCOLHER O NUMERO DE ELEMENTOS NO VETOR
int submenu(){
    int opcao;
    printf("Organização de vetores usando sorts - DEFININDO A COMPLEXIDADE\n\n\n"
            "Escolha o número de elementos que deseja dentro do seu vetor:\n"
            "1- 1.000\n"
            "2- 5.000\n"
            "3- 10.000\n"
            "4- 20.000\n"
            "5- 50.000\n"
            "6- 100.000\n"
            "Sua opção: ");
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
    default: printf("\n            que?                  \n");
        break;
    }
}



// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

/* funções de utilidade */
/* Função de Mostrar um Array */
void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
//int main()
/*{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Array desordenado\n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nArray ordenado\n");
	printArray(arr, arr_size);
	return 0;
}*/



/*
Integrantes do grupo: Diego, Beatriz, Elo�sa, Gabriel Zara.
*/


void bead_sort(int *a, int len)
{
    //SUM = SOMA DA COLUNA
	int i, j, max, sum;
	unsigned char *beads;
//S�O COMO PONTOS DE CORDENADA EM UM PLANO CARTESIANO
#	define BEAD(i, j) beads[i * max + j] //PRECISO ENTENDER ESSE 'beads[i * max + j]'

    //COLOCA O MAIOR VALOR DO VETOR DENTRO DA VARIAVEL MAX
	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];
    //ALOCA MEMORIA
	beads = calloc(1, max * len);

	/* mark the beads */
	//MARCA EM TODOS FEIJ�ES VERDADEIRO
	//USA O i COMO LINHA E O j COMO COLUNA
	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
            //AQUI ELE TA COLOCANDO QUE NESSA POSI��O TEMOS UM FEIJ�O, POR ISSO VERADEIRO
			BEAD(i, j) = 1;
    //AQUI ELE VAI POR COLUNA CONTANDO OS FEIJ�ES CONSIDERANDO QUE ESSE SORT CONTA AS COLUNAS DO ABACO PARA SABER O VALOR DOS NUMEROS
    //N�O AS LINHAS COMO FARIAMOS NO USO NORMAL DO ABACO
	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		//AQUI DEPOIS DE SOMAR FEIJ�O POR FEIJ�O DA COLUNA ELE ATRIBUI O FALSE PARA AQUELA POSI��O, JA QUE JA FOI UTILIZADA
		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		//AQUI ELE VAI SUBTRAIR A SOMA DO NUMERO DE COLUNAS E INICIA O FOR A PARTIR DISSO ASSIM ELE FAZ COM QUE OS FEIJ�ES ANDEM PARA A ESQUERDA AT� ENCONTRAR UM EMPECILHO, OU SEJA, OUTRO FEIJ�O
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}
    //VAI RODAR TORNANDO OS FEIJ�ES N�MEROS
	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
}

/*int main()
{
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20,15,60,89};
	//ESSE LEN VAI RECEBER A QUANTIDADE DE ITENS QUE TEMOS NO VETOR, PORQUE CADA ITEM VAI COMPOR UMA COLUNA DO ABACO
	int len = sizeof(x)/sizeof(x[0]);

	bead_sort(x, len);
	for (i = 0; i < len; i++)
		printf("%d\n", x[i]);

	return 0;


}*/




void counting_sort(int a[],int n,int max){
     int count[50]={0},i,j;

     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;

     printf("\nSorted elements are:");

     for(i=0;i<=max;++i)
      for(j=1;j<=count[i];++j)
       printf("%d ",i);
}

int main(){
    int a[50],n,i,max=0;
    printf("Insira o numero de elementos:");
    scanf("%d",&n);
    printf("\nInsira os elementos:");

    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(a[i]>max)
        max=a[i];
    }

    counting_sort(a,n,max);
    return 0;
}

/*Algoritmo Quicksort - ordena��o*/


//particiona e retorna o indice do pivo
int particiona(int vetor[], int ini, int fim) {
    int esq, dir, pivo, aux;

    esq = ini; //esquerda � o inicio
    dir = fim; //direita eh o final
    pivo = vetor[ini]; //pivo recebe o inicio do vetor

    while(esq < dir) {
        while(esq <= fim && vetor[esq] <= pivo) { //avanca posicao da esquerda at� achar um elemento que n seja menor que o pivo
            esq++;
        }
        while(dir >= 0 && vetor[dir] > pivo) { //recua posicao da direita enquanto os elementos forem menor que o pivo
            dir--;
        }
        //se a esquerda for maior que a direita faz a troca dps elementos
        if(esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[ini] = vetor[dir]; //inicio recebe o ultimo valor da direita
    vetor[dir] = pivo; //posicao da direita se torna o pivo
    return dir;


}

// funcao do quick sort
void quick_sort(int vetor[], int ini, int fim){

    int pivo;

    //utiliza recursividade para ordenar as particoes
    if(ini < fim) {
        pivo = particiona(vetor, ini, fim); //chama a funcao que separa os dados em 2 particoes
        quick_sort(vetor, ini, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }

}
/*
int main(){
    // vetor desordenado
    int vetor[] = {8, 3, 1, 43, 12, 5, 4, 7, 10, 22};

    int tam_vetor = sizeof(vetor) / sizeof(int);

    //Mostra vetor desordenado
    printf("Vetor desordenado \n");
    for(int i = 0; i < tam_vetor; i++){
        printf("%d ", vetor[i]);
    }

    //chamada da fun��o de ordena��o usando quick sort
    quick_sort(vetor, 0, 9);

    //apresenta vetor ordenado
    printf("\n\nVetor ordenado\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}*/


const int run = 32;  
   
    int minimum(int a, int b)  
    {  
        if(a<b)  
        return a;   
        else   
        return b;   
}  

    void insertionSort(int a[], int beg, int end)  
    {  
        int temp, i, j;   
        for (i = beg + 1; i <= end; i++)  
        {  
            temp = a[i];  
            j = i - 1;  
            while (a[j] > temp && j >= beg)  
            {  
                a[j+1] = a[j];  
                j--;  
            }  
            a[j+1] = temp;  
        }  
    }  
   
    void merge(int a[], int left, int mid, int right)  
    {  
        int len1 = mid - left + 1, len2 = right - mid;  
        int beg[len1], end[len2];  
        int i,j,k;  
        for (i = 0; i < len1; i++)  
            beg[i] = a[left + i];  
        for (i = 0; i < len2; i++)  
            end[i] = a[mid + 1 + i];  
       
        i = 0;  
        j = 0;  
        k = left;  
       
        while (i < len1 && j < len2)  
        {  
            if (beg[i] <= end[j])  
            {  
                a[k] = beg[i];  
                i++;  
            }  
            else  
            {  
                a[k] = end[j];  
                j++;  
            }  
            k++;  
        }  
        while (i < len1)  
        {  
            a[k] = beg[i];  
            k++;  
            i++;  
        }  
       
        while (j < len2)  
        {  
            a[k] = end[j];  
            k++;  
            j++;  
        }  
    }  

    void timSort(int a[], int n)  
    {  
                int i,size,beg,mid,end;  
                for (i = 0; i < n; i+=run)  
                    insertionSort(a, i, minimum((i+31), (n-1)));  
                for (size = run; size < n; size = 2*size)  
                {  
                    for (beg = 0; beg < n; beg += 2*size)  
                    {  
                        mid = beg + size - 1;  
                        end = minimum((beg + 2*size - 1), (n-1));  
               
                        merge(a, beg, mid, end);  
                    }  
                }  
    }  
  
    /*int main()  
            {  
                int a[] = {12,1,20,2,3,123,54,332},i;  
                int n = sizeof(a)/sizeof(a[0]);  
                printf("Elementos desorganizados \n");  
                for (i = 0; i < n; i++)  
                printf("%d  ", a[i]);  
                printf("\n");  
                timSort(a, n);  
               
                printf("Elementos Ordenados \n");  
                for (i = 0; i < n; i++)  
                    printf("%d  ", a[i]);  
                printf("\n");  
                return 0;  
            }  */

//---------------------------------------
//v = VETOR
//len = TAMANHO DO VETOR
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
/*******************************************/

/*int main(){
    setlocale(LC_ALL, "Portuguese");
    int vetor[20] = {12, 41, 2, 57, 100, 51, 60, 83, 39, 59, 50, 45, 49, 46, 24, 83, 30, 96, 32, 15};
    int i;

    printf("Vetor desordenado: ");
    for(i=0; i<=19; i++){
        printf("[%d] ", vetor[i]);
    }

    Ordena_insertionSort(vetor, 20);

    printf("\n\nVetor ordenado por InsertionSort: ");
    for(i=0; i<=19; i++){
        printf("[%d] ", vetor[i]);
    }

    printf("\n\n");

return 0;
}*/



//---------------------------------------
//v = VETOR
//len = TAMANHO DO VETOR
void insertionSort(int *v, int len){
    int i, j, aux;
    for(i = 1; i < len; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}
/*******************************************/

/*int main(){
    setlocale(LC_ALL, "Portuguese");
    int vetor[20] = {12, 41, 2, 57, 100, 51, 60, 83, 39, 59, 50, 45, 49, 46, 24, 83, 30, 96, 32, 15};
    int i;

    printf("Vetor desordenado: ");
    for(i=0; i<=19; i++){
        printf("[%d] ", vetor[i]);
    }

    Ordena_selectionSort(vetor, 20);

    printf("\n\nVetor ordenado por SelectionSort: ");
    for(i=0; i<=19; i++){
        printf("[%d] ", vetor[i]);
    }

    printf("\n\n");

return 0;
}*/


//---------------------------------------
//v = VETOR
//len = TAMANHO DO VETOR
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
/*******************************************/


//---------------------------------------
//v = VETOR
//len = TAMANHO DO VETOR
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
/*******************************************/

//---------------------------------------
//v = VETOR
//len = TAMANHO DO VETOR
void HeapSort(int *V, int n){
    int i, aux;

    for(i=(n-1)/2; i>=0; i--){
        CriandoHeap(V, i, n-1);
    }

    for(i=(n-1); i>0; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        CriandoHeap(V, 0, i-1);
    }
}
//func auxiliar Heap Sort
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
/*int main(){
    setlocale(LC_ALL, "Portuguese");
    int i, n=10, vetor[] = {9,8,7,6,5,4,3,2,1,0};
    for(i=0; i<n; i++){
        printf("%i, ",vetor[i]);
    }

    HeapSort(vetor, n);
    printf("\n\n\n");
    for(i=0; i<n; i++){
        printf("%i, ",vetor[i]);
    }
    return 0;
}

void HeapSort(int *V, int n){
    int i, aux;

    for(i=(n-1)/2; i>=0; i--){
        CriandoHeap(V, i, n-1);
    }

    for(i=(n-1); i>0; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        CriandoHeap(V, 0, i-1);
    }
}*/
/*******************************************/


void shellSort(int *vet, int size) {
    int i , j , value;
 
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet [j - h];
                j = j - h;
            }
            vet [j] = value;
        }
        h = h/3;
    }
}