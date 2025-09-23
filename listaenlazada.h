#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
}; // Alias para la estructura

void iterar(struct Node* head);

/// @brief 
/// @param direccionCabeza 
/// @param data 
void insertar_cabeza(struct Node** direccionCabeza, int data);
void insertar_al_final(struct Node** ptrhead, int data);
void insertar_medio(struct Node **ptrhead, int data);
void eliminar_head(struct Node **ptrhead);