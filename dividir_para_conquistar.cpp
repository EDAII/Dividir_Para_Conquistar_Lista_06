#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Funções para o Merge Sort
void junta(int vet[], int inicio, int meio, int fim, int vet_aux[]);
void merge_sort(int vet[], int inicio, int fim, int vet_aux[]);
void merge_sort(int vet[], int tamanho);

//Funções para o Quick Sort
void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(){

  int opcao = 0;
  cout << "Escolha o algoritmo:" << endl;
  cout << "1 - Merge Sort" << endl;
  cout << "2 - Quick Sort" << endl;
  cout << "Caso queira finalizar o programa pressione \"0\" ." << endl;

  cin >> opcao;
  if(opcao == 1){
    //Merge Sort
    printf("Digite o tamanho do array: \n");

    int tamanho;
    int array[tamanho];

    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++){
      int valor = rand() % 100 + 1;
      array[i] = valor;
    }

    merge_sort(array, tamanho);

    printf("Vetor ordenado pelo metodo Merge Sorte:\n\n");

    for(int k = 0; k < tamanho; k++){
      if (k < tamanho -1)
      printf("%d ", array[k]);
      else
      printf("%d.", array[k]);
    }

    printf("\n");

  }else if(opcao == 2){
    //Quick Sort
    printf("Digite o tamanho do array: \n");
    int tamanho;
    scanf("%d",&tamanho);
    int A[tamanho];
    int i,j,k;
    for(i=0; i < tamanho; i++){
      int valor = rand() % 100 + 1;
      A[i] = valor;
    }

    quick_sort(A, 0, tamanho);

    for(k=0; k<tamanho; k++){
      printf("%d ",A[k]);
    }
    printf("\n");
  }else{

  }

  return 0;
}

void junta(int vet[], int inicio, int meio, int fim, int vet_aux[]) {
  int esq = inicio;
  int dir = meio;

  for (int i = inicio; i < fim; ++i) {
    if ((esq < meio) && ((dir >= fim) || (vet[esq] < vet[dir]))) {
      vet_aux[i] = vet[esq];
      ++esq;
    }
    else {
      vet_aux[i] = vet[dir];
      ++dir;
    }
  }

  for (int i = inicio; i < fim; ++i)
  vet[i] = vet_aux[i];

}

void merge_sort(int vet[], int inicio, int fim, int vet_aux[]) {
  if ((fim - inicio) < 2) return;

  int meio = ((inicio + fim)/2);

  merge_sort(vet, inicio, meio, vet_aux);
  merge_sort(vet, meio, fim, vet_aux);
  junta(vet, inicio, meio, fim, vet_aux);
}

void merge_sort(int vet[], int tamanho) {
  int vet_aux[tamanho]; //vetor auxiliar
  merge_sort(vet, 0, tamanho, vet_aux);
}

int partition(int array[], int start, int end){

  int pivo = array[end]; //Último elemento usado como pivo
  int i = start-1;

  for(int j = start; j < end; j++){
    if(array[j] <= pivo){
      i++;
      int aux = array[i];
      array[i] = array[j];
      array[j] = aux;
    }
  }

  int aux2 = array[i + 1];
  array[i + 1] = array[end];
  array[end] = aux2;

  return (i + 1);
}

void quick_sort(int array[], int start, int end){
  if(start < end){
    int index_atual = partition(array, start, end);
    quick_sort(array, start, index_atual - 1);
    quick_sort(array, index_atual + 1, end);
  }
}
