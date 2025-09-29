#include "pila.h"

/**
 * @brief Creamos una pila con *size* cero y un puntero *top* a NULL
 * @param ptrStack  Dirección de memoria del puntero a la pila a crear.
 */
void stack_ll_init(struct Stack_ll **ptrStack){
  struct Stack_ll (*ptrStack)=malloc(sizeof(struct Stack_ll));
  (*ptrStack)->size=0;
  (*ptrStack)->top=NULL;
}
/**
 * @brief Añadimos un elemento a la pila
 * @param ptrStack  Puntero a la pila
 * @param element  Elemento a añadir
 */
void stack_ll_push(struct Stack_ll *ptrStack, struct Node element){
  struct Node *new = malloc(sizeof(struct Node));
   *new= element;
  if(new==NULL){
    perror("Error al alocar memoria");
    return;
  }
  if(ptrStack->top==NULL){
    ptrStack->top=new;
    new->next=NULL;
  }else{
   new->next=ptrStack->top;
   ptrStack->top=new;
  }
  ptrStack->size++;
}
/**
 * @brief Devuelve el elemento en la cima de la pila
 * @param ptrStack  Puntero a la pila 
 * @return Puntero al elemento en la cima de la pila 
 */
struct Node stack_ll_top(struct Stack_ll * ptrStack){
  if(ptrStack->top==NULL||ptrStack==NULL){
    exit(1);
  }else{
    return *(ptrStack->top);

  }
}
/**
 * @brief Elimina el elemento en la cima de la pila
 * @param ptrStack Puntero a la pila.
 * @return true se puede eliminar, false en caso contrario
 */
bool stack_ll_pop(struct Stack_ll * ptrStack){
  if(ptrStack->top==NULL||ptrStack==NULL){
    return false;
  }
  struct Node *aux = ptrStack->top;
  ptrStack->top=ptrStack->top->next;
  free(aux);
  ptrStack->size--;
  return true;
}

/**
 * @brief Comprueba si la pila está vacía
 * @param ptrStack  Puntero a la pila
 * @return true si la pila está vacía, false en caso contrario
 */
bool stack_ll_isEmpty(struct Stack_ll * ptrStack){
  bool bombilla=true;
  if(ptrStack->size==0){
    bombilla=false;
  }
  return bombilla;
}
/**
 * @brief Devuelve el número de elementos en la pila
 * @param ptrStack  Puntero a la Pila
 * @return Número de elementos en la pila
 */
int stack_ll_size(struct Stack_ll * ptrStack){
  if(ptrStack==NULL){
    perror("Lista nula");
    exit(1);
  }else{
    return ptrStack->size;
  }
}
/**
 * @brief Elimina todos los elementos de la pila
 * @param ptrStack  Puntero a la Pila
 */
void stack_ll_clear(struct Stack_ll * ptrStack){
  if(ptrStack==NULL){
    return;
  }
  while(ptrStack->size!=0){
    stack_ll_pop(ptrStack);
  }
}

/**
 * @brief Muestra los elementos de la pila 
 * @param ptrStack Puntero a la pila a mostrar
 */
void stack_ll_show(struct Stack_ll * ptrStack){
  struct Node * current = ptrStack->top;
  for(int i = ptrStack->size; i > 0; i--){
    printf("Nodo { color: %d, capacidad: %f, material: mat}", current->color, current->capacidad);
    current = current->next;
  }
}