#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //crear Vector.
  //int i, j, k;
  //int * vec = (int *) calloc (10, sizeof(int));
  
  int p;
  for (int k = 0; k < 9; k++) {
     for (p = 0; p < 9; p++) {
        int i = 3 * (k/3) + (p/3) ;
        int j = 3 * (k%3) + (p%3) ;
        printf("%d ",n->sudo[i][j]);
        if(p%3 == 2) //printf("\n");
      }
  }
  
  /*
  //Recorrer Filas y Columnas.
  for (i = 0; i <= 9; i++) {
    vec = (int *) calloc (10, sizeof(int));
    for (j = 0; j <= 9; j++) {
      printf("%d ", n->sudo[i][j]);
      if (n->sudo[i][j] != 0){
        k = n->sudo[i][j];
        //Revisar si está en el arreglo
        for (k = 0; k <= 9; k++) {
          //printf("%d", n->sudo[i][j]);
          if (vec[k-1] == 1) return 1;
          vec[k-1] = 1;
        }
      }
    }
  }*/
    return 1;
}


List* get_adj_nodes(Node* n){
    List * list = createList();
    int i, j, k;

    //Recorrer una matriz.
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (n->sudo[i][j] <= 0) {
          for(k = 1; k < 10; k++) { // Probar los valores.
            n->sudo[i][j] = k; //Asignar Valores.
            if(is_valid(n)) {
              Node * adj = copy(n);
              pushBack(list, adj);
            }
          }
        n->sudo[i][j] = 0;
        return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
  int i, j;
  for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (n->sudo[i][j] == 0) return 0;
      }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/