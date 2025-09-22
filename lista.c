#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
}; // Alias para la estructura

void cambiar(struct Node *cabeza){
  while(cabeza!=NULL){
    cabeza -> data= 2;
    cabeza = cabeza->next;
  }

}
void iterar (struct Node *cabeza) {
  while (cabeza != NULL) {
    printf("%d ",cabeza->data);
    cabeza = cabeza->next;
  }}
  int numerodenodos(struct Node *head){
    int contador=0;
    while(head!=NULL){
      contador++;
      head = head -> next;
    }
    return contador;
  }

  void insertarcola(struct Node *head, int num){
    while(head->next !=NULL){
      head = head -> next;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    if (head == NULL)
    {
      printf("Error al alocar memoria");
      return;
    }

    newNode->data = num;
    newNode->next = NULL;

    head->next = newNode;
  }
  void insertar(struct Node **ptrhead, int num) {
    struct Node* newhead = malloc(sizeof(struct Node));
    if (newhead == NULL) {
        printf("Error al alocar memoria\n");
        return;
    }
    newhead->data = num;
    newhead->next = *ptrhead; // enlazar con la antigua cabeza
    *ptrhead = newhead;       // actualizar cabeza
}
 void insertarEnMedio(struct Node *ptrhead, int pos, int num){
  struct Node* newhead = malloc(sizeof(struct Node));
  newhead -> data=num;
  int posiciones = numerodenodos(ptrhead);
  if (pos < 0 || pos > posiciones ){
      printf("Error en la posicion");
      return;
 }
 for(int i=0;i<pos-1;i++){
  ptrhead = ptrhead -> next;
 }
 newhead -> next = ptrhead -> next;
 ptrhead -> next = newhead;


  }
void eliminarcabeza(struct Node **ptrhead){
  if(ptrhead==NULL){
    printf("Error");
    return;
  }
  struct Node *temp = *ptrhead;
  *ptrhead = (*ptrhead) -> next;
  free(temp);
}
void eliminarcola(struct Node *ptrhead){
  while(ptrhead -> next!=NULL){
    ptrhead = ptrhead -> next;
  }
  ptrhead ->next = NULL;
///TERMINA CARAJO
}
 
int main(void){
  struct Node* head;
  
 head= malloc(sizeof(struct Node));

 head -> data=3;
 head -> next=malloc(sizeof(struct Node));
 head -> next -> data= 7;
 head -> next -> next = malloc(sizeof(struct Node));
 head -> next -> next -> data = 9;
 head -> next -> next -> next = NULL;


 // insertarcola(head,5);
 //insertar(&head,9);
 //iterar(head);
 //insertarEnMedio(head,2,8);
 eliminarcabeza(&head);
 eliminarcola(head);
iterar(head);
    
    return 0;
}