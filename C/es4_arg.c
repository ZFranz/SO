#include <stdio.h>
#include <string.h>

#define SIZE 100

void stampa(int *, int);
void swap(int *, int *);
void reverse(int *, int);

int main(int argc, char **argv) {
	int a[SIZE] = {};
	int count = 0, n = 0, dim = 0;
	int scelta = 0;
	
	if (argc >= 2) {
		if (strcmp(argv[1], "-r") == 0) {
			scelta = 0;
		} else if (strcmp(argv[1], "-s") == 0) {
			scelta = 1;
		} else if (strcmp(argv[1], "-S") == 0) {
			scelta = 2;
		} else {
			printf("Scelta non valida.\n");
			return 0;
		}
	} else {
		printf("Non e' stata effettuata nessuna scelta.\n");
		return 0;
	}
	
	printf("Inserisci una dimensione: ");
	scanf("%d", &dim);
	
	while(count < SIZE && scanf("%d", &n) == 1) {
    	a[count] = n;
    	count++;
    	if (count >= dim) {
    		break;
		}
	}
	
	printf("\n\nArray inserito.\n");
	stampa(&a, count);
	printf("\n");
	switch (scelta) {
		case 0:
			reverse(&a, count);
			printf("\nArray invertito.\n");
			stampa(&a, count);
			break;
		
		case 1:
			quickSort(&a, 0, count-1);
			printf("\nArray in ordine crescente.\n");
			stampa(&a, count);
			break;
			
		case 2:
			quickSort(&a, 0, count-1);
			reverse(&a, count);
			printf("\nArray inordine decrescente.\n");
			stampa(&a, count);
			break;
	}
	
	return 0;
}

void stampa(int *a, int size) {
	for (int i = 0; i < size; ++i) {
		printf("Elemento [%d] = %d\n", i, a[i]);
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(int *begin, int size) {
	for(int i = 0; i < size / 2; ++i) {
		swap(begin + i, begin + size - i - 1);
	}
}

int partition (int arr[], int low, int high) { 
	int pivot = arr[high]; // pivot 
	int i = (low - 1);
	
	for (int j = low; j <= high-1; j++) { 
		if (arr[j] <= pivot) { 
			i++;
    		swap(&arr[i], &arr[j]); 
		} 
	} 
  	swap(&arr[i + 1], &arr[high]); 
  	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
    	quickSort(arr, low, pi - 1); 
    	quickSort(arr, pi + 1, high); 
	} 
}
