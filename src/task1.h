#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct Lista
{
    double valoare;
    double randam;
    struct Lista *next;
};
typedef struct Lista Node;
void print(Node *head);
void addAtEnd(Node** head, double v);
void addAtBeginning(Node** head, double v);
void print(Node *head);
void free_list(Node* head);
