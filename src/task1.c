#include "task1.h"

// void addAtBeginning(Node** head, double v) {
//     Node *newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL)
//         exit(-1);
// 	newNode->valoare = v;
// 	newNode->next = *head;
// 	*head = newNode;
// }
void addAtEnd(Node** head, double v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
        exit(-1); 
    newNode->valoare = v;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *aux = *head;
        while (aux->next != NULL) 
            aux = aux->next;
        aux->next = newNode;
    }
}

void free_list(Node* head) {
    Node* aux = head;
    while (head != NULL) {
        head = head->next;
        free(aux);
        aux = head;
    }

}