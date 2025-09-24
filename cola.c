#include "cola.h"

struct Person * createPerson(char *name, int age){
  struct Person *Persona = malloc(sizeof(struct Person));
  if(Persona!=NULL){

     Persona -> age = age;
  strcpy(Persona -> name, name);
  
  }
 
}

void createQueue(struct Node **ptrqueue){

  *ptrqueue = NULL;
  }

/**
 * @brief Comprueba si la cola está vacía
 * @param queue Puntero a la cola
 * @return true si la cola está vacía, false en caso contrario
 */
bool isEmpty(struct Node * queue){
  bool bombilla = false;
  if(queue == NULL){
    bombilla = true;
  }
  return bombilla;
}
/**
 * @brief Comprueba el tamaño de la cola
 * @param queue Puntero a la cola
 * @return
 */
int size(struct Node * queue){
  int contador=0;
  struct Node *temp=queue;
  while ( queue->next!=temp){
    contador++;
    queue = queue -> next;
  }
  return contador;
}
/* void enqueue(struct Node **ptrqueue, struct Person * person){
    struct Node *nuevo = malloc(sizeof(struct Node));
    if(nuevo == NULL){
        printf("Error al alocar memoria");
        return;
    }
    nuevo->person = person;
    nuevo->next = NULL;
    
    if(*ptrqueue == NULL){  // Caso cola vacía
        *ptrqueue = nuevo;
    } else {
        struct Node *actual = *ptrqueue;
        while(actual->next != NULL){  // Usar variable temporal
            actual = actual->next;
        }
        actual->next = nuevo;
    }
}*/

  /**
 * @brief Añade un elemento al final de la cola
 * @param queue Puntero a la cola
 * @param person Puntero a persona a añadir
 */
void enqueue(struct Node **ptrqueue, struct Person * person){
  struct Node *nuevo=malloc(sizeof(struct Node));
  if(nuevo==NULL){
    printf("Error al alocar memoria");
    exit(-1);
  }
  nuevo->person=person;

  if(*ptrqueue==NULL){
    *ptrqueue=nuevo;
    (*ptrqueue)->next=ptrqueue;
  }else{
     
     nuevo->next= (*ptrqueue)->next;
    (*ptrqueue)->next=nuevo;
    *ptrqueue=nuevo;

  }


}
    
/**
 * @brief Elimina el primer elemento de la cola
 * @param queue Puntero a la cola
 */
/* void dequeue(struct Node **ptrqueue){
  if((*ptrqueue) -> next == NULL){
    free(*ptrqueue);
    *ptrqueue=NULL;
  }else if(*ptrqueue!=NULL){
    struct Node *aux = *ptrqueue;
    *ptrqueue = (*ptrqueue) -> next;
    free(aux);
    aux = NULL;
  }
}
  */
/**
 * @brief Elimina el primer elemento de la cola
 * @param queue Puntero a la cola
 */
 void dequeue(struct Node **ptrqueue){
  if(*ptrqueue==NULL){
    printf("La lista esta vacia");
    exit(-1);
  }
  else if((*ptrqueue)->next ==*ptrqueue){
    free(*ptrqueue);
    *ptrqueue=NULL;
  }else{
    struct Node *temp= (*ptrqueue)->next;
    (*ptrqueue)->next = temp->next;
    free(temp);
  }
 }
  
/**
 * @brief Limpia la cola
 * @param queue Puntero a la cola
 */
void clear(struct Node **ptrqueue){
  while(*ptrqueue!=NULL){
    dequeue(ptrqueue);
  }

}
/**
 * @brief Muestra los elementos de la cola
 * @param queue Puntero a la cola
 */
void display(struct Node * queue){
  if(queue==NULL){
    printf("COLA VACIA");
    return;
  }
  struct Node *temp=queue;
  
  while(queue!=NULL){
    printf("%s de edad %d",queue->person->name,queue->person->age);
    queue=queue->next;
  }
}