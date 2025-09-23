#include "listaEnlazada.h"

void iterar(struct Node* head){
  //Imprime por pantalla la información de cada nodo: su data, la posición de memoria de data y el next.
  while(head != NULL) {
    printf("%d\n", head->data);
    //iterar(head->next); marranada historica y super poco eficiente
    head = head->next;  
  }

}

void insertar_cabeza(struct Node** direccionCabeza, int data) {
    struct Node* aux=malloc(sizeof(struct Node));
    if (aux==NULL)exit(1);
    aux->data=data;
    aux->next= *direccionCabeza;
    *direccionCabeza=aux;
}

void insertar_al_final(struct Node** ptrhead, int data){
  if (*ptrhead == NULL){
    insertar_cabeza(ptrhead,data);
  }else{
    struct Node *nuevoBloque = malloc(sizeof(struct Node));
    nuevoBloque->data = data;
    nuevoBloque->next = NULL;

    struct Node *phead = *ptrhead;
    while(phead->next != NULL){
      phead = phead->next;
    }
    phead->next = nuevoBloque;
  }
}

void insertar_medio(struct Node **ptrhead, int data){
  //Creamos el nuevo bloque y le damos el valor
  struct Node *nuevoBloque;
  nuevoBloque = malloc(sizeof(struct Node));
  nuevoBloque->data = data;
  nuevoBloque->next = NULL; //Esto no es necesario pero es para saber que no apunta a nada

  //Creamos una copia del puntero (ptrhead) y creamos uno nuevo que vaya por detrás suya (por eso el = NULL)
  struct Node *phead = *ptrhead;
  struct Node *ant = NULL;
  while(data > phead->data ){ //En este caso, el órden es de menor a mayor
    ant = phead;
    phead = phead->next;
  }
  if(ant == NULL){
    insertar_cabeza(ptrhead, data);
  }else if(phead == NULL){
    insertar_al_final(ptrhead, data);
  }else{
    ant->next = nuevoBloque;
    nuevoBloque->next = phead;
  }
}

void eliminarHead(struct Node **ptrHead){
  if(*ptrHead == NULL){
    printf("No hay nodos que eliminar");
    exit(-1);
  }else{
    struct Node *aux = *ptrHead;
    *ptrHead = aux->next;
    free(aux);
    aux = NULL;
  }
}